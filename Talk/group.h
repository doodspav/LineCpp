#ifndef TALK_GROUP_H
#define TALK_GROUP_H

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <unistd.h>

namespace talk {

	// createGroup

	uint_fast16_t createGroup(int32_t sockfd, string_pair& split_header, uint32_t seq, std::string& name, std::vector<std::string>& contactIds, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::createGroup(payload, seq, name, contactIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::createGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t createGroup(int32_t sockfd, string_pair& split_header, transport::http_response& response, uint32_t seq, std::string& name, std::vector<std::string>& contactIds, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::createGroup(payload, seq, name, contactIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::createGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t createGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, uint32_t seq, std::string& name, std::vector<std::string>& contactIds, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::createGroup(payload, seq, name, contactIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::createGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t createGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, uint32_t seq, std::string& name, std::vector<std::string>& contactIds, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::createGroup(payload, seq, name, contactIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::createGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	// createGroupV2

	uint_fast16_t creatGroupV2(int32_t sockfd, string_pair& split_header, uint32_t seq, std::string& name, std::vector<std::string>& contactIds, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::createGroupV2(payload, seq, name, contactIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::createGroupV2(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t creatGroupV2(int32_t sockfd, string_pair& split_header, transport::http_response& response, uint32_t seq, std::string& name, std::vector<std::string>& contactIds, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::createGroupV2(payload, seq, name, contactIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::createGroupV2(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t creatGroupV2(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, uint32_t seq, std::string& name, std::vector<std::string>& contactIds, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::createGroupV2(payload, seq, name, contactIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::createGroupV2(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t creatGroupV2(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, uint32_t seq, std::string& name, std::vector<std::string>& contactIds, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::createGroupV2(payload, seq, name, contactIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::createGroupV2(response.payload.data(), group, e);
		return response.status_code;
	}
	
	// getGroup

	uint_fast16_t getGroup(int32_t sockfd, string_pair& split_header, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroup(payload, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t getGroup(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroup(payload, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t getGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroup(payload, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t getGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroup(payload, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	// getCompactGroup

	uint_fast16_t getCompactGroup(int32_t sockfd, string_pair& split_header, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getCompactGroup(payload, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getCompactGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t getCompactGroup(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getCompactGroup(payload, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getCompactGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t getCompactGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getCompactGroup(payload, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getCompactGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t getCompactGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getCompactGroup(payload, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getCompactGroup(response.payload.data(), group, e);
		return response.status_code;
	}

	// getGroupWithoutMembers

	uint_fast16_t getGroupWithoutMembers(int32_t sockfd, string_pair& split_header, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroupWithoutMembers(payload, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupWithoutMembers(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t getGroupWithoutMembers(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroupWithoutMembers(payload, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupWithoutMembers(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t getGroupWithoutMembers(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroupWithoutMembers(payload, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupWithoutMembers(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t getGroupWithoutMembers(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::string& groupId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroupWithoutMembers(payload, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupWithoutMembers(response.payload.data(), group, e);
		return response.status_code;
	}

	// getGroupMemberMids

	uint_fast16_t getGroupMemberMids(int32_t sockfd, string_pair& split_header, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroupMemberMids(payload, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupMemberMids(response.payload.data(), contactIds, e);
		return response.status_code;
	}

	uint_fast16_t getGroupMemberMids(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroupMemberMids(payload, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupMemberMids(response.payload.data(), contactIds, e);
		return response.status_code;
	}

	uint_fast16_t getGroupMemberMids(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroupMemberMids(payload, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupMemberMids(response.payload.data(), contactIds, e);
		return response.status_code;
	}

	uint_fast16_t getGroupMemberMids(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroupMemberMids(payload, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupMemberMids(response.payload.data(), contactIds, e);
		return response.status_code;
	}

	// getGroups

	uint_fast16_t getGroups(int32_t sockfd, string_pair& split_header, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroups(payload, groupIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroups(response.payload.data(), groups, e);
		return response.status_code;
	}

	uint_fast16_t getGroups(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroups(payload, groupIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroups(response.payload.data(), groups, e);
		return response.status_code;
	}

	uint_fast16_t getGroups(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroups(payload, groupIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroups(response.payload.data(), groups, e);
		return response.status_code;
	}

	uint_fast16_t getGroups(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroups(payload, groupIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroups(response.payload.data(), groups, e);
		return response.status_code;
	}

	// getGroupsV2

	uint_fast16_t getGroupsV2(int32_t sockfd, string_pair& split_header, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroupsV2(payload, groupIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupsV2(response.payload.data(), groups, e);
		return response.status_code;
	}

	uint_fast16_t getGroupsV2(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroupsV2(payload, groupIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupsV2(response.payload.data(), groups, e);
		return response.status_code;
	}

	uint_fast16_t getGroupsV2(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroupsV2(payload, groupIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupsV2(response.payload.data(), groups, e);
		return response.status_code;
	}

	uint_fast16_t getGroupsV2(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroupsV2(payload, groupIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupsV2(response.payload.data(), groups, e);
		return response.status_code;
	}

	// getCompactGroups

	uint_fast16_t getCompactGroups(int32_t sockfd, string_pair& split_header, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getCompactGroups(payload, groupIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getCompactGroups(response.payload.data(), groups, e);
		return response.status_code;
	}

	uint_fast16_t getCompactGroups(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getCompactGroups(payload, groupIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getCompactGroups(response.payload.data(), groups, e);
		return response.status_code;
	}

	uint_fast16_t getCompactGroups(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getCompactGroups(payload, groupIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getCompactGroups(response.payload.data(), groups, e);
		return response.status_code;
	}

	uint_fast16_t getCompactGroups(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::vector<std::string>& groupIds, std::vector<protocol::Group>& groups, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getCompactGroups(payload, groupIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getCompactGroups(response.payload.data(), groups, e);
		return response.status_code;
	}

	// getGroupIdsInvited

	uint_fast16_t getGroupIdsInvited(int32_t sockfd, string_pair& split_header, std::vector<std::string>& groupIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroupIdsInvited(payload);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupIdsInvited(response.payload.data(), groupIds, e);
		return response.status_code;
	}

	uint_fast16_t getGroupIdsInvited(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::vector<std::string>& groupIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroupIdsInvited(payload);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupIdsInvited(response.payload.data(), groupIds, e);
		return response.status_code;
	}

	uint_fast16_t getGroupIdsInvited(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::vector<std::string>& groupIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroupIdsInvited(payload);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupIdsInvited(response.payload.data(), groupIds, e);
		return response.status_code;
	}

	uint_fast16_t getGroupIdsInvited(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::vector<std::string>& groupIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroupIdsInvited(payload);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupIdsInvited(response.payload.data(), groupIds, e);
		return response.status_code;
	}

	// getGroupIdsJoined

	uint_fast16_t getGroupIdsJoined(int32_t sockfd, string_pair& split_header, std::vector<std::string>& groupIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroupIdsJoined(payload);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupIdsJoined(response.payload.data(), groupIds, e);
		return response.status_code;
	}

	uint_fast16_t getGroupIdsJoined(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::vector<std::string>& groupIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::getGroupIdsJoined(payload);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupIdsJoined(response.payload.data(), groupIds, e);
		return response.status_code;
	}

	uint_fast16_t getGroupIdsJoined(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::vector<std::string>& groupIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroupIdsJoined(payload);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupIdsJoined(response.payload.data(), groupIds, e);
		return response.status_code;
	}

	uint_fast16_t getGroupIdsJoined(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::vector<std::string>& groupIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::getGroupIdsJoined(payload);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::getGroupIdsJoined(response.payload.data(), groupIds, e);
		return response.status_code;
	}

	// findGroupByTicket

	uint_fast16_t findGroupByTicket(int32_t sockfd, string_pair& split_header, std::string& ticketId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::findGroupByTicket(payload, ticketId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::findGroupByTicket(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t findGroupByTicket(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::string& ticketId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::findGroupByTicket(payload, ticketId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::findGroupByTicket(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t findGroupByTicket(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::string& ticketId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::findGroupByTicket(payload, ticketId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::findGroupByTicket(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t findGroupByTicket(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::string& ticketId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::findGroupByTicket(payload, ticketId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::findGroupByTicket(response.payload.data(), group, e);
		return response.status_code;
	}

	// findGroupByTicketV2

	uint_fast16_t findGroupByTicketV2(int32_t sockfd, string_pair& split_header, std::string& ticketId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::findGroupByTicketV2(payload, ticketId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::findGroupByTicketV2(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t findGroupByTicketV2(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::string& ticketId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::findGroupByTicketV2(payload, ticketId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::findGroupByTicketV2(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t findGroupByTicketV2(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::string& ticketId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::findGroupByTicketV2(payload, ticketId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::findGroupByTicketV2(response.payload.data(), group, e);
		return response.status_code;
	}

	uint_fast16_t findGroupByTicketV2(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::string& ticketId, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::findGroupByTicketV2(payload, ticketId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::findGroupByTicketV2(response.payload.data(), group, e);
		return response.status_code;
	}

	// reissueGroupTicket

	uint_fast16_t reissueGroupTicket(int32_t sockfd, string_pair& split_header, std::string& groupId, std::string& ticketId, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::reissueGroupTicket(payload, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::reissueGroupTicket(response.payload.data(), ticketId, e);
		return response.status_code;
	}

	uint_fast16_t reissueGroupTicket(int32_t sockfd, string_pair& split_header, transport::http_response& response, std::string& groupId, std::string& ticketId, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::reissueGroupTicket(payload, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::reissueGroupTicket(response.payload.data(), ticketId, e);
		return response.status_code;
	}

	uint_fast16_t reissueGroupTicket(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, std::string& groupId, std::string& ticketId, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::reissueGroupTicket(payload, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::reissueGroupTicket(response.payload.data(), ticketId, e);
		return response.status_code;
	}

	uint_fast16_t reissueGroupTicket(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, std::string& groupId, std::string& ticketId, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::reissueGroupTicket(payload, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::reissueGroupTicket(response.payload.data(), ticketId, e);
		return response.status_code;
	}

	// acceptGroupInvitation

	uint_fast16_t acceptGroupInvitation(int32_t sockfd, string_pair& split_header, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::acceptGroupInvitation(payload, reqSeq, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::acceptGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t acceptGroupInvitation(int32_t sockfd, string_pair& split_header, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::acceptGroupInvitation(payload, reqSeq, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::acceptGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t acceptGroupInvitation(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::acceptGroupInvitation(payload, reqSeq, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::acceptGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t acceptGroupInvitation(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::acceptGroupInvitation(payload, reqSeq, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::acceptGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	// acceptGroupInvitationByTicket

	uint_fast16_t acceptGroupInvitationByTicket(int32_t sockfd, string_pair& split_header, uint32_t reqSeq, std::string& groupId, std::string& ticketId, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::acceptGroupInvitationByTicket(payload, reqSeq, groupId, ticketId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::acceptGroupInvitationByTicket(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t acceptGroupInvitationByTicket(int32_t sockfd, string_pair& split_header, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::string& ticketId, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::acceptGroupInvitationByTicket(payload, reqSeq, groupId, ticketId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::acceptGroupInvitationByTicket(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t acceptGroupInvitationByTicket(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, uint32_t reqSeq, std::string& groupId, std::string& ticketId, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::acceptGroupInvitationByTicket(payload, reqSeq, groupId, ticketId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::acceptGroupInvitationByTicket(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t acceptGroupInvitationByTicket(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::string& ticketId, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::acceptGroupInvitationByTicket(payload, reqSeq, groupId, ticketId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::acceptGroupInvitationByTicket(response.payload.data(), e);
		return response.status_code;
	}

	// rejectGroupInvitation

	uint_fast16_t rejectGroupInvitation(int32_t sockfd, string_pair& split_header, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::rejectGroupInvitation(payload, reqSeq, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::rejectGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t rejectGroupInvitation(int32_t sockfd, string_pair& split_header, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::rejectGroupInvitation(payload, reqSeq, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::rejectGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t rejectGroupInvitation(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::rejectGroupInvitation(payload, reqSeq, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::rejectGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t rejectGroupInvitation(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::rejectGroupInvitation(payload, reqSeq, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::rejectGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	// cancelGroupInvitation

	uint_fast16_t cancelGroupInvitation(int32_t sockfd, string_pair& split_header, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::cancelGroupInvitation(payload, reqSeq, groupId, contactIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::cancelGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t cancelGroupInvitation(int32_t sockfd, string_pair& split_header, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::cancelGroupInvitation(payload, reqSeq, groupId, contactIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::cancelGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t cancelGroupInvitation(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::cancelGroupInvitation(payload, reqSeq, groupId, contactIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::cancelGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t cancelGroupInvitation(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::cancelGroupInvitation(payload, reqSeq, groupId, contactIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::cancelGroupInvitation(response.payload.data(), e);
		return response.status_code;
	}

	// inviteIntoGroup

	uint_fast16_t inviteIntoGroup(int32_t sockfd, string_pair& split_header, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::inviteIntoGroup(payload, reqSeq, groupId, contactIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::inviteIntoGroup(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t inviteIntoGroup(int32_t sockfd, string_pair& split_header, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::inviteIntoGroup(payload, reqSeq, groupId, contactIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::inviteIntoGroup(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t inviteIntoGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::inviteIntoGroup(payload, reqSeq, groupId, contactIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::inviteIntoGroup(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t inviteIntoGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::inviteIntoGroup(payload, reqSeq, groupId, contactIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::inviteIntoGroup(response.payload.data(), e);
		return response.status_code;
	}

	// kickoutFromGroup

	uint_fast16_t kickoutFromGroup(int32_t sockfd, string_pair& split_header, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::kickoutFromGroup(payload, reqSeq, groupId, contactIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::kickoutFromGroup(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t kickoutFromGroup(int32_t sockfd, string_pair& split_header, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::kickoutFromGroup(payload, reqSeq, groupId, contactIds);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::kickoutFromGroup(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t kickoutFromGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::kickoutFromGroup(payload, reqSeq, groupId, contactIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::kickoutFromGroup(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t kickoutFromGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::vector<std::string>& contactIds, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::kickoutFromGroup(payload, reqSeq, groupId, contactIds);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::kickoutFromGroup(response.payload.data(), e);
		return response.status_code;
	}

	// leaveGroup

	uint_fast16_t leaveGroup(int32_t sockfd, string_pair& split_header, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::leaveGroup(payload, reqSeq, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::leaveGroup(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t leaveGroup(int32_t sockfd, string_pair& split_header, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::leaveGroup(payload, reqSeq, groupId);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::leaveGroup(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t leaveGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::leaveGroup(payload, reqSeq, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::leaveGroup(response.payload.data(), e);
		return response.status_code;
	}

	uint_fast16_t leaveGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, uint32_t reqSeq, std::string& groupId, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::leaveGroup(payload, reqSeq, groupId);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::leaveGroup(response.payload.data(), e);
		return response.status_code;
	}

	// updateGroup

	uint_fast16_t updateGroup(int32_t sockfd, string_pair& split_header, uint32_t reqSeq, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::updateGroup(payload, reqSeq, group);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::updateGroup(response.payload.data(), e);
	}

	uint_fast16_t updateGroup(int32_t sockfd, string_pair& split_header, transport::http_response& response, uint32_t reqSeq, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		std::string payload;
		protocol::write::request::updateGroup(payload, reqSeq, group);
		std::string request = std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::updateGroup(response.payload.data(), e);
	}

	uint_fast16_t updateGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, uint32_t reqSeq, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::updateGroup(payload, reqSeq, group);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::http_response response = transport::read_http_response(sockfd);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::updateGroup(response.payload.data(), e);
	}

	uint_fast16_t updateGroup(int32_t sockfd, string_pair& split_header, std::string& payload, std::string& request, transport::http_response& response, uint32_t reqSeq, protocol::Group& group, std::optional<protocol::TalkException>& e)
	{
		// write request
		protocol::write::request::updateGroup(payload, reqSeq, group);
		request += std::get<0>(split_header);
		request += std::to_string(payload.size());
		request += std::get<1>(split_header);
		request += payload;
		write(sockfd, request.data(), request.size());

		// read response
		transport::read_http_response(sockfd, response);
		if (response.status_code != 200) { return response.status_code; }
		protocol::read::result::updateGroup(response.payload.data(), e);
	}
}

#endif TALK_GROUP_H
