#ifndef LINE_CONFIG_H
#define LINE_CONFIG_H

#include <cstdint>

namespace config
{
	constexpr char* HOST_NAME = "legy-jp.line.naver.jp";
	constexpr uint_fast16_t PORT = 443;
	constexpr char* ENDPOINT = "/S4";
	constexpr char* USER_AGENT = "LI/7.150 iPad6,3 10.2";
	constexpr char* X_LINE_APPLICATION = "IOS\t8.2.4\tiOS\t10.2";
}

#endif // !LINE_CONFIG
