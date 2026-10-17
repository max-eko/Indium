#ifndef INDIUM_LIB_SRC_WINDOW_WINDOW_H
#define INDIUM_LIB_SRC_WINDOW_WINDOW_H

#include <string>
#include <memory>

struct WindowProps
{
  int width;
  int height;
  std::string name;
};

class IWindow
{
public:
  IWindow();
  virtual ~IWindow() = default;

  virtual bool init() = 0;
  virtual void pollEvents() = 0;
  virtual void terminate() const = 0;

  [[nodiscard]] int getWidth() const;
  [[nodiscard]] int getHeight() const;
  void setWidth(int w);
  void setHeight(int h);

  [[nodiscard]] virtual bool isOpen() const = 0;

  static std::shared_ptr<IWindow> createWindow(const WindowProps& props);
protected:
  int width;
  int height;
  std::string name;
};

#endif
