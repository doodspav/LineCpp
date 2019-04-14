#ifndef THRIFT_COMPACT_PROTOCOL_H
#define THRIFT_COMPACT_PROTOCOL_H

#include <cstring>
#include <stack>
#include <cstdint>
#include <string>

#include "TCompactType.h"
#include "TMessageType.h"

class TCompactProtocol
{
private:
	TCompactProtocol();

	// protocol constants
	static constexpr uint8_t PROTOCOL_ID = static_cast<uint8_t>(0x82u);
	static constexpr uint8_t VERSION_N = 1;
	static constexpr uint8_t VERSION_MASK = static_cast<uint8_t>(0x1fu);  // 0001 1111
	static constexpr uint8_t TYPE_MASK = static_cast<uint8_t>(0xE0u);     // 1110 0000
	static constexpr uint8_t TYPE_BITS = static_cast<uint8_t>(0x07u);     // 0000 0111
	static constexpr uint8_t TYPE_SHIFT_AMOUNT = 5;

	// conversion functions
	static uint32_t i32ToZigzag(const uint32_t i32) { return (i32 << 1) ^ (i32 >> 31); }
	static uint64_t i64ToZigzag(const uint64_t i64) { return (i64 << 1) ^ (i64 >> 63); }
	static uint32_t zigzagToI32(const uint32_t zz32) { return (zz32 >> 1) ^ (-(zz32 & 1)); }
	static uint64_t zigzagToI64(const uint64_t zz64) { return (zz64 >> 1) ^ (-(zz64 & 1)); }

	// inline write functions
	static void writeVarint32(std::string& buffer, uint32_t i32)
	{
		uint8_t buf[5];
		uint_fast8_t wsize = 0;
		while ((i32 & ~0x7fu) != 0)
		{
			buf[wsize++] = static_cast<uint8_t>((i32 & 0x7fu) | 0x80u);
			i32 >>= 7;
		}
		buf[wsize++] = static_cast<uint8_t>(i32);
		buffer.append(reinterpret_cast<char*>(buf), wsize);
	}
	static void writeVarint64(std::string& buffer, uint64_t i64)
	{
		uint8_t buf[10];
		uint_fast8_t wsize = 0;
		while ((i64 & ~0x7fu) != 0)
		{
			buf[wsize++] = static_cast<uint8_t>((i64 & 0x7fu) | 0x80u);
			i64 >>= 7;
		}
		buf[wsize++] = static_cast<uint8_t>(i64);
		buffer.append(reinterpret_cast<char*>(buf), wsize);
	}

