#include "window/Window.h"
#include "window/platform/GLFW.h"

IWindow::IWindow() = default;

int IWindow::getWidth() const { return width; }
int IWindow::getHeight() const { return height; }

void IWindow::setWidth(int w) { width = w; }
void IWindow::setHeight(int h) { height = h; }

std::shared_ptr<IWindow> IWindow::createWindow(const WindowProps& props)
{
  return std::make_shared<GLFWWindowImpl>(props);
}