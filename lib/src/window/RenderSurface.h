#ifndef INDIUM_LIB_SRC_WINDOW_RENDERSURFACE_H
#define INDIUM_LIB_SRC_WINDOW_RENDERSURFACE_H

class IRenderSurface {
public:
  IRenderSurface() = default;
  virtual ~IRenderSurface();
  
  virtual void bindSwapchain() = 0;
};

#endif