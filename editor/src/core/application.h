#ifndef INDIUM_EDITOR_SRC_CORE_APPLICATION_H
#define INDIUM_EDITOR_SRC_CORE_APPLICATION_H

// Standard Library
#include <memory>

// Core Library Headers
#include "logger/logger.h"
#include "window/window.h"
#include "render/context/render_context.h"

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
