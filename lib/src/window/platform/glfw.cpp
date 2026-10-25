#include "window/platform/GLFW.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>

GLFWWindowImpl::GLFWWindowImpl(const WindowProps& props)
{
  width = props.width;
  height = props.height;
  name = props.name;
}

void GLFWWindowImpl::init()
{
  if (m_WindowCount == 0)
  {
    if (!glfwInit()) { throw std::runtime_error("GLFW initialization failed"); }
  }

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  m_Handle = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

  if (m_Handle == nullptr)
  {
    throw std::runtime_error("Window was not created");
  }

  m_WindowCount++;



}

void GLFWWindowImpl::pollEvents()
{
  glfwPollEvents();
}

void GLFWWindowImpl::terminate() const
{
  glfwDestroyWindow(m_Handle);

  m_WindowCount--;

  if (m_WindowCount == 0)
  {
    glfwTerminate();
  }
}

bool GLFWWindowImpl::isOpen() const
{
  return !glfwWindowShouldClose(m_Handle);
}

inline void GLFWWindowImpl::setWidth(int w) { width = w; }
inline void GLFWWindowImpl::setHeight(int h) { height = h; }

const char** GLFWWindowImpl::getVulkanExtensions(uint32_t* count)
{
  return glfwGetRequiredInstanceExtensions(count);
}
