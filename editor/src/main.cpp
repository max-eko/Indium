#include <cstdlib>

#include "core/application.h"

int main()
{
  Application m_App(640,480);
  if (!m_App.run())
  {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}