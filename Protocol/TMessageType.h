#ifndef THRIFT_MESSAGE_TYPE_H
#define THRIFT_MESSAGE_TYPE_H

#include <cstdint>

enum class TMessageType : uint8_t
{
	CALL = 1,
	REPLY = 2,
	EXCEPTION = 3,
	ONEWAY = 4
};

#endif  // THRIFT_MESSAGE_TYPE_H
