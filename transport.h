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

	struct http_header_template
	{
		std::string header_start;
		uint64_t content_length;
		std::string header_end;
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

	http_header_template create_header_template(const char* method, const char* endpoint, const std::unordered_map<std::string, std::string>& headers)
	{
		http_header_template hht;

		// POST
		hht.header_start += method;
		hht.header_start += ' ';
		hht.header_start += endpoint;
		hht.header_start += " HTTP/1.1\r\n";

		// headers
		constexpr char upper_content_length[] = "Content-Length";
		constexpr char lower_content_length[] = "content-length";
		for (auto& pair : headers)
		{
			if (pair.first == upper_content_length || pair.first == lower_content_length) { continue; }
			hht.header_start += pair.first + ": ";
			hht.header_start += pair.second + "\r\n";
		}

		// content length
		hht.header_start += "Content-Length: ";
		hht.content_length = 0;
		hht.header_end += "\r\n\r\n";
	}

	std::unordered_map<std::string, std::string> create_line_headers(const std::string& auth_token, const char* host_name, const char* user_agent, const char* app_version, bool keep_alive)
	{
		std::unordered_map<std::string, std::string> headers;

		// insert default
		headers["Accept"] = "*/*";
		headers["Accept-Encoding"] = "identity";
		headers["Connection"] = keep_alive ? "keep-alive" : "close";
		headers["Content-Type"] = "application/x-thrift";
		headers["Host"] = host_name;
		headers["User-Agent"] = user_agent;
		headers["X-Line-Access"] = auth_token;
		headers["X-Line-Application"] = app_version;

		return headers;
	}

	http_response read_http_response(int sockfd)
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

	read_http_response(int sockfd, http_response& ret)
	{
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
	}
}

#endif // !LINE_TRANSPORT_H
