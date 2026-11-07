#include "VkDebugUtil.h"

#include <logger/Logger.h>

#include <vulkan/vulkan.hpp>

VKAPI_ATTR vk::Bool32 VKAPI_CALL debugCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT severity, vk::DebugUtilsMessageTypeFlagsEXT type, const vk::DebugUtilsMessengerCallbackDataEXT * pCallbackData, void* pUserData)
{
  if (severity == vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning || severity == vk::DebugUtilsMessageSeverityFlagBitsEXT::eError)
  {
    logger::log("Validation layer: type " + vk::to_string(type) + " msg " + pCallbackData->pMessage, Status::ERR);
  }
  return vk::False;
}