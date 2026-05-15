#include <stdexcept>
#include <format>
#include <iostream>
#include <filesystem>
#include <utility>

#include "windows.h"
#include "psapi.h"

void print_exe_path() {
  system("cls");

  try { // GetModuleFileNameW
    std::wstring path_wstr(MAX_PATH, L'\0');

    while (true) {
      const DWORD ret = GetModuleFileNameW(nullptr, path_wstr.data(), path_wstr.size());

      if (!ret) throw std::exception("!GetModuleFileNameW");

      if (ret < path_wstr.size()) break;

      path_wstr.resize(path_wstr.size() + MAX_PATH, L'\0');
    };

    path_wstr.erase(path_wstr.find(L'\0'));

    const auto path = std::filesystem::path(std::move(path_wstr));

    const std::u8string path_u8 = path.u8string();
    const std::string_view path_sv(reinterpret_cast<const char *>(path_u8.data()), path_u8.size());

    std::cout << std::format("GetModuleFileNameW: (size: {}) {}", path_sv.size(), path_sv) << std::endl;
  } catch (const std::exception &e) {
    std::cout << std::format("GetModuleFileNameW Exception: {}", e.what()) << std::endl;
  };

  try { // QueryFullProcessImageNameW 0
    DWORD path_size = (std::numeric_limits<int16_t>::max)();
    std::wstring path_wstr(path_size, L'\0');
    if (!QueryFullProcessImageNameW(GetCurrentProcess(), 0, path_wstr.data(), &path_size))
      throw std::exception("!QueryFullProcessImageNameW 0");

    path_wstr.erase(path_wstr.find(L'\0'));

    const auto path = std::filesystem::path(std::move(path_wstr));

    const std::u8string path_u8 = path.u8string();
    const std::string_view path_sv(reinterpret_cast<const char *>(path_u8.data()), path_u8.size());

    std::cout << std::format("QueryFullProcessImageNameW 0: (size: {}) {}", path_sv.size(), path_sv) << std::endl;
  } catch (const std::exception &e) {
    std::cout << std::format("QueryFullProcessImageNameW 0 Exception: {}", e.what()) << std::endl;
  };

  try { // QueryFullProcessImageNameW PROCESS_NAME_NATIVE
    DWORD path_size = (std::numeric_limits<int16_t>::max)();
    std::wstring path_wstr(path_size, L'\0');
    if (!QueryFullProcessImageNameW(GetCurrentProcess(), PROCESS_NAME_NATIVE, path_wstr.data(), &path_size))
      throw std::exception("!QueryFullProcessImageNameW PROCESS_NAME_NATIVE");

    path_wstr.erase(path_wstr.find(L'\0'));

    const auto path = std::filesystem::path(std::move(path_wstr));

    const std::u8string path_u8 = path.u8string();
    const std::string_view path_sv(reinterpret_cast<const char *>(path_u8.data()), path_u8.size());

    std::cout << std::format("QueryFullProcessImageNameW PROCESS_NAME_NATIVE: (size: {}) {}", path_sv.size(), path_sv) << std::endl;
  } catch (const std::exception &e) {
    std::cout << std::format("QueryFullProcessImageNameW PROCESS_NAME_NATIVE Exception: {}", e.what()) << std::endl;
  };

  try { // K32GetProcessImageFileNameW
    DWORD path_size = (std::numeric_limits<int16_t>::max)();
    std::wstring path_wstr(path_size, L'\0');
    if (!K32GetProcessImageFileNameW(GetCurrentProcess(), path_wstr.data(), path_size))
      throw std::exception("!K32GetProcessImageFileNameW");

    path_wstr.erase(path_wstr.find(L'\0'));

    const auto path = std::filesystem::path(std::move(path_wstr));

    const std::u8string path_u8 = path.u8string();
    const std::string_view path_sv(reinterpret_cast<const char *>(path_u8.data()), path_u8.size());

    std::cout << std::format("K32GetProcessImageFileNameW: (size: {}) {}", path_sv.size(), path_sv) << std::endl;
  } catch (const std::exception &e) {
    std::cout << std::format("K32GetProcessImageFileNameW Exception: {}", e.what()) << std::endl;
  };

  try { // K32GetModuleFileNameExW
    DWORD path_size = (std::numeric_limits<int16_t>::max)();
    std::wstring path_wstr(path_size, L'\0');
    if (!K32GetModuleFileNameExW(GetCurrentProcess(), nullptr, path_wstr.data(), path_size))
      throw std::exception("!K32GetModuleFileNameExW");

    path_wstr.erase(path_wstr.find(L'\0'));

    const auto path = std::filesystem::path(std::move(path_wstr));

    const std::u8string path_u8 = path.u8string();
    const std::string_view path_sv(reinterpret_cast<const char *>(path_u8.data()), path_u8.size());

    std::cout << std::format("K32GetModuleFileNameExW: (size: {}) {}", path_sv.size(), path_sv) << std::endl;
  } catch (const std::exception &e) {
    std::cout << std::format("K32GetModuleFileNameExW Exception: {}", e.what()) << std::endl;
  };

  try { // K32GetModuleBaseNameW
    DWORD path_size = (std::numeric_limits<int16_t>::max)();
    std::wstring path_wstr(path_size, L'\0');
    if (!K32GetModuleBaseNameW(GetCurrentProcess(), nullptr, path_wstr.data(), path_size))
      throw std::exception("!K32GetModuleBaseNameW");

    path_wstr.erase(path_wstr.find(L'\0'));

    const auto path = std::filesystem::path(std::move(path_wstr));

    const std::u8string path_u8 = path.u8string();
    const std::string_view path_sv(reinterpret_cast<const char *>(path_u8.data()), path_u8.size());

    std::cout << std::format("K32GetModuleBaseNameW: (size: {}) {}", path_sv.size(), path_sv) << std::endl;
  } catch (const std::exception &e) {
    std::cout << std::format("K32GetModuleBaseNameW Exception: {}", e.what()) << std::endl;
  };
};

int wmain() {
  SetConsoleOutputCP(CP_UTF8);

  print_exe_path();

  std::cin.get();
  return 0;
};