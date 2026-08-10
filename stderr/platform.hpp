#pragma once

#include <cstdio>
#include <utility>

#include "sentinel/detail/log_core.hpp"


namespace sentinel::platform
{
  template <class... Args>
    inline void log_error(const char* tag, const char* format, Args&&... args)
    {
      std::fprintf(stderr, "[error] %s: ", tag);
      std::fprintf(stderr, format, std::forward<Args>(args)...);
      std::fprintf(stderr, "\n");
    }

  template <class... Args>
    inline void log_warning(const char* tag, const char* format, Args&&... args)
    {
      std::fprintf(stderr, "[warning] %s: ", tag);
      std::fprintf(stderr, format, std::forward<Args>(args)...);
      std::fprintf(stderr, "\n");
    }

  template <class... Args>
    inline void log_info(const char* tag, const char* format, Args&&... args)
    {
      std::fprintf(stderr, "[info] %s: ", tag);
      std::fprintf(stderr, format, std::forward<Args>(args)...);
      std::fprintf(stderr, "\n");
    }

  template <class... Args>
    inline void log_error_isr(const char* tag, const char* format, Args&&... args)
    {
      log_error(tag, format, std::forward<Args>(args)...);
    }

  template <class... Args>
    inline void log_warning_isr(const char* tag, const char* format, Args&&... args)
    {
      log_warning(tag, format, std::forward<Args>(args)...);
    }

  template <class... Args>
    inline void log_info_isr(const char* tag, const char* format, Args&&... args)
    {
      log_info(tag, format, std::forward<Args>(args)...);
    }
}
