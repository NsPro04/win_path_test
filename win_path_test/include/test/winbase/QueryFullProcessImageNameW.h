#pragma once

#include <string>

namespace test {
namespace winbase {
std::string QueryFullProcessImageNameW(bool native = false, void *process = nullptr);
}
}