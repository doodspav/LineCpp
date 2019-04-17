#ifndef LINE_CONFIG_H
#define LINE_CONFIG_H

#include <cstdint>
#include <string_view>

namespace config
{
	// host & ip
	constexpr std::string_view HOST_NAME = "legy-jp.line.naver.jp";
	constexpr uint_fast16_t PORT = 443;

	// endpoints
	constexpr std::string_view NORMAL_ENDPOINT = "/S4";
	constexpr std::string_view POLL_ENDPOINT = "/P4";
	constexpr std::string_view AUTH_ENDPOINT = "/api/v4p/rs";

	// user_agent & app_version combinations
	constexpr std::string_view USER_AGENT = "LI/7.150 iPad6,3 10.2";
	constexpr std::string_view X_LINE_APPLICATION = "IOS\t8.2.4\tiOS\t10.2";
}

#endif // !LINE_CONFIG
