#include <chrono>
#include <cstdint>
#include <iostream>
#include <optional>
#include <string>
#include <unistd.h>

#include "LINE.h"
#include "Utils/all.h"
#include "Talk/all.h"

int main()
{
    // token
    const std::string authtoken = "token";

    // setup socket
    int32_t sockfd = transport::get_connected_socket(config::HOST_NAME, config::PORT);
    if (sockfd < 0)
    {
        std::cout << "Creating a connected socket failed" << std::endl;
        return 0;
    }

    // setup headers
    auto line_headers = transport::create_line_basic_headers(authtoken, config::HOST_NAME, config::USER_AGENT, config::X_LINE_APPLICATION, true);
    auto poll_split_header = transport::create_split_header("POST", config::POLL_ENDPOINT, line_headers, "Content-Length");
    auto normal_split_header = transport::create_split_header("POST", config::NORMAL_ENDPOINT, line_headers, "Content-Length");

    // setup variables
    std::optional<protocol::TalkException> talk_exception;
    std::optional<protocol::ShouldSyncException> should_sync_exception;
    uint_fast16_t status_code;
    uint64_t rev;
    std::vector<protocol::Operation> ops;
    ops.reserve(5);

    // get rev(ision)
    status_code = talk::getLastOpRevision(sockfd, normal_split_header, rev, talk_exception);
    if (status_code != 200 || talk_exception.has_value())
    {
        std::cout << "Error getting last op revision" << std::endl;
        return 0;
    }

    
    // poll
    while (true)
    {
        status_code = talk::fetchOperations(sockfd, normal_split_header, rev, 5, ops, should_sync_exception);
        if ((status_code != 200 && status_code != 204) || talk_exception.has_value())
        {
            std::cout << "Error fetching operations" << std::endl;
            std::cout << "Status code: " << status_code << std::endl;
            return 0;
        }
        if (ops.size() == 0) { continue; }
        for (auto& op : ops)
        {
            if (*op.type == protocol::OpType::END_OF_OPERATION) { continue; }
            std::cout << "OpType: " << static_cast<uint32_t>(*op.type) << std::endl;
            rev = (*op.revision < rev) ? rev : *op.revision;
            if (*op.type == protocol::OpType::RECEIVE_MESSAGE)
            {
                auto now = std::chrono::high_resolution_clock::now();
                auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
                auto epoch = now_ms.time_since_epoch();
                auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
                double ms = value.count();
                ms -= (double)(*op.createdTime);
                std::cout << "Responsetime: " << ms << std::endl;
            }
        }
        ops.clear();
    }

    // finish
    close(sockfd);
    return 0;
}
