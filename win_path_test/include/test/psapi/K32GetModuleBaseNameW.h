#pragma once

#include <string>

namespace test {
namespace psapi {
std::string K32GetModuleBaseNameW(void *hModule = nullptr, void *process = nullptr);
}
}