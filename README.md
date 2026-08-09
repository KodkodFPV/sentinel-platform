# sentinel-platform
sentinel-platform provides pluggable platform backends for the sentinel C++ diagnostics library. It contains logging sinks and platform-specific status adapters, such as stderr/native, ESP-IDF, and no-op backends, while keeping the core sentinel library free of OS, RTOS, SDK, and vendor dependencies.
