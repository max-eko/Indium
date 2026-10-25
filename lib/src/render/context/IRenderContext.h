#ifndef INDIUM_LIB_SRC_RENDER_RENDER_CONTEXT_H
#define INDIUM_LIB_SRC_RENDER_RENDER_CONTEXT_H

#include <memory>

#include "window/IWindow.h"

enum class RenderAPI {
  None = 0,
  OpenGL = 1,
  Vulkan = 2
};

class IContext
{
public:

  IContext() = default;
  virtual ~IContext() = default;

  virtual void init();
  virtual void bindWindow(IWindow& window);
  
  [[nodiscard]] virtual RenderAPI getRenderAPI() const;
  
  static std::shared_ptr<IContext> createContext();
};

#endif
