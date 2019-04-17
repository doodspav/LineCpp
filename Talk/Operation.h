#ifndef TALK_OPERATION_H
#define TALK_OPERATION_H

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <unistd.h>

namespace talk {

	// getLastOpRevision

	uint_fast16_t getLastOpRevision(int32_t sockfd, string_pair& split_header, uint64_t& revision, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getLastOpRevision(payload);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getLastOpRevision(response.payload.data(), revision, e);
		return response.status_code;
	}

	uint_fast16_t getLastOpRevision(int32_t sockfd, string_pair& split_header, transport::http_response& response, uint64_t& revision, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getLastOpRevision(payload);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getLastOpRevision(response.payload.data(), revision, e);
		return response.status_code;
	}

	uint_fast16_t getLastOpRevision(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, uint64_t& revision, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getLastOpRevision(payload);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getLastOpRevision(response.payload.data(), revision, e);
		return response.status_code;
	}

	uint_fast16_t getLastOpRevision(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, uint64_t& revision, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getLastOpRevision(payload);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getLastOpRevision(response.payload.data(), revision, e);
		return response.status_code;
	}

	// fetchOperations

	uint_fast16_t fetchOperations(int32_t sockfd, string_pair& split_header, const uint64_t localRev, const uint32_t count, std::vector<protocol::Operation>& ops, std::optional<protocol::ShouldSyncException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::fetchOperations(payload, localRev, count);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::fetchOperations(response.payload.data(), ops, e);
		return response.status_code;
	}

	uint_fast16_t fetchOperations(int32_t sockfd, string_pair& split_header, transport::http_response& response, const uint64_t localRev, const uint32_t count, std::vector<protocol::Operation>& ops, std::optional<protocol::ShouldSyncException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::fetchOperations(payload, localRev, count);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::fetchOperations(response.payload.data(), ops, e);
		return response.status_code;
	}

	uint_fast16_t fetchOperations(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, const uint64_t localRev, const uint32_t count, std::vector<protocol::Operation>& ops, std::optional<protocol::ShouldSyncException>& e)
	{
		// write request
		protocol::write::request::fetchOperations(payload, localRev, count);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::fetchOperations(response.payload.data(), ops, e);
		return response.status_code;
	}

	uint_fast16_t fetchOperations(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, const uint64_t localRev, const uint32_t count, std::vector<protocol::Operation>& ops, std::optional<protocol::ShouldSyncException>& e)
	{
		// write request
		protocol::write::request::fetchOperations(payload, localRev, count);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::fetchOperations(response.payload.data(), ops, e);
		return response.status_code;
	}

	// fetchOps

	uint_fast16_t fetchOps(int32_t sockfd, string_pair& split_header, const uint64_t localRev, const uint32_t count, const uint64_t globalRev, const uint64_t individualRev, std::vector<protocol::Operation>& ops, std::optional<protocol::ShouldSyncException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::fetchOps(payload, localRev, count, globalRev, individualRev);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::fetchOps(response.payload.data(), ops, e);
		return response.status_code;
	}

	uint_fast16_t fetchOps(int32_t sockfd, string_pair& split_header, transport::http_response& response, const uint64_t localRev, const uint32_t count, const uint64_t globalRev, const uint64_t individualRev, std::vector<protocol::Operation>& ops, std::optional<protocol::ShouldSyncException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::fetchOps(payload, localRev, count, globalRev, individualRev);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::fetchOps(response.payload.data(), ops, e);
		return response.status_code;
	}

	uint_fast16_t fetchOps(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, const uint64_t localRev, const uint32_t count, const uint64_t globalRev, const uint64_t individualRev, std::vector<protocol::Operation>& ops, std::optional<protocol::ShouldSyncException>& e)
	{
		// write request
		protocol::write::request::fetchOps(payload, localRev, count, globalRev, individualRev);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::fetchOps(response.payload.data(), ops, e);
		return response.status_code;
	}

	uint_fast16_t fetchOps(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, const uint64_t localRev, const uint32_t count, const uint64_t globalRev, const uint64_t individualRev, std::vector<protocol::Operation>& ops, std::optional<protocol::ShouldSyncException>& e)
	{
		// write request
		protocol::write::request::fetchOps(payload, localRev, count, globalRev, individualRev);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::fetchOps(response.payload.data(), ops, e);
		return response.status_code;
	}
}

#endif // !TALK_OPERATION_H
