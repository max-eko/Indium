#ifndef INDIUM_LIB_SRC_RENDER_CONTEXT_PLATFORM_VULKAN_VKRENDERCONTEXT
#define INDIUM_LIB_SRC_RENDER_CONTEXT_PLATFORM_VULKAN_VKRENDERCONTEXT

#include <vulkan/vulkan.hpp>

#include "render/context/RenderContext.h"

class VkRenderContextImpl : public IContext {
public:
  VkRenderContextImpl();
  [[nodiscard]] RenderAPI getRenderAPI() const override { return RenderAPI::Vulkan; }
private:

};

#endif
