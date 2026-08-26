#include <test/libloaderapi/GetModuleFileNameW.h>
#include <utils/utils.h>

#include <windows.h>

std::string test::libloaderapi::GetModuleFileNameW(void *hModule) {
  std::wstring path_wstr(MAX_PATH, L'\0');

  while (true) {
    const DWORD path_size = ::GetModuleFileNameW(reinterpret_cast<HMODULE>(hModule), path_wstr.data(), path_wstr.size());

    if (!path_size) throw std::exception("!GetModuleFileNameW");

    if (path_size < path_wstr.size()) {
      path_wstr.erase(path_size);
      break;
    }

    path_wstr.resize(path_wstr.size() + MAX_PATH, L'\0');
  }

  return utils::wstr2str(std::move(path_wstr));
};