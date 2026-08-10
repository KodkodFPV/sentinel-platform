@mainpage sentinel-platform

@tableofcontents

`sentinel-platform` contains the selected `platform.hpp` implementation used by `sentinel`.
Each backend exports the same `sentinel::platform` logging API while keeping SDK-specific includes
and log sinks outside the core library.

The package does not auto-select a backend. The consuming build sets `SENTINEL_PLATFORM` and links
the resulting backend target through `sentinel`.

@section sentinel_platform_main_modules Modules

- @ref sentinel_platform_contract "Backend Contract": functions every backend must provide.
- @ref sentinel_platform_backends "Backends": behavior of the bundled `none`, `stderr`, and `esp` backends.
- @ref sentinel_platform_cmake "CMake Integration": backend selection and documentation generation.

@section sentinel_platform_main_selection Backend Selection

@code{.cmake}
set(SENTINEL_PLATFORM stderr CACHE STRING "" FORCE)
add_subdirectory(sentinel-platform)
@endcode

The selected backend provides `platform.hpp` on its include path.

@section sentinel_platform_main_docs Documentation

@code{.cmake}
set(SENTINEL_PLATFORM_BUILD_DOCS ON CACHE BOOL "" FORCE)
@endcode

The `sentinel-platform.docs` target runs Doxygen and writes HTML documentation into the CMake
build tree.

@defgroup sentinel_platform_public Public API

@brief Stable backend API consumed by `sentinel`.

@defgroup sentinel_platform_contract Backend Contract
@ingroup sentinel_platform_public

@brief Required `sentinel::platform` logging functions.

@defgroup sentinel_platform_backends Backends
@ingroup sentinel_platform_public

@brief Bundled backend implementations.

@defgroup sentinel_platform_backend_none none Backend
@ingroup sentinel_platform_backends

@brief No-op backend for targets without a usable log sink.

@defgroup sentinel_platform_backend_stderr stderr Backend
@ingroup sentinel_platform_backends

@brief Native backend that prints messages to `stderr`.

@defgroup sentinel_platform_backend_esp esp Backend
@ingroup sentinel_platform_backends

@brief ESP-IDF backend that forwards messages to ESP logging macros.

@defgroup sentinel_platform_cmake CMake Integration
@ingroup sentinel_platform_public

@brief Build-system contract for selecting and exposing one backend.
