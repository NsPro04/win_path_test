#pragma once

#include <string>

namespace test {
namespace psapi {
std::string K32GetModuleFileNameExW(void *hModule = nullptr, void *process = nullptr);
}
}