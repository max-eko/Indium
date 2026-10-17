#include <cstdlib>

#include "core/Application.h"

int main()
{
  Application app(640, 480, "Indium Engine");
  if (!app.run())
  {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}