	// inline read functions
	static void readVarint32(char const*& buffer, uint32_t& i32)
	{
		uint64_t i64;
		TCompactProtocol::readVarint64(buffer, i64);
		i32 = static_cast<uint32_t>(i64);
	}
	static void readVarint64(char const*& buffer, uint64_t& i64)
	{
		uint64_t temp_i64 = 0;
		uint_fast8_t shift = 0;
		uint8_t byte;

		for (uint_fast8_t i = 0; i < 10; ++i)
		{
			TCompactProtocol::readByte(buffer, byte);
			temp_i64 |= static_cast<uint64_t>((byte & 0x7fu) << shift);
			shift += 7;
			if (!(byte & 0x80u)) { break; }
		}
		i64 = temp_i64;
	}

public:
	// write begin functions
	static void writeMessageBegin(std::string& buffer, const char* name, const TMessageType messageType, const uint32_t seqid)
	{
		TCompactProtocol::writeByte(buffer, TCompactProtocol::PROTOCOL_ID);
		TCompactProtocol::writeByte(buffer, ((TCompactProtocol::VERSION_N & TCompactProtocol::VERSION_MASK) | ((static_cast<uint32_t>(messageType) << TCompactProtocol::TYPE_SHIFT_AMOUNT) & TCompactProtocol::TYPE_MASK)));
		TCompactProtocol::writeVarint32(buffer, seqid);
		TCompactProtocol::writeBinary(buffer, name);
	}
	static void writeStructBegin(std::stack<uint16_t>& lastField)
	{
		lastField.push(0);
	}
	static void writeFieldBegin(std::string& buffer, std::stack<uint16_t>& lastField, const TCompactType fieldType, const uint16_t fieldId, const bool boolValue = false)
	{
		uint8_t typeToWrite = static_cast<uint8_t>((fieldType == TCompactType::BOOL) ? (boolValue ? TCompactType::TRUE : TCompactType::FALSE) : fieldType);
		uint16_t lastFieldId = lastField.top();
		if (fieldId > lastFieldId && fieldId - lastFieldId <= 15)
		{
			TCompactProtocol::writeByte(buffer, static_cast<uint8_t>((fieldId - lastFieldId) << 4 | typeToWrite));
		}
		else
		{
			TCompactProtocol::writeByte(buffer, typeToWrite);
			TCompactProtocol::writeI16(buffer, fieldId);
		}
		lastField.pop();
		lastField.push(fieldId);
	}
	static void writeMapBegin(std::string& buffer, const TCompactType keyType, const TCompactType valType, const uint32_t size)
	{
		if (size == 0)
		{
			TCompactProtocol::writeByte(buffer, 0);
		}
		else
		{
			TCompactProtocol::writeVarint32(buffer, size);
			TCompactProtocol::writeByte(buffer, ((static_cast<uint8_t>(keyType) << 4) | static_cast<uint8_t>(valType)));
		}
	}
	static void writeCollectionBegin(std::string& buffer, const TCompactType elemType, const uint32_t size)
	{
		if (size <= 14)
		{
			TCompactProtocol::writeByte(buffer, (uint8_t)(size << 4 | (uint8_t)elemType));
		}
		else
		{
			TCompactProtocol::writeByte(buffer, (0xf0u | static_cast<uint8_t>(elemType)));
			TCompactProtocol::writeVarint32(buffer, size);
		}
	}
	static void writeListBegin(std::string & buffer, const TCompactType elemType, const uint32_t size) { writeCollectionBegin(buffer, elemType, size); }
	static void writeSetBegin(std::string & buffer, const TCompactType elemType, const uint32_t size) { writeCollectionBegin(buffer, elemType, size); }

	// write functions
	static void writeBool(std::string& buffer, const bool value)
	{
		buffer += static_cast<uint8_t>(value ? TCompactType::TRUE : TCompactType::FALSE);
	}
	static void writeByte(std::string& buffer, const uint8_t byte)
	{
		buffer += byte;
	}
	static void writeI16(std::string& buffer, const uint16_t i16)
	{
		TCompactProtocol::writeVarint32(buffer, TCompactProtocol::i32ToZigzag(i16));
	}
	static void writeI32(std::string& buffer, const uint32_t i32)
	{
		TCompactProtocol::writeVarint32(buffer, TCompactProtocol::i32ToZigzag(i32));
	}
	static void writeI64(std::string& buffer, const uint64_t i64)
	{
		TCompactProtocol::writeVarint64(buffer, TCompactProtocol::i64ToZigzag(i64));
	}
	static void writeDouble(std::string& buffer, const double dub)
	{
		uint64_t bits;
		std::memcpy(&bits, &dub, 8);
		bits = htole64(bits);
		buffer.append(reinterpret_cast<char*>(&bits), 8);
	}
	static void writeBinary(std::string& buffer, const char* bin)
	{
		TCompactProtocol::writeVarint32(buffer, std::strlen(bin));
		buffer.append(bin);
	}
	static void writeString(std::string& buffer, const std::string& str)
	{
		TCompactProtocol::writeVarint32(buffer, str.size());
		buffer.append(str);
	}

	// write end functions
	static void writeFieldStop(std::string& buffer)
	{
		TCompactProtocol::writeByte(buffer, static_cast<uint8_t>(TCompactType::STOP));
	}
	static void writeStructEnd(std::stack<uint16_t>& lastField)
	{
		lastField.pop();
	}

