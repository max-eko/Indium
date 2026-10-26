#include "render/context/platform/vulkan/VkRenderContextImpl.h"

void VkRenderContextImpl::init()
{
  // Define standard information about the app
  // NOTE: The version provided here is inaccurate and will always be 1.0.0
  vk::ApplicationInfo appInfo{};
  appInfo.setPApplicationName("Indium")
       .setApplicationVersion(VK_MAKE_VERSION(1, 0, 0))
       .setPEngineName("Indium")
       .setEngineVersion(VK_MAKE_VERSION(1, 0, 0))
       .setApiVersion(vk::ApiVersion14);

  // Get the necessary extensions
  uint32_t extensionCount = 0;
  const char** extensions = m_RenderSurface.getVulkanExtensions(&extensionCount);
  // Check if these extensions are supported
  auto extensionProperties = m_NativeContext.enumerateInstanceExtensionProperties();
  for (uint32_t i = 0; i < extensionCount; ++i)
  {
    if (std::ranges::none_of(extensionProperties,
    [extension = extensions[i]](auto const& extensionProperty)
    { return strcmp(extensionProperty.extensionName, extension) == 0; }))
    {
      throw std::runtime_error("Required Vulkan extension not supported: " + std::string(extensions[i]));
    }
  }
  // Convert the extensions list to a vector
  std::vector<const char*> enabledExtensions(
    extensions, extensions + extensionCount
  );

  // Define an InstanceCreateInfo to create an instance
  vk::InstanceCreateInfo createInfo{};
  createInfo.setPApplicationInfo(&appInfo)
    .setEnabledExtensionCount(extensionCount)
    .setPEnabledExtensionNames(enabledExtensions);
  // Create the instance
  m_NativeInstance = vk::raii::Instance(m_NativeContext, createInfo);

}