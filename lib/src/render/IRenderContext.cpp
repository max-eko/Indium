#include "IRenderContext.h"

#include "platform/vulkan/VkRenderContextImpl.h"

static std::shared_ptr<IContext> createContext(IRenderSurface& renderSurface)
{
  return std::make_shared<VkRenderContextImpl>(renderSurface);
};