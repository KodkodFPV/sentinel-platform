#pragma once

/**
 * @file
 * @ingroup sentinel_platform_backend_stderr
 *
 * @brief `stderr` logging backend for native and hosted targets.
 */

#include <utility>
#include <cstdio>

#include "sentinel/detail/log_core.hpp"


namespace sentinel::platform
{
  /**
   *
   * @brief Emits an info-level log message to `stderr`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag printed after the severity label.
   * @param format `std::fprintf`-compatible format string.
   * @param args Format arguments forwarded to `std::fprintf`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_info(const char* tag, const char* format, Args&&... args)
    {
      std::fprintf(stderr, "[info] %s: ", tag);
      std::fprintf(stderr, format, std::forward<Args>(args)...);
      std::fprintf(stderr, "\n");
    }

  /**
   *
   * @brief Emits an ISR-safe info-level log message to `stderr`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag printed after the severity label.
   * @param format `std::fprintf`-compatible format string.
   * @param args Format arguments forwarded to `std::fprintf`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_info_isr(const char* tag, const char* format, Args&&... args)
    {
      log_info(tag, format, std::forward<Args>(args)...);
    }

  /**
   *
   * @brief Emits a warning-level log message to `stderr`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag printed after the severity label.
   * @param format `std::fprintf`-compatible format string.
   * @param args Format arguments forwarded to `std::fprintf`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_warning(const char* tag, const char* format, Args&&... args)
    {
      std::fprintf(stderr, "[warning] %s: ", tag);
      std::fprintf(stderr, format, std::forward<Args>(args)...);
      std::fprintf(stderr, "\n");
    }

  /**
   *
   * @brief Emits an ISR-safe warning-level log message to `stderr`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag printed after the severity label.
   * @param format `std::fprintf`-compatible format string.
   * @param args Format arguments forwarded to `std::fprintf`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_warning_isr(const char* tag, const char* format, Args&&... args)
    {
      log_warning(tag, format, std::forward<Args>(args)...);
    }

  /**
   *
   * @brief Emits an error-level log message to `stderr`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag printed after the severity label.
   * @param format `std::fprintf`-compatible format string.
   * @param args Format arguments forwarded to `std::fprintf`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_error(const char* tag, const char* format, Args&&... args)
    {
      std::fprintf(stderr, "[error] %s: ", tag);
      std::fprintf(stderr, format, std::forward<Args>(args)...);
      std::fprintf(stderr, "\n");
    }

  /**
   *
   * @brief Emits an ISR-safe error-level log message to `stderr`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag printed after the severity label.
   * @param format `std::fprintf`-compatible format string.
   * @param args Format arguments forwarded to `std::fprintf`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_error_isr(const char* tag, const char* format, Args&&... args)
    {
      log_error(tag, format, std::forward<Args>(args)...);
    }

  /**
   *
   * @brief Emits a debug-level log message to `stderr`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag printed after the severity label.
   * @param format `std::fprintf`-compatible format string.
   * @param args Format arguments forwarded to `std::fprintf`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_debug(const char* tag, const char* format, Args&&... args)
    {
      std::fprintf(stderr, "[debug] %s: ", tag);
      std::fprintf(stderr, format, std::forward<Args>(args)...);
      std::fprintf(stderr, "\n");
    }

  /**
   *
   * @brief Emits an ISR-safe debug-level log message to `stderr`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag printed after the severity label.
   * @param format `std::fprintf`-compatible format string.
   * @param args Format arguments forwarded to `std::fprintf`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_debug_isr(const char* tag, const char* format, Args&&... args)
    {
      log_debug(tag, format, std::forward<Args>(args)...);
    }

  /**
   *
   * @brief Emits a verbose-level log message to `stderr`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag printed after the severity label.
   * @param format `std::fprintf`-compatible format string.
   * @param args Format arguments forwarded to `std::fprintf`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_verbose(const char* tag, const char* format, Args&&... args)
    {
      std::fprintf(stderr, "[verbose] %s: ", tag);
      std::fprintf(stderr, format, std::forward<Args>(args)...);
      std::fprintf(stderr, "\n");
    }

  /**
   *
   * @brief Emits an ISR-safe verbose-level log message to `stderr`.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag printed after the severity label.
   * @param format `std::fprintf`-compatible format string.
   * @param args Format arguments forwarded to `std::fprintf`.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_verbose_isr(const char* tag, const char* format, Args&&... args)
    {
      log_verbose(tag, format, std::forward<Args>(args)...);
    }
}
