#include <iostream>
#include <print>

#include "windows.h"

#include <test/winbase/QueryFullProcessImageNameW.h>

#include <test/libloaderapi/GetModuleFileNameW.h>

#include <test/psapi/K32GetMappedFileNameW.h>
#include <test/psapi/K32GetModuleBaseNameW.h>
#include <test/psapi/K32GetModuleFileNameExW.h>
#include <test/psapi/K32GetProcessImageFileNameW.h>

void print_exe_path() {
  system("cls");

  try {
    std::println("QueryFullProcessImageNameW win32: {}", test::winbase::QueryFullProcessImageNameW(false));
  } catch (const std::exception &e) {
    std::println("QueryFullProcessImageNameW win32 last error: {}; e: {}", GetLastError(), e.what());

    SetLastError(0);
  }

  try {
    std::println("QueryFullProcessImageNameW native: {}", test::winbase::QueryFullProcessImageNameW(true));
  } catch (const std::exception &e) {
    std::println("QueryFullProcessImageNameW native last error: {}; e: {}", GetLastError(), e.what());

    SetLastError(0);
  }

  try {
    std::println("GetModuleFileNameW: {}", test::libloaderapi::GetModuleFileNameW());
  } catch (const std::exception &e) {
    std::println("GetModuleFileNameW last error: {}; e: {}", GetLastError(), e.what());

    SetLastError(0);
  }

  try {
    std::println("K32GetMappedFileNameW: {}", test::psapi::K32GetMappedFileNameW(&print_exe_path));
  } catch (const std::exception &e) {
    std::println("K32GetMappedFileNameW last error: {}; e: {}", GetLastError(), e.what());

    SetLastError(0);
  }

  try {
    std::println("K32GetModuleBaseNameW: {}", test::psapi::K32GetModuleBaseNameW());
  } catch (const std::exception &e) {
    std::println("K32GetModuleBaseNameW last error: {}; e: {}", GetLastError(), e.what());

    SetLastError(0);
  }

  try {
    std::println("K32GetModuleFileNameExW: {}", test::psapi::K32GetModuleFileNameExW());
  } catch (const std::exception &e) {
    std::println("K32GetModuleFileNameExW last error: {}; e: {}", GetLastError(), e.what());

    SetLastError(0);
  }

  try {
    std::println("K32GetProcessImageFileNameW: {}", test::psapi::K32GetProcessImageFileNameW());
  } catch (const std::exception &e) {
    std::println("K32GetProcessImageFileNameW last error: {}; e: {}", GetLastError(), e.what());

    SetLastError(0);
  }
}

int wmain() {
  SetConsoleOutputCP(CP_UTF8);

  while (true) {
    print_exe_path();
    Sleep(1000);
  };

  std::cin.get();
  return 0;
};