	// useless write functions
	static void writeMessageEnd() {}
	static void writeFieldEnd() {}
	static void writeMapEnd() {}
	static void writeListEnd() {}
	static void writeSetEnd() {}

	// read begin functions
	static void readMessageBegin(char const*& buffer, TMessageType& messageType)
	{
		uint8_t protocolId;
		uint8_t versionAndType;
		uint32_t seqid;
		std::string name;
		TCompactProtocol::readByte(buffer, protocolId);
		TCompactProtocol::readByte(buffer, versionAndType);
		TCompactProtocol::readVarint32(buffer, seqid);
		TCompactProtocol::readString(buffer, name);
		messageType = static_cast<TMessageType>((versionAndType >> TCompactProtocol::TYPE_SHIFT_AMOUNT) & TCompactProtocol::TYPE_BITS);
	}
	static void readStructBegin(std::stack<uint16_t>& lastField)
	{
		lastField.push(0);
	}
	static void readFieldBegin(char const*& buffer, std::stack<uint16_t>& lastField, TCompactType& fieldType)
	{
		uint8_t byte;
		uint16_t fieldId;
		TCompactProtocol::readByte(buffer, byte);
		fieldType = static_cast<TCompactType>(byte & 0x0fu);
		if (fieldType == TCompactType::STOP)
		{
			return;
		}
		fieldId = static_cast<uint16_t>((byte & 0xf0u) >> 4);
		if (fieldId == 0)
		{
			TCompactProtocol::readI16(buffer, fieldId);
		}
		else
		{
			fieldId += lastField.top();
		}
		lastField.pop();
		lastField.push(fieldId);
	}
	static void readMapBegin(char const*& buffer, TCompactType& keyType, TCompactType& valType, uint32_t& size)
	{
		uint8_t kvType;
		TCompactProtocol::readVarint32(buffer, size);
		TCompactProtocol::readByte(buffer, kvType);
		keyType = static_cast<TCompactType>(kvType >> 4);
		valType = static_cast<TCompactType>(kvType & 0xfu);
	}
	static void readListBegin(char const*& buffer, TCompactType& elemType, uint32_t& size)
	{
		uint8_t size_and_type;
		uint32_t list_size;
		TCompactProtocol::readByte(buffer, size_and_type);
		list_size = static_cast<uint32_t>((size_and_type >> 4) & 0x0fu);
		if (list_size == 15)
		{
			TCompactProtocol::readVarint32(buffer, list_size);
		}
		size = list_size;
		elemType = static_cast<TCompactType>(size_and_type & 0x0fu);
	}
	static void readSetBegin(char const*& buffer, TCompactType & elemType, uint32_t & size) { readListBegin(buffer, elemType, size); }

