#pragma once

/**
 * @file
 * @ingroup sentinel_platform_backend_none
 *
 * @brief No-op logging backend for targets without a log sink.
 */

#include "sentinel/detail/log_core.hpp"


namespace sentinel::platform
{
  /**
   *
   * @brief Discards an info-level log message.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_info(const char* tag, const char* format, Args&&... args)
    {
      static_cast<void>(tag);
      static_cast<void>(format);
      (static_cast<void>(args), ...);
    }

  /**
   *
   * @brief Discards an ISR-safe info-level log message.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_info_isr(const char* tag, const char* format, Args&&... args)
    {
      static_cast<void>(tag);
      static_cast<void>(format);
      (static_cast<void>(args), ...);
    }

  /**
   *
   * @brief Discards a warning-level log message.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_warning(const char* tag, const char* format, Args&&... args)
    {
      static_cast<void>(tag);
      static_cast<void>(format);
      (static_cast<void>(args), ...);
    }

  /**
   *
   * @brief Discards an ISR-safe warning-level log message.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_warning_isr(const char* tag, const char* format, Args&&... args)
    {
      static_cast<void>(tag);
      static_cast<void>(format);
      (static_cast<void>(args), ...);
    }

  /**
   *
   * @brief Discards an error-level log message.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_error(const char* tag, const char* format, Args&&... args)
    {
      static_cast<void>(tag);
      static_cast<void>(format);
      (static_cast<void>(args), ...);
    }

  /**
   *
   * @brief Discards an ISR-safe error-level log message.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_error_isr(const char* tag, const char* format, Args&&... args)
    {
      static_cast<void>(tag);
      static_cast<void>(format);
      (static_cast<void>(args), ...);
    }

  /**
   *
   * @brief Discards a debug-level log message.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_debug(const char* tag, const char* format, Args&&... args)
    {
      static_cast<void>(tag);
      static_cast<void>(format);
      (static_cast<void>(args), ...);
    }

  /**
   *
   * @brief Discards an ISR-safe debug-level log message.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_debug_isr(const char* tag, const char* format, Args&&... args)
    {
      static_cast<void>(tag);
      static_cast<void>(format);
      (static_cast<void>(args), ...);
    }

  /**
   *
   * @brief Discards a verbose-level log message.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_verbose(const char* tag, const char* format, Args&&... args)
    {
      static_cast<void>(tag);
      static_cast<void>(format);
      (static_cast<void>(args), ...);
    }

  /**
   *
   * @brief Discards an ISR-safe verbose-level log message.
   *
   * @tparam Args Format argument types.
   *
   * @param tag Platform log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    inline void log_verbose_isr(const char* tag, const char* format, Args&&... args)
    {
      static_cast<void>(tag);
      static_cast<void>(format);
      (static_cast<void>(args), ...);
    }
}
