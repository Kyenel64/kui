/*
===============================================================================

    Log

===============================================================================
*/

#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace kui {

std::shared_ptr<spdlog::logger> Log::s_Logger;

void Log::init() {
  if (spdlog::get("KUI")) return;

  spdlog::set_pattern("%^[%T] %n: %v%$");

  s_Logger = spdlog::stdout_color_mt("KUI");
  s_Logger->set_level(spdlog::level::trace);
}

} // kui
