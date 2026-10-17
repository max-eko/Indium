#ifndef INDIUM_LIB_SRC_LOGGER_LOGGER_H
#define INDIUM_LIB_SRC_LOGGER_LOGGER_H

#include <string>

enum class Status
{
  INFO,
  WARN,
  ERR
};

class Logger
{
public:
  Logger();
  void Log(const std::string &message, Status status = Status::INFO);
};

#endif
