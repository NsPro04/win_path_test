#include <fstream>
#include <stdexcept>
#include <format>
#include <iostream>
#include <string_view>
#include <filesystem>

#include "windows.h"

namespace ns {
using u8ifstream = std::basic_ifstream<char8_t, std::char_traits<char8_t>>;
};

int wmain() try {
  constexpr std::u8string_view txt_path_u8 = u8"./path.txt";

  const std::string_view txt_path_sv(reinterpret_cast<const char *>(txt_path_u8.data()), txt_path_u8.size());
  
  const auto txt_path = std::filesystem::path(txt_path_u8);

  if (!std::filesystem::exists(txt_path)) {
    throw std::runtime_error(std::format("File not found: {}", txt_path_sv));
  };

  const size_t file_size = std::filesystem::file_size(txt_path);

  std::u8string dest_path_u8(file_size, u8'\0');

  ns::u8ifstream(txt_path, std::ios::binary).read(dest_path_u8.data(), file_size);

  {
    const std::string_view dest_path_sv(reinterpret_cast<const char *>(dest_path_u8.data()), dest_path_u8.size());
    if (!std::filesystem::exists(dest_path_u8)) {
      throw std::runtime_error(std::format("File not found: {}", dest_path_sv));
    };
  }

  const auto dest_path = std::filesystem::path(std::move(dest_path_u8));

  STARTUPINFOW SIW = {};
  PROCESS_INFORMATION PI = {};

  if(!CreateProcessW(dest_path.c_str(), nullptr, nullptr, nullptr, FALSE, CREATE_NEW_CONSOLE | CREATE_NEW_PROCESS_GROUP | CREATE_UNICODE_ENVIRONMENT, nullptr, nullptr, &SIW, &PI)) {
    throw std::runtime_error("Failed to create process");
  };

  CloseHandle(PI.hProcess);
  CloseHandle(PI.hThread);

  return 0;
} catch (const std::exception &e) {
  std::cout << std::format("Exception: {}", e.what()) << std::endl;

  std::cin.get();
  return 1;
};