#include "core/application.h"

// Standard Library
#include <string>

// Core Library Headers
#include "logger/logger.h"

Application::Application(int w, int h) : window { IWindow::createWindow(WindowProps(w, h, "Indium Engine"))} {}

bool Application::run()
{
  logger = std::make_shared<Logger>();

  if (!init())
  {
    logger->Log("Engine initialization failed", Status::ERR);
    return false;
  }

  logger->Log("Engine running");

  while (window->isOpen())
  {
    if (!process())
    {
      logger->Log("Engine failed", Status::ERR);
      return false;
    }
  }

  if (!cleanup())
  {
    logger->Log("Engine cleanup failed", Status::ERR);
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
    logger->Log("Window creation failed!", Status::ERR);\
    return false;
  }

  logger->Log("Engine initialized", Status::INFO);

  return true;
}

bool Application::process()
{
  window->pollEvents();

  return true;
}

bool Application::cleanup()
{
  logger->Log("Engine cleaned up", Status::INFO);

  window->terminate();

  return true;
}