	// read functions
	static void readBool(char const*& buffer, bool& value)
	{
		uint8_t val;
		TCompactProtocol::readByte(buffer, val);
		value = (static_cast<TCompactType>(val) == TCompactType::TRUE);
	}
	static void readByte(char const*& buffer, uint8_t& byte)
	{
		byte = static_cast<uint8_t>(*(buffer++));
	}
	static void readI16(char const*& buffer, uint16_t& i16)
	{
		uint32_t i32;
		TCompactProtocol::readVarint32(buffer, i32);
		i16 = static_cast<uint16_t>(TCompactProtocol::zigzagToI32(i32));
	}
	static void readI32(char const*& buffer, uint32_t& i32)
	{
		uint32_t temp_i32;
		TCompactProtocol::readVarint32(buffer, temp_i32);
		i32 = TCompactProtocol::zigzagToI32(temp_i32);
	}
	static void readI64(char const*& buffer, uint64_t& i64)
	{
		uint64_t temp_i64;
		TCompactProtocol::readVarint64(buffer, temp_i64);
		i64 = TCompactProtocol::zigzagToI64(temp_i64);
	}
	static void readDouble(char const*& buffer, double& dub)
	{
		union
		{
			double dit;
			uint64_t bits;
			uint8_t b[8];
		} u;
		std::memcpy(u.b, buffer, 8);
		buffer += 8;
		u.bits = le64toh(u.bits);
		dub = u.dit;
	}
	static void readString(char const*& buffer, std::string & str) { readBinary(buffer, str); }
	static void readBinary(char const*& buffer, std::string& str)
	{
		uint32_t size;
		TCompactProtocol::readVarint32(buffer, size);
		if (size == 0)
		{
			return;
		}
		str.append(buffer, size);
		buffer += size;
	}
	static void skip(char const*& buffer, TCompactType& ttype, bool is_in_container)
	{
		switch (ttype)
		{
		case TCompactType::STOP:
		{
			break;
		}
		case TCompactType::TRUE: // also BOOL
		{
			// reusing is_in_container since it's no longer needed
			if (is_in_container) { TCompactProtocol::readBool(buffer, is_in_container); }
			break;
		}
		case TCompactType::FALSE:
		{
			// reusing is_in_container since it's no longer needed
			if (is_in_container) { TCompactProtocol::readBool(buffer, is_in_container); }
			break;
		}
		case TCompactType::BYTE:
		{
			uint8_t unused_byte;
			TCompactProtocol::readByte(buffer, unused_byte);
			break;
		}
		case TCompactType::I16:
		{
			uint16_t unused_i16;
			TCompactProtocol::readI16(buffer, unused_i16);
			break;
		}
		case TCompactType::I32:
		{
			uint32_t unused_i32;
			TCompactProtocol::readI32(buffer, unused_i32);
			break;
		}
		case TCompactType::I64:
		{
			uint64_t unused_i64;
			TCompactProtocol::readI64(buffer, unused_i64);
			break;
		}
		case TCompactType::DOUBLE:
		{
			double unused_double;
			TCompactProtocol::readDouble(buffer, unused_double);
			break;
		}
		case TCompactType::STRING:  // also BINARY
		{
			std::string unused_string;
			TCompactProtocol::readString(buffer, unused_string);
			break;
		}
		case TCompactType::LIST:
		{
			TCompactType elemType;
			uint32_t list_size;
			TCompactProtocol::readListBegin(buffer, elemType, list_size);
			for (uint_fast32_t i = 0; i < list_size; ++i)
			{
				TCompactProtocol::skip(buffer, elemType, true);
			}
			TCompactProtocol::readListEnd();
			break;
		}
		case TCompactType::SET:
		{
			TCompactType elemType;
			uint32_t set_size;
			TCompactProtocol::readSetBegin(buffer, elemType, set_size);
			for (uint_fast32_t i = 0; i < set_size; ++i)
			{
				TCompactProtocol::skip(buffer, elemType, true);
			}
			TCompactProtocol::readSetEnd();
			break;
		}
		case TCompactType::MAP:
		{
			TCompactType keyType, valType;
			uint32_t map_size;
			TCompactProtocol::readMapBegin(buffer, keyType, valType, map_size);
			for (uint_fast32_t i = 0; i < map_size; ++i)
			{
				TCompactProtocol::skip(buffer, keyType, true);
				TCompactProtocol::skip(buffer, valType, true);
			}
			TCompactProtocol::readMapEnd();
			break;
		}
		case TCompactType::STRUCT:
		{
			std::stack<uint16_t> _lastField;
			TCompactProtocol::readStructBegin(_lastField);
			while (true)
			{
				TCompactType fieldType;
				TCompactProtocol::readFieldBegin(buffer, _lastField, fieldType);
				if (fieldType == TCompactType::STOP) { break; }
				TCompactProtocol::skip(buffer, fieldType, false);
				TCompactProtocol::readFieldEnd();
			}
			TCompactProtocol::readStructEnd(_lastField);
			break;
		}
		}
	}

	// read end functions
	static void readStructEnd(std::stack<uint16_t>& lastField)
	{
		lastField.pop();
	}

	// useless read functions
	static void readMessageEnd() {}
	static void readFieldEnd() {}
	static void readMapEnd() {}
	static void readListEnd() {}
	static void readSetEnd() {}
};

#endif  // !THRIFT_COMPACT_PROTOCOL_H
