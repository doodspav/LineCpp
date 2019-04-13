#ifndef THRIFT_COMPACT_TYPE_H
#define THRIFT_COMPACT_TYPE_H

#include <cstdint>

enum class TCompactType : uint8_t
{
	STOP = 0,
	BOOL = 1,
	TRUE = 1,
	FALSE = 2,
	BYTE = 3,
	I16 = 4,
	I32 = 5,
	I64 = 6,
	DOUBLE = 7,
	STRING = 8,
	BINARY = 8,
	LIST = 9,
	SET = 10,
	MAP = 11,
	STRUCT = 12
};

#endif  // THRIFT_COMPACT_TYPE_H
