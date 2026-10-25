#ifndef INDIUM_LIB_SRC_WINDOW_WINDOW_H
#define INDIUM_LIB_SRC_WINDOW_WINDOW_H

#include <string>
#include <memory>

#include "RenderSurface.h"

struct WindowProps
{
  int width;
  int height;
  std::string name;
};

class IWindow : public IRenderSurface
{
public:
  IWindow() = default;
  ~IWindow() override = default;

  virtual void init() = 0;
  virtual void pollEvents() = 0;
  virtual void terminate() const = 0;

  [[nodiscard]] int getWidth() const { return width; }
  [[nodiscard]] int getHeight() const { return height; }
  [[nodiscard]] std::string getName() const { return name;}

  inline virtual void setWidth(int w) = 0;
  inline virtual void setHeight(int h) = 0;

  [[nodiscard]] virtual bool isOpen() const = 0;

  static std::shared_ptr<IWindow> createWindow(const WindowProps& props);

protected:
  int width;
  int height;
  std::string name;
};

#endif
