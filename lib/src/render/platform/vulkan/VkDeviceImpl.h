#ifndef INDIUM_LIB_SRC_RENDER_PLATFORM_VULKAN_VKDEVICEIMPL_H
#define INDIUM_LIB_SRC_RENDER_PLATFORM_VULKAN_VKDEVICEIMPL_H

#include "../../IDevice.h"

class VkDeviceImpl : public IDevice
{
public:
  VkDeviceImpl() = default;
  void use() override {}
};

#endif