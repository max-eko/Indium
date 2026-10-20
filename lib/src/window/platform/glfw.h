#ifndef INDIUM_LIB_SRC_WINDOW_PLATFORM_GLFW_H
#define INDIUM_LIB_SRC_WINDOW_PLATFORM_GLFW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

#include "window/Window.h"


class GLFWWindowImpl: public IWindow
{
public:
  GLFWWindowImpl(const WindowProps& props);
  ~GLFWWindowImpl() override = default;

  bool init() override;
  void pollEvents() override;
  void terminate() const override;

  inline void setWidth(int w) override;
  inline void setHeight(int h) override;
  
  [[nodiscard]] bool isOpen() const override;

private:
  GLFWwindow* handle = nullptr;
};

#endif
