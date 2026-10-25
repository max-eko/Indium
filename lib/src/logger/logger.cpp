#include "logger/Logger.h"

#include <chrono>
#include <iostream>
#include <source_location>

#ifdef _WIN32
#include <windows.h>
#endif

void logger::init()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
#ifdef _WIN32
  // Forces the Windows console to interpret ANSI escape codes
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  if (hOut != INVALID_HANDLE_VALUE) {
    DWORD dwMode = 0;
    if (GetConsoleMode(hOut, &dwMode)) {
      dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
      SetConsoleMode(hOut, dwMode);
    }
  }
#endif
}
void logger::log(const std::string &message, Status status, const std::source_location& location)
{
  using namespace std::chrono;

  auto now = time_point_cast<duration<int, std::ratio<1, 10>>>(system_clock::now());

  std::string time = std::format("{:%H:%M:%S}", now);

  switch (status)
  {
  case Status::INFO:
    std::cout << "\033[90m[" << time << " UTC] \033[0m" << message << "\n";
    break;
  case Status::WARN:
    std::cout << "\033[33m[" << time << " UTC] WARNING: " << message <<  " on line " << location.line() << " in file " << location.file_name() << "\033[0m\n";
    break;
  case Status::ERR:
    std::cout << "\033[91m[" << time << " UTC] ERROR: " << message << " on line " << location.line() << " in file " << location.file_name() << "\033[0m\n";
    break;
    }
}