# Backend Contract

@ingroup sentinel_platform_contract

A backend is a directory that contains `platform.hpp`. When selected through
`SENTINEL_PLATFORM`, that directory is added to the include path and `sentinel` includes:

@code{.cpp}
#include "platform.hpp"
@endcode

The header must define the logging API in `sentinel::platform`.

@code{.cpp}
namespace sentinel::platform
{
  /**
   *
   * @brief Emits an info-level log message.
   *
   * @tparam Args Format argument types accepted by the backend.
   *
   * @param tag Backend log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    void log_info(const char* tag, const char* format, Args&&... args);

  /**
   *
   * @brief Emits an ISR-safe info-level log message.
   *
   * @tparam Args Format argument types accepted by the backend.
   *
   * @param tag Backend log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    void log_info_isr(const char* tag, const char* format, Args&&... args);

  /**
   *
   * @brief Emits a warning-level log message.
   *
   * @tparam Args Format argument types accepted by the backend.
   *
   * @param tag Backend log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    void log_warning(const char* tag, const char* format, Args&&... args);

  /**
   *
   * @brief Emits an ISR-safe warning-level log message.
   *
   * @tparam Args Format argument types accepted by the backend.
   *
   * @param tag Backend log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    void log_warning_isr(const char* tag, const char* format, Args&&... args);

  /**
   *
   * @brief Emits an error-level log message.
   *
   * @tparam Args Format argument types accepted by the backend.
   *
   * @param tag Backend log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    void log_error(const char* tag, const char* format, Args&&... args);

  /**
   *
   * @brief Emits an ISR-safe error-level log message.
   *
   * @tparam Args Format argument types accepted by the backend.
   *
   * @param tag Backend log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    void log_error_isr(const char* tag, const char* format, Args&&... args);

  /**
   *
   * @brief Emits a debug-level log message.
   *
   * @tparam Args Format argument types accepted by the backend.
   *
   * @param tag Backend log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    void log_debug(const char* tag, const char* format, Args&&... args);

  /**
   *
   * @brief Emits an ISR-safe debug-level log message.
   *
   * @tparam Args Format argument types accepted by the backend.
   *
   * @param tag Backend log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    void log_debug_isr(const char* tag, const char* format, Args&&... args);

  /**
   *
   * @brief Emits a verbose-level log message.
   *
   * @tparam Args Format argument types accepted by the backend.
   *
   * @param tag Backend log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    void log_verbose(const char* tag, const char* format, Args&&... args);

  /**
   *
   * @brief Emits an ISR-safe verbose-level log message.
   *
   * @tparam Args Format argument types accepted by the backend.
   *
   * @param tag Backend log tag.
   * @param format Backend-defined format string.
   * @param args Format arguments.
   *
   * @note Returns no value.
   */
  template <class... Args>
    void log_verbose_isr(const char* tag, const char* format, Args&&... args);
}
@endcode

The format string contract is owned by the backend. Bundled backends use printf-style formatting
because both `stderr` and ESP-IDF logging macros follow that convention.
