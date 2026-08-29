#pragma once

/**
 * @file
 * @ingroup sentinel_platform_backend_esp
 *
 * @brief ESP-IDF error adapter for sentinel checks and logs.
 */

#include <cstdint>

#include "esp_err.h"

#include "sentinel/error_traits.hpp"


namespace sentinel::platform::esp
{
  struct error
  {
    esp_err_t code;
  };

  inline error err(esp_err_t code)
  {
    return {code};
  }
}

namespace sentinel
{
  template <>
    struct error_traits<platform::esp::error>
    {
      static bool failed(platform::esp::error err)
      {
        return err.code != ESP_OK;
      }

      static const char* message(platform::esp::error err)
      {
        return esp_err_to_name(err.code);
      }

      static std::int32_t value(platform::esp::error err)
      {
        return static_cast<std::int32_t>(err.code);
      }
    };
}
