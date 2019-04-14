#ifndef LINE_TRANSPORT_H
#define LINE_TRANSPORT_H

#include <cstdint>
#include <cstring>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <unordered_map>

#include "config.h"

namespace transport {

	enum class SocketError : int_fast8_t
	{
		CREATION_FAILED = -1,
		SETTING_OPTIONS_FAILED = -2,
		IP_LOOKUP_FAILED = -3,
		CONNECTION_FAILED = -4
	};

	struct http_response
	{
		uint_fast16_t status_code;
		std::unordered_map<std::string, std::string> headers;
		std::string payload;
	};

	int32_t get_connected_socket(const char* host_name, const uint16_t port)
	{
		// create socket
		int sockfd = socket(AF_INET, SOCK_STREAM, 6);
		if (sockfd < 0) { return static_cast<int32_t>(SocketError::CREATION_FAILED); }

		// set options
		int flag = 0;
		int opt_result = setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (void*)& flag, sizeof(flag));
		if (opt_result != 0)
		{
			close(sockfd);
			return static_cast<int32_t>(SocketError::SETTING_OPTIONS_FAILED); 
		}

		// lookup ip
		hostent* server = gethostbyname(host_name);
		if (server == nullptr) 
		{
			close(sockfd);
			return static_cast<int32_t>(SocketError::IP_LOOKUP_FAILED);
		}

		// setup sockaddr
		sockaddr_in serv_addr;
		std::memset(&serv_addr, 0, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(port);
		std::memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

		// connect
		int conn_result = connect(sockfd, reinterpret_cast<sockaddr*>(&serv_addr), sizeof(serv_addr));
		if (conn_result < 0)
		{
			close(sockfd);
			return static_cast<int32_t>(SocketError::CONNECTION_FAILED);
		}
		
		// success
		return static_cast<int32_t>(sockfd);
	}

	std::string create_talk_header(const char* authtoken, const uint_fast16_t payload_size, bool keep_alive)
	{
		// create return string
		constexpr uint_fast16_t bare_header_size = 191 + std::strlen(config::ENDPOINT) + std::strlen(config::HOST_NAME) + std::strlen(config::USER_AGENT) + std::strlen(config::X_LINE_APPLICATION);
		const uint_fast16_t header_size = bare_header_size + (keep_alive ? 5 : 0) + std::strlen(authtoken) + std::to_string(payload_size).size();
		std::string header;
		header.reserve(header_size);

		// POST
		header += "POST ";
		header += config::ENDPOINT;
		header += " HTTP/1.1\r\n";

		// headers
		header += "Accept: */*\r\nAccept-Encoding: identity\r\nConnection: ";
		header += keep_alive ? "keep-alive\r\nContent-Length: " : "close\r\nContent-Length: ";
		header += std::to_string(payload_size);
		header += "\r\nContent-Type: application/x-thrift\r\nHost: ";
		header += config::HOST_NAME;
		header += "\r\nUser-Agent: ";
		header += config::USER_AGENT;
		header += "\r\nX-Line-Access: ";
		header += authtoken;
		header += "\r\nX-Line-Application: ";
		header += config::X_LINE_APPLICATION;
		header += "\r\n\r\n";

		// return
		return header;
	}

	http_response read_header(int sockfd)
	{
		http_response ret;
		constexpr uint_fast16_t buffer_size = 1024; // should be enough to read all headers
		char buffer[buffer_size]{ 0 };
		char* buf_p = buffer;
		std::string key;
		std::string value;

		// status code
		read(sockfd, buffer, buffer_size);
		while (*buf_p != ' ') { ++buf_p; }  // "HTTP/1.1"
		++buf_p; // " "
		while (*buf_p != ' ') { key += *buf_p++; } // "200"
		ret.status_code = std::stoi(key);
		key.clear();
		while (*buf_p != '\n') { ++buf_p; } // " OK\r"
		++buf_p; // "\n"

		// headers
		while (*buf_p != '\r')
		{
			while (*buf_p != ':') { key += tolower(*buf_p++); } // key
			buf_p += 2; // ": "
			while (*buf_p != '\r') { value += *buf_p++; } // value
			buf_p += 2; // "\r\n"
			ret.headers[key] = value;
			key.clear();
			value.clear();
		}
		buf_p += 2; // "\r\n";

		// payload
		int payload_size = std::stoi(ret.headers["content-length"]);
		if (payload_size > 0)
		{
			int remaining_buffer = buffer_size - (buf_p - buffer);
			ret.payload.reserve(payload_size);
			if (payload_size <= remaining_buffer)
			{
				ret.payload.append(buf_p, payload_size);
			}
			else
			{
				char* payload_p = ret.payload.data();
				ret.payload.append(buf_p, remaining_buffer);
				payload_p += remaining_buffer;
				payload_size -= remaining_buffer;
				read(sockfd, payload_p, payload_size);
			}
		}
		
		// return
		return ret;
	}
}

#endif // !LINE_TRANSPORT_H
