#pragma once

#include <utility>

#include "esp_log.h"

#include "sentinel/detail/log_core.hpp"


namespace sentinel::platform
{
  template <class... Args>
    inline void log_error(const char* tag, const char* format, Args&&... args)
    {
      ESP_LOGE(tag, format, std::forward<Args>(args)...);
    }

  template <class... Args>
    inline void log_warning(const char* tag, const char* format, Args&&... args)
    {
      ESP_LOGW(tag, format, std::forward<Args>(args)...);
    }

  template <class... Args>
    inline void log_info(const char* tag, const char* format, Args&&... args)
    {
      ESP_LOGI(tag, format, std::forward<Args>(args)...);
    }

  template <class... Args>
    inline void log_error_isr(const char* tag, const char* format, Args&&... args)
    {
      ESP_EARLY_LOGE(tag, format, std::forward<Args>(args)...);
    }

  template <class... Args>
    inline void log_warning_isr(const char* tag, const char* format, Args&&... args)
    {
      ESP_EARLY_LOGW(tag, format, std::forward<Args>(args)...);
    }

  template <class... Args>
    inline void log_info_isr(const char* tag, const char* format, Args&&... args)
    {
      ESP_EARLY_LOGI(tag, format, std::forward<Args>(args)...);
    }
}
