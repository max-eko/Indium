#include "core/Application.h"

// Standard Library
#include <string>

// Core Library Headers
#include "logger/Logger.h"

Application::Application(int w, int h, const std::string& name) : window { IWindow::createWindow(WindowProps(w, h, name))} {}

bool Application::run()
{
  logger::init();

  try { init(); }
  catch (const std::exception& e)
  {
    logger::log(e.what(), Status::ERR);
    return false;
  }

  logger::log("Engine running");

  while (window->isOpen())
  {
    try { process(); }
    catch ( const std::exception& e) {
      logger::log(e.what(), Status::ERR);

      try { cleanup(); }
      catch (const std::exception& err)
      {
        logger::log(err.what(), Status::ERR);
        return false;
      }

      return false;
    }
  }

  try { cleanup(); }
  catch (const std::exception& e)
  {
    logger::log(e.what(), Status::ERR);
    return false;
  }

  return true;
}

void Application::init()
{
  WindowProps props = {
    640,
    480,
    std::string("Indium Engine")
  };
  window = IWindow::createWindow(props);

  try { window->init(); }
  catch (const std::exception& e) { throw e; }

  logger::log("Engine initialized", Status::INFO);
}

inline void Application::process()
{
  window->pollEvents();
}

void Application::cleanup()
{
  logger::log("Engine cleaned up", Status::INFO);

  window->terminate();
}

