#include <test/psapi/K32GetProcessImageFileNameW.h>
#include <utils/utils.h>

#include <windows.h>
#include <psapi.h>

std::string test::psapi::K32GetProcessImageFileNameW(void *process) {
  if (process == nullptr) process = ::GetCurrentProcess();

  std::wstring path_wstr(32768, L'\0');

  const DWORD path_size = ::K32GetProcessImageFileNameW(process, path_wstr.data(), path_wstr.size());

  if (!path_size) throw std::exception("!K32GetProcessImageFileNameW");

  path_wstr.erase(path_size);

  return utils::wstr2str(std::move(path_wstr));
}