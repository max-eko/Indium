#include "render/context/platform/vulkan/VkRenderContextImpl.h"

void VkRenderContextImpl::init()
{
  vk::ApplicationInfo appInfo{};
  appInfo.setPApplicationName(m_AppName.c_str())
       .setApplicationVersion(VK_MAKE_VERSION(1, 0, 0))
       .setPEngineName("Indium")
       .setEngineVersion(VK_MAKE_VERSION(1, 0, 0))
       .setApiVersion(vk::ApiVersion14);
  vk::InstanceCreateInfo createInfo{};
  createInfo.setPApplicationInfo(&appInfo);
}