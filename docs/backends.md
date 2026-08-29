# Backends

@ingroup sentinel_platform_backends

Bundled backends are intentionally small. They provide only the functions required by
@ref sentinel_platform_contract "the backend contract".

| Backend | Target | Header | Behavior |
| ------- | ------ | ------ | -------- |
| `none` | `sentinel::platform_none` | `none/platform.hpp` | Accepts every log call and emits nothing. |
| `stderr` | `sentinel::platform_stderr` | `stderr/platform.hpp` | Prints severity, tag, formatted text, and newline to `stderr`. |
| `esp` | `sentinel::platform_esp` | `esp/platform.hpp` | Forwards normal and ISR logs to `esp_log` with the matching ESP-IDF severity. |

## none

@ingroup sentinel_platform_backend_none

The `none` backend is useful when a target has no available logging transport or when logs must be
compiled against the same API but intentionally dropped.

## stderr

@ingroup sentinel_platform_backend_stderr

The `stderr` backend is intended for hosted/native builds. It uses `std::fprintf` and therefore
requires a C runtime with `stderr`.

## esp

@ingroup sentinel_platform_backend_esp

The `esp` backend is intended for ESP-IDF builds. It includes `esp_log.h` directly and expects the
consumer build to expose ESP-IDF headers before compiling code that includes the selected backend.
