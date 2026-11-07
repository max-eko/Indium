#include "render/context/platform/vulkan/VkRenderContextImpl.h"

#include <vector>

#include "VkDebugUtil.h"

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
  // Get the required layers
  std::vector<char const*> requiredLayers;
  if (enableValidationLayers)
  {
    requiredLayers.assign(m_ValidationLayers.begin(), m_ValidationLayers.end());
  }

  // Check if the required layers are supported by the Vulkan implementation.
  std::vector<vk::LayerProperties> layerProperties = m_NativeContext.enumerateInstanceLayerProperties();
  std::ranges::borrowed_iterator_t<std::vector<const char*>&>  unsupportedLayerIt = std::ranges::find_if(requiredLayers,
  [&layerProperties](auto const &requiredLayer) {
    return std::ranges::none_of(layerProperties,
      [requiredLayer](auto const &layerProperty) { return strcmp(layerProperty.layerName, requiredLayer) == 0; });
  });
  if (unsupportedLayerIt != requiredLayers.end())
  {
    throw std::runtime_error("Required layer not supported: " + std::string(*unsupportedLayerIt));
  }
  // Create the instance
  m_NativeInstance = vk::raii::Instance(m_NativeContext, createInfo);
  // Setup debug messenger
  if (enableValidationLayers)
  {
    // Setup relevant info for debug messenger
    vk::DebugUtilsMessageSeverityFlagsEXT severityFlags(vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning |
                                                        vk::DebugUtilsMessageSeverityFlagBitsEXT::eError);
    vk::DebugUtilsMessageTypeFlagsEXT messageTypeFlags(
            vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral | vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance | vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation);
    // Specify create info w/ proper values
    vk::DebugUtilsMessengerCreateInfoEXT debugUtilsMessengerCreateInfoEXT{};
    debugUtilsMessengerCreateInfoEXT.messageSeverity = severityFlags;
    debugUtilsMessengerCreateInfoEXT.messageType = messageTypeFlags;
    debugUtilsMessengerCreateInfoEXT.pfnUserCallback = &debugCallback;
    // Create debug messenger
    m_DebugMessenger = m_NativeInstance.createDebugUtilsMessengerEXT( debugUtilsMessengerCreateInfoEXT );
  }
}