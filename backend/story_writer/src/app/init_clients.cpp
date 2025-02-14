#include "init_clients.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace
{
    void init_logger()
    {
        // Create separate sinks for stdout (normal logs) and stderr (errors)
        auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>(); // Colored stdout
        auto stderr_sink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>(); // Colored stderr

        // Set log level for each sink
        stdout_sink->set_level(spdlog::level::debug); // Everything else (info, debug, warn)
        stderr_sink->set_level(spdlog::level::err);   // Only errors and critical logs

        // Create a logger with both sinks
        const auto logger = std::make_shared<spdlog::logger>(
            "global_logger",
            spdlog::sinks_init_list{stdout_sink, stderr_sink});

        // Set the logger as the default global logger
        spdlog::set_default_logger(logger);

        // Optional: Set overall log level (controls filtering)
        spdlog::set_level(spdlog::level::debug); // Show all logs (debug, info, warning, etc.)

        // Optional: Set log pattern (adjust as needed)
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");
        // Example: "[2025-02-01 12:34:56.789] [INFO] Message"
    }
} // namespace

void app::init_clients()
{
    init_logger();
    spdlog::info("[app::init_clients] successfully initialized all clients");
}
