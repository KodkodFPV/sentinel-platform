# CMake Integration

@ingroup sentinel_platform_cmake

`sentinel-platform` is selected explicitly. There is no default backend because embedded targets
often have project-specific logging requirements.

@code{.cmake}
set(SENTINEL_PLATFORM none CACHE STRING "" FORCE)
add_subdirectory(sentinel-platform)
@endcode

`SENTINEL_PLATFORM` must name a backend directory that contains `platform.hpp`.

The generated target name is:

@code{.cmake}
platform_${SENTINEL_PLATFORM}
@endcode

An alias is also exported:

@code{.cmake}
sentinel::platform_${SENTINEL_PLATFORM}
@endcode

For example, selecting `stderr` creates `platform_stderr` and `sentinel::platform_stderr`.

## Documentation Target

Enable generated documentation with:

@code{.cmake}
set(SENTINEL_PLATFORM_BUILD_DOCS ON CACHE BOOL "" FORCE)
@endcode

Then build:

@code{.bash}
cmake --build <build-dir> --target sentinel-platform.docs
@endcode
