#pragma once

#include <string>

namespace test {
namespace psapi {
std::string K32GetProcessImageFileNameW(void *process = nullptr);
}
}