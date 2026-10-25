#ifndef INDIUM_LIB_SRC_WINDOW_RENDERSURFACE_H
#define INDIUM_LIB_SRC_WINDOW_RENDERSURFACE_H

class IRenderSurface {
public:
  IRenderSurface() = default;
  virtual ~IRenderSurface() = default;
  
  virtual const char** getVulkanExtensions(uint32_t* count) = 0;
};

#endif