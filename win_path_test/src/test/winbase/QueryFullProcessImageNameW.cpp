#include <test/winbase/QueryFullProcessImageNameW.h>
#include <utils/utils.h>

#include <windows.h>

std::string test::winbase::QueryFullProcessImageNameW(bool native, void *process) {
  if (process == nullptr) process = ::GetCurrentProcess();

  DWORD path_size = 32768;
  std::wstring path_wstr(path_size, L'\0');

  if (!::QueryFullProcessImageNameW(process, native, path_wstr.data(), &path_size))
    throw std::exception("!QueryFullProcessImageNameW");

  path_wstr.erase(path_size);

  return utils::wstr2str(std::move(path_wstr));
}