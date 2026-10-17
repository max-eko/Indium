#ifndef INDIUM_LIB_SRC_LOGGER_LOGGER_H
#define INDIUM_LIB_SRC_LOGGER_LOGGER_H

#include <string>

enum class Status
{
  INFO,
  WARN,
  ERR
};

namespace logger
{
  void init();
  void log(const std::string &message, Status status = Status::INFO);
};

#endif
