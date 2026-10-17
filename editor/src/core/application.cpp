#include "core/application.h"

// Standard Library
#include <string>

// Core Library Headers
#include "logger/logger.h"

Application::Application(int w, int h) : window { IWindow::createWindow(WindowProps(w, h, "Indium Engine"))} {}

bool Application::run()
{
  if (!init())
  {
    log::log("Engine initialization failed", Status::ERR);
    return false;
  }

  log::log("Engine running");

  while (window->isOpen())
  {
    if (!process())
    {
      log::log("Engine failed", Status::ERR);
      return false;
    }
  }

  if (!cleanup())
  {
    log::log("Engine cleanup failed", Status::ERR);
    return false;
  }

  return true;
}

bool Application::init()
{
  WindowProps props = {
    640,
    480,
    std::string("Indium Engine")
  };
  window = IWindow::createWindow(props);

  if (!window->init())
  {
    log::log("Window creation failed!", Status::ERR);\
    return false;
  }

  log::log("Engine initialized", Status::INFO);

  return true;
}

inline bool Application::process()
{
  window->pollEvents();

  return true;
}

bool Application::cleanup()
{
  log::log("Engine cleaned up", Status::INFO);

  window->terminate();

  return true;
}

