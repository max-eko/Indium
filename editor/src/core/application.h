#ifndef INDIUM_EDITOR_SRC_CORE_APPLICATION_H
#define INDIUM_EDITOR_SRC_CORE_APPLICATION_H

// Standard Library
#include <memory>

// Core Library Headers
#include "render/context/IRenderContext.h"
#include "window/IWindow.h"

class Application
{
public:
  Application(int w, int h, const std::string& name);
  bool run();

private:
  void init();
  inline void process();
  void cleanup();

  std::shared_ptr<IWindow> window;
  std::unique_ptr<IContext> context;
};
#endif
