#pragma once

/**
 * @file
 * @ingroup sentinel_platform_backend_esp
 *
 * @brief ESP-IDF logging backend.
 */

#include <utility>

#include "esp_log.h"

#include "sentinel/detail/log_core.hpp"


namespace sentinel::platform
{
  /**
   *
   * @brief Emits an error-level log message through `ESP_LOGE`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag ESP-IDF log tag.
   * @param format ESP-IDF log format string.
   * @param args Format arguments forwarded to `ESP_LOGE`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_error(const char* tag, const char* format, Args&&... args)
    {
      ESP_LOGE(tag, format, std::forward<Args>(args)...);
    }

  /**
   *
   * @brief Emits a warning-level log message through `ESP_LOGW`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag ESP-IDF log tag.
   * @param format ESP-IDF log format string.
   * @param args Format arguments forwarded to `ESP_LOGW`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_warning(const char* tag, const char* format, Args&&... args)
    {
      ESP_LOGW(tag, format, std::forward<Args>(args)...);
    }

  /**
   *
   * @brief Emits an info-level log message through `ESP_LOGI`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag ESP-IDF log tag.
   * @param format ESP-IDF log format string.
   * @param args Format arguments forwarded to `ESP_LOGI`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_info(const char* tag, const char* format, Args&&... args)
    {
      ESP_LOGI(tag, format, std::forward<Args>(args)...);
    }

  /**
   *
   * @brief Emits an ISR-safe error-level log message through `ESP_EARLY_LOGE`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag ESP-IDF log tag.
   * @param format ESP-IDF log format string.
   * @param args Format arguments forwarded to `ESP_EARLY_LOGE`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_error_isr(const char* tag, const char* format, Args&&... args)
    {
      ESP_EARLY_LOGE(tag, format, std::forward<Args>(args)...);
    }

  /**
   *
   * @brief Emits an ISR-safe warning-level log message through `ESP_EARLY_LOGW`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag ESP-IDF log tag.
   * @param format ESP-IDF log format string.
   * @param args Format arguments forwarded to `ESP_EARLY_LOGW`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_warning_isr(const char* tag, const char* format, Args&&... args)
    {
      ESP_EARLY_LOGW(tag, format, std::forward<Args>(args)...);
    }

  /**
   *
   * @brief Emits an ISR-safe info-level log message through `ESP_EARLY_LOGI`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag ESP-IDF log tag.
   * @param format ESP-IDF log format string.
   * @param args Format arguments forwarded to `ESP_EARLY_LOGI`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_info_isr(const char* tag, const char* format, Args&&... args)
    {
      ESP_EARLY_LOGI(tag, format, std::forward<Args>(args)...);
    }
}
