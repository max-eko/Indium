cmake_minimum_required(VERSION 4.3)

# Automatically loads vcpkg setup when project() is called
if(NOT DEFINED ENV{VCPKG_ROOT})
  message(FATAL_ERROR "The VCPKG_ROOT environment variable is not defined!")
endif()

file(TO_CMAKE_PATH "$ENV{VCPKG_ROOT}" VCPKG_PATH)
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(Indium)

set(CMAKE_CXX_STANDARD 20)
# Throw error if necessary environment variables are not set
if(NOT DEFINED ENV{VULKAN_SDK})
  message(FATAL_ERROR "The VULKAN_SDK environment variable is not set!")
endif()
# Utility Variables
set(LIB_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(EDITOR_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/editor)
set(VULKAN_PATH "$ENV{VULKAN_SDK}")
file(TO_CMAKE_PATH "${VULKAN_PATH}" VULKAN_PATH)
# Extra CMake scripts
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
# Dependencies
find_package(glfw3 CONFIG REQUIRED)

get_target_property(GLFW_INCLUDES glfw
  INTERFACE_INCLUDE_DIRECTORIES
)
message(STATUS "GLFW include directories: ${GLFW_INCLUDES}")

find_package(glm REQUIRED)
find_package(slang CONFIG HINTS "${VULKAN_PATH}/lib/cmake")
find_package (Vulkan 1.4.335 REQUIRED)

include(ModuleSupport)

# Indium Library
add_library(Indium)
target_sources(Indium
  PRIVATE
    ${LIB_ROOT}/src/logger/logger.cpp
    ${LIB_ROOT}/src/window/window.cpp
    ${LIB_ROOT}/src/render/context/render_context.cpp
    ${LIB_ROOT}/src/window/platform/glfw.cpp
  PRIVATE FILE_SET HEADERS
    BASE_DIRS ${LIB_ROOT}/src
    FILES
    ${LIB_ROOT}/src/logger/logger.h
    ${LIB_ROOT}/src/window/window.h
    ${LIB_ROOT}/src/render/context/render_context.h
    ${LIB_ROOT}/src/window/platform/glfw.h
)
target_include_directories(Indium PUBLIC ${LIB_ROOT}/src)
target_link_libraries(Indium
  PRIVATE
    glfw
)
# Indium Editor
add_executable(IndiumEngine)
target_sources(IndiumEngine
  PRIVATE
    ${EDITOR_ROOT}/src/main.cpp
    ${EDITOR_ROOT}/src/core/application.cpp
  PRIVATE FILE_SET HEADERS
    BASE_DIRS ${EDITOR_ROOT}/src
    FILES
      ${EDITOR_ROOT}/src/core/Application.h
)
target_link_libraries(IndiumEngine PRIVATE Indium)
