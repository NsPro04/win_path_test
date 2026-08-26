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

  std::println("QueryFullProcessImageNameW win32: {}",  test::winbase::QueryFullProcessImageNameW(false));
  std::println("QueryFullProcessImageNameW native: {}", test::winbase::QueryFullProcessImageNameW(true));

  std::println("GetModuleFileNameW: {}", test::libloaderapi::GetModuleFileNameW());

  try {
    std::println("K32GetMappedFileNameW: {}", test::psapi::K32GetMappedFileNameW(&print_exe_path));
  } catch (const std::exception &e) {
    std::println("K32GetMappedFileNameW last error: {}", GetLastError());

    SetLastError(0);
  }
  std::println("K32GetModuleBaseNameW: {}", test::psapi::K32GetModuleBaseNameW());
  std::println("K32GetModuleFileNameExW: {}", test::psapi::K32GetModuleFileNameExW());
  std::println("K32GetProcessImageFileNameW: {}", test::psapi::K32GetProcessImageFileNameW());
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