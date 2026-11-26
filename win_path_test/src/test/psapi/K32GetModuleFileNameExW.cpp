#include <test/psapi/K32GetModuleFileNameExW.h>
#include <utils/utils.h>

#include <windows.h>
#include <psapi.h>

std::string test::psapi::K32GetModuleFileNameExW(void *hModule, void *process) {
  if (process == nullptr) process = ::GetCurrentProcess();

  std::wstring path_wstr(MAX_PATH, L'\0');

  while (true) {
    const DWORD path_size = ::K32GetModuleFileNameExW(process, reinterpret_cast<HMODULE>(hModule), path_wstr.data(), path_wstr.size());

    if (!path_size) throw std::exception("!K32GetMappedFileNameW");

    if ((path_size + 1uz) < path_wstr.size()) {
      path_wstr.erase(path_size);
      break;
    }

    path_wstr.resize(path_wstr.size() + MAX_PATH, L'\0');
  }

  return utils::wstr2str(std::move(path_wstr));
}