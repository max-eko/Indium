#ifndef INDIUM_LIB_SRC_RENDER_CONTEXT_PLATFORM_VULKAN_VKDEBUGUTIL_H
#define INDIUM_LIB_SRC_RENDER_CONTEXT_PLATFORM_VULKAN_VKDEBUGUTIL_H

#include <vulkan/vulkan.hpp>

static VKAPI_ATTR vk::Bool32 VKAPI_CALL debugCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT severity, vk::DebugUtilsMessageTypeFlagsEXT type, const vk::DebugUtilsMessengerCallbackDataEXT * pCallbackData, void* pUserData);

#endif
