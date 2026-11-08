#ifndef INDIUM_LIB_SRC_RENDER_IDEVICE_H
#define INDIUM_LIB_SRC_RENDER_IDEVICE_H

#include <memory>
#include <vector>

class IDevice
{
public:
  IDevice() = default;
  virtual ~IDevice() = default;

  virtual void use() = 0;

  static std::vector<std::shared_ptr<IDevice>> queryDevices();
};

#endif
