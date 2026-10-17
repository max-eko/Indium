#include "core/Application.h"

// Standard Library
#include <string>

// Core Library Headers
#include "logger/Logger.h"

Application::Application(int w, int h, const std::string& name) : window { IWindow::createWindow(WindowProps(w, h, name))} {}

bool Application::run()
{
  logger::init();

  if (!init())
  {
    logger::log("Engine initialization failed", Status::ERR);
    return false;
  }

  logger::log("Engine running");

  while (window->isOpen())
  {
    if (!process())
    {
      logger::log("Engine failed", Status::ERR);
      return false;
    }
  }

  if (!cleanup())
  {
    logger::log("Engine cleanup failed", Status::ERR);
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
    logger::log("Window creation failed!", Status::ERR);\
    return false;
  }

  logger::log("Engine initialized", Status::INFO);

  return true;
}

inline bool Application::process()
{
  window->pollEvents();

  return true;
}

bool Application::cleanup()
{
  logger::log("Engine cleaned up", Status::INFO);

  window->terminate();

  return true;
}

