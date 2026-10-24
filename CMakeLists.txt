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
find_package(glm CONFIG REQUIRED)
find_package(slang CONFIG HINTS "${VULKAN_PATH}/Lib/cmake")
find_package (Vulkan 1.4 MODULE REQUIRED)

include(ModuleSupport)

# Indium Library
add_library(Indium)
target_sources(Indium
  PRIVATE
    ${LIB_ROOT}/src/logger/Logger.cpp
    ${LIB_ROOT}/src/window/Window.cpp
    ${LIB_ROOT}/src/render/context/RenderContext.cpp
    ${LIB_ROOT}/src/window/platform/GLFW.cpp
    ${LIB_ROOT}/src/render/context/platform/vulkan/VkRenderContextImpl.cpp
  PRIVATE FILE_SET HEADERS
    BASE_DIRS ${LIB_ROOT}/src
    FILES
    ${LIB_ROOT}/src/logger/Logger.h
    ${LIB_ROOT}/src/window/Window.h
    ${LIB_ROOT}/src/render/context/RenderContext.h
    ${LIB_ROOT}/src/window/platform/GLFW.h
    ${LIB_ROOT}/src/render/context/platform/vulkan/VkRenderContextImpl.h
)
target_include_directories(Indium PUBLIC ${LIB_ROOT}/src)
target_link_libraries(Indium
  PRIVATE
    glfw
    Vulkan::Vulkan
)
# Indium Editor
add_executable(IndiumEngine)
target_sources(IndiumEngine
  PRIVATE
    ${EDITOR_ROOT}/src/main.cpp
    ${EDITOR_ROOT}/src/core/Application.cpp
  PRIVATE FILE_SET HEADERS
    BASE_DIRS ${EDITOR_ROOT}/src
    FILES
      ${EDITOR_ROOT}/src/core/Application.h
)
target_link_libraries(IndiumEngine PRIVATE Indium)
