#ifndef INDIUM_LIB_SRC_RENDER_CONTEXT_PLATFORM_VULKAN_VKRENDERCONTEXTIMPL
#define INDIUM_LIB_SRC_RENDER_CONTEXT_PLATFORM_VULKAN_VKRENDERCONTEXTIMPL

#include <vulkan/vulkan_raii.hpp>

#include <string>

#include "render/context/IRenderContext.h"

class VkRenderContextImpl : public IContext {
public:
  VkRenderContextImpl(const std::string& name);

  void init() override;
  [[nodiscard]] RenderAPI getRenderAPI() const override { return RenderAPI::Vulkan; }
private:
  std::string m_AppName;
  vk::raii::Instance m_NativeInstance = nullptr;
  vk::raii::Context m_NativeContext;

};

#endif
