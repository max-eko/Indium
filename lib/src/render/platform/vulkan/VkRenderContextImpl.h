#ifndef INDIUM_LIB_SRC_RENDER_CONTEXT_PLATFORM_VULKAN_VKRENDERCONTEXTIMPL
#define INDIUM_LIB_SRC_RENDER_CONTEXT_PLATFORM_VULKAN_VKRENDERCONTEXTIMPL

#include <vulkan/vulkan_raii.hpp>

#include "render/IRenderContext.h"

class VkRenderContextImpl : public IContext {
public:
  VkRenderContextImpl();
  void init() override;
  [[nodiscard]] RenderAPI getRenderAPI() const override { return RenderAPI::Vulkan; }
private:
  IRenderSurface& m_RenderSurface;
  vk::raii::Instance m_NativeInstance = nullptr;
  vk::raii::Context m_NativeContext;

  // Validation layer related debug utils
  vk::raii::DebugUtilsMessengerEXT m_DebugMessenger;
  inline static std::vector<char const*> m_ValidationLayers = {
    "VK_LAYER_KHRONOS_validation"
  };
 // Defaults to validation layers being enabled on a Debug build and disabled on a Release build
#if !defined(NDEBUG) || defined(_DEBUG) || defined(DEBUG)
  inline static bool enableValidationLayers = true;
#else
  inline static bool enableValidationLayers = false;
#endif

  // Extension related params
  uint32_t extensionCount;
  std::vector<const char*> enabledExtensions;

  // Helper methods for init()
  void setupDebugMessenger();
  void checkForValidationLayers();
  void getRequiredExtensions();
};

#endif
