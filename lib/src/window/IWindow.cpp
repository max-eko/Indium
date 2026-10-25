#include "window/IWindow.h"
#include "window/platform/GLFWWindowImpl.h"

void IWindow::setWidth(int w) { width = w; }
void IWindow::setHeight(int h) { height = h; }

std::shared_ptr<IWindow> IWindow::createWindow(const WindowProps& props)
{
  return std::make_shared<GLFWWindowImpl>(props);
}