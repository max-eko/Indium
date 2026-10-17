#include "window/platform/GLFW.h"

GLFWWindowImpl::GLFWWindowImpl(const WindowProps& props)
{
  width = props.width;
  height = props.height;
  name = props.name;
}

bool GLFWWindowImpl::init()
{
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  handle = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

  if (handle == nullptr)
  {
    return false;
  }

  return true;
}

void GLFWWindowImpl::pollEvents()
{
  glfwPollEvents();
}

void GLFWWindowImpl::terminate() const
{
  glfwDestroyWindow(handle);
  glfwTerminate();
}

bool GLFWWindowImpl::isOpen() const
{
  return !glfwWindowShouldClose(handle);
}
