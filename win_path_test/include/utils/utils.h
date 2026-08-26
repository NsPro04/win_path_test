#pragma once

#include <string>
#include <string_view>
#include <filesystem>

namespace utils {
inline std::string wstr2str(std::wstring path_wstr) {
  const auto path = std::filesystem::path(std::move(path_wstr));

  const std::u8string path_u8 = path.u8string();
  const std::string_view path_sv(reinterpret_cast<const char *>(path_u8.data()), path_u8.size());

  return std::string(path_sv.data(), path_sv.size());
}
}