#include "IDevice.h"

#include "platform/vulkan/VkDeviceImpl.h"

std::vector<std::shared_ptr<IDevice>> IDevice::queryDevices()
{
  std::vector<std::shared_ptr<IDevice>> vec = {std::make_shared<VkDeviceImpl>()};
  return vec;
}