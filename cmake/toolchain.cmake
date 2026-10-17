set(VCPKG_PATH "$ENV{VCPKG_ROOT}")

if(NOT VCPKG_PATH)
  message(FATAL_ERROR "The VCPKG_ROOT environment variable is not defined!")
endif()

file(TO_CMAKE_PATH "${VCPKG_PATH}" VCPKG_PATH)

include("${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake")