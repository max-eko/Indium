#ifndef INDIUM_EDITOR_SRC_CORE_APPLICATION_H
#define INDIUM_EDITOR_SRC_CORE_APPLICATION_H

// Standard Library
#include <memory>

// Core Library Headers
#include "window/Window.h"
#include "render/context/RenderContext.h"

class Application
{
public:
  Application(int w, int h, const std::string& name);
  bool run();

private:
  bool init();
  inline bool process();
  bool cleanup();

  std::shared_ptr<IWindow> window;
  std::unique_ptr<IContext> context;
};
#endif
