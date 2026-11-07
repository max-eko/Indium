#ifndef INDIUM_LIB_SRC_WINDOW_RENDERSURFACE_H
#define INDIUM_LIB_SRC_WINDOW_RENDERSURFACE_H

#include <string>

class IRenderSurface {
public:
  IRenderSurface() = default;
  virtual ~IRenderSurface() = default;

  virtual void init() = 0;

  [[nodiscard]] std::string getName() const { return name; }
  [[nodiscard]] int getWidth() const { return width; }
  [[nodiscard]] int getHeight() const { return height; }

  virtual const char** getVulkanExtensions(uint32_t* count) = 0;
protected:
  int width;
  int height;
  std::string name;
};

#endif