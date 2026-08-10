# sentinel-platform

`sentinel-platform` provides pluggable platform backends for the `sentinel` C++ diagnostics
library. It contains logging sinks and platform-specific status adapters, such as stderr/native,
ESP-IDF, and no-op backends, while keeping the core `sentinel` library free of OS, RTOS, SDK,
and vendor dependencies.

## CMake

`SENTINEL_PLATFORM` selects exactly one backend:

```cmake
set(SENTINEL_PLATFORM stderr CACHE STRING "" FORCE)
add_subdirectory(sentinel-platform)
```

The selected backend exports `platform.hpp` through its include directory.

## Backends

- `sentinel::platform_none`
- `sentinel::platform_stderr`
- `sentinel::platform_esp` when configured under ESP-IDF

## Documentation

The Doxygen documentation target is optional:

```cmake
set(SENTINEL_PLATFORM_BUILD_DOCS ON CACHE BOOL "" FORCE)
```

Build the generated HTML documentation with:

```bash
cmake --build <build-dir> --target sentinel-platform.docs
```
