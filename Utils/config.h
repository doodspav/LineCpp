#ifndef LINE_CONFIG_H
#define LINE_CONFIG_H

#include <cstdint>

namespace config
{
	// host & ip
	constexpr char HOST_NAME[] = "legy-jp.line.naver.jp";
	constexpr uint_fast16_t PORT = 443;

	// endpoints
	constexpr char NORMAL_ENDPOINT[] = "/S4";
	constexpr char POLL_ENDPOINT[] = "/P4";
	constexpr char AUTH_ENDPOINT[] = "/api/v4p/rs";

	// user_agent & app_version combinations
	constexpr char USER_AGENT[] = "LI/7.150 iPad6,3 10.2";
	constexpr char X_LINE_APPLICATION[] = "IOS\t8.2.4\tiOS\t10.2";
}

#endif // !LINE_CONFIG
