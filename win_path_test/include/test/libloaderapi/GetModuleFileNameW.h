#pragma once

#include <string>

namespace test {
namespace libloaderapi {
std::string GetModuleFileNameW(void *hModule = nullptr);
}
}