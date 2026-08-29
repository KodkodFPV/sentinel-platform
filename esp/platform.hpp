#pragma once

/**
 * @file
 * @ingroup sentinel_platform_backend_esp
 *
 * @brief ESP-IDF logging backend.
 */

#include <utility>

#include "esp_log.h"

#include "error.hpp"

#include "sentinel/detail/log_core.hpp"


namespace sentinel::platform
{
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
      if constexpr (ESP_LOG_ENABLED(ESP_LOG_INFO))
      {
        esp_log(ESP_LOG_CONFIG_INIT(ESP_LOG_INFO | ESP_LOG_CONFIGS_DEFAULT), tag, ESP_LOG_ATTR_STR(format) ESP_LOG_ARGS(std::forward<Args>(args)...));
      }
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
      if constexpr (ESP_LOG_ENABLED(ESP_LOG_INFO))
      {
        esp_log(ESP_LOG_CONFIG_INIT(ESP_LOG_INFO | ESP_LOG_CONFIGS_DEFAULT | ESP_LOG_CONFIG_CONSTRAINED_ENV), tag, ESP_LOG_ATTR_STR(format) ESP_LOG_ARGS(std::forward<Args>(args)...));
      }
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
      if constexpr (ESP_LOG_ENABLED(ESP_LOG_WARN))
      {
        esp_log(ESP_LOG_CONFIG_INIT(ESP_LOG_WARN | ESP_LOG_CONFIGS_DEFAULT), tag, ESP_LOG_ATTR_STR(format) ESP_LOG_ARGS(std::forward<Args>(args)...));
      }
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
      if constexpr (ESP_LOG_ENABLED(ESP_LOG_WARN))
      {
        esp_log(ESP_LOG_CONFIG_INIT(ESP_LOG_WARN | ESP_LOG_CONFIGS_DEFAULT | ESP_LOG_CONFIG_CONSTRAINED_ENV), tag, ESP_LOG_ATTR_STR(format) ESP_LOG_ARGS(std::forward<Args>(args)...));
      }
    }

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
      if constexpr (ESP_LOG_ENABLED(ESP_LOG_ERROR))
      {
        esp_log(ESP_LOG_CONFIG_INIT(ESP_LOG_ERROR | ESP_LOG_CONFIGS_DEFAULT), tag, ESP_LOG_ATTR_STR(format) ESP_LOG_ARGS(std::forward<Args>(args)...));
      }
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
      if constexpr (ESP_LOG_ENABLED(ESP_LOG_ERROR))
      {
        esp_log(ESP_LOG_CONFIG_INIT(ESP_LOG_ERROR | ESP_LOG_CONFIGS_DEFAULT | ESP_LOG_CONFIG_CONSTRAINED_ENV), tag, ESP_LOG_ATTR_STR(format) ESP_LOG_ARGS(std::forward<Args>(args)...));
      }
    }

  /**
   *
   * @brief Emits a debug-level log message through `ESP_LOGD`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag ESP-IDF log tag.
   * @param format ESP-IDF log format string.
   * @param args Format arguments forwarded to `ESP_LOGD`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_debug(const char* tag, const char* format, Args&&... args)
    {
      if constexpr (ESP_LOG_ENABLED(ESP_LOG_DEBUG))
      {
        esp_log(ESP_LOG_CONFIG_INIT(ESP_LOG_DEBUG | ESP_LOG_CONFIGS_DEFAULT), tag, ESP_LOG_ATTR_STR(format) ESP_LOG_ARGS(std::forward<Args>(args)...));
      }
    }

  /**
   *
   * @brief Emits an ISR-safe debug-level log message through `ESP_EARLY_LOGD`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag ESP-IDF log tag.
   * @param format ESP-IDF log format string.
   * @param args Format arguments forwarded to `ESP_EARLY_LOGD`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_debug_isr(const char* tag, const char* format, Args&&... args)
    {
      if constexpr (ESP_LOG_ENABLED(ESP_LOG_DEBUG))
      {
        esp_log(ESP_LOG_CONFIG_INIT(ESP_LOG_DEBUG | ESP_LOG_CONFIGS_DEFAULT | ESP_LOG_CONFIG_CONSTRAINED_ENV), tag, ESP_LOG_ATTR_STR(format) ESP_LOG_ARGS(std::forward<Args>(args)...));
      }
    }

  /**
   *
   * @brief Emits a verbose-level log message through `ESP_LOGV`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag ESP-IDF log tag.
   * @param format ESP-IDF log format string.
   * @param args Format arguments forwarded to `ESP_LOGV`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_verbose(const char* tag, const char* format, Args&&... args)
    {
      if constexpr (ESP_LOG_ENABLED(ESP_LOG_VERBOSE))
      {
        esp_log(ESP_LOG_CONFIG_INIT(ESP_LOG_VERBOSE | ESP_LOG_CONFIGS_DEFAULT), tag, ESP_LOG_ATTR_STR(format) ESP_LOG_ARGS(std::forward<Args>(args)...));
      }
    }

  /**
   *
   * @brief Emits an ISR-safe verbose-level log message through `ESP_EARLY_LOGV`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag ESP-IDF log tag.
   * @param format ESP-IDF log format string.
   * @param args Format arguments forwarded to `ESP_EARLY_LOGV`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_verbose_isr(const char* tag, const char* format, Args&&... args)
    {
      if constexpr (ESP_LOG_ENABLED(ESP_LOG_VERBOSE))
      {
        esp_log(ESP_LOG_CONFIG_INIT(ESP_LOG_VERBOSE | ESP_LOG_CONFIGS_DEFAULT | ESP_LOG_CONFIG_CONSTRAINED_ENV), tag, ESP_LOG_ATTR_STR(format) ESP_LOG_ARGS(std::forward<Args>(args)...));
      }
    }
}
