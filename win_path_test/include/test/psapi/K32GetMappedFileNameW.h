#pragma once

#include <string>

namespace test {
namespace psapi {
std::string K32GetMappedFileNameW(void *ptr = nullptr, void *process = nullptr);
}
}