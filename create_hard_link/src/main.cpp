#include <fstream>
#include <stdexcept>
#include <format>
#include <iostream>
#include <string_view>
#include <filesystem>

namespace ns {
using u8ifstream = std::basic_ifstream<char8_t, std::char_traits<char8_t>>;
};

int wmain() try {
  constexpr std::u8string_view txt_path_u8 = u8"./path.txt";
  constexpr std::u8string_view exe_path_u8 = u8"./test.exe";

  const std::string_view txt_path_sv(reinterpret_cast<const char *>(txt_path_u8.data()), txt_path_u8.size());
  const std::string_view exe_path_sv(reinterpret_cast<const char *>(exe_path_u8.data()), exe_path_u8.size());

  const auto txt_path = std::filesystem::path(txt_path_u8);
  const auto exe_path = std::filesystem::path(exe_path_u8);

  if (!std::filesystem::exists(txt_path)) {
    throw std::runtime_error(std::format("File not found: {}", txt_path_sv));
  };

  if (!std::filesystem::exists(exe_path)) {
    throw std::runtime_error(std::format("File not found: {}", exe_path_sv));
  };

  const size_t file_size = std::filesystem::file_size(txt_path);

  std::u8string dest_path_u8(file_size, u8'\0');

  ns::u8ifstream(txt_path, std::ios::binary).read(dest_path_u8.data(), file_size);

  const auto dest_path = std::filesystem::path(std::move(dest_path_u8));

  std::filesystem::create_directories(dest_path.parent_path());

  std::filesystem::create_hard_link(exe_path, dest_path);

  return 0;
} catch (const std::exception &e) {
  std::cout << std::format("Exception: {}", e.what()) << std::endl;

  std::cin.get();
  return 1;
};