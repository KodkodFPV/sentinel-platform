#pragma once

#include "sentinel/detail/log_core.hpp"


namespace sentinel::platform
{
  template <class... Args>
    inline void log_error(const char*, const char*, Args&&...)
    {

    }

  template <class... Args>
    inline void log_warning(const char*, const char*, Args&&...)
    {

    }

  template <class... Args>
    inline void log_info(const char*, const char*, Args&&...)
    {

    }

  template <class... Args>
    inline void log_error_isr(const char*, const char*, Args&&...)
    {

    }

  template <class... Args>
    inline void log_warning_isr(const char*, const char*, Args&&...)
    {

    }

  template <class... Args>
    inline void log_info_isr(const char*, const char*, Args&&...)
    {

    }
}
