#include "util/config.h"
#include "util/log.h"
namespace util {
SystemConfig& getSystemConfig() {
    static SystemConfig conf;
    return conf;
}

SystemConfig::SystemConfig() {
    this->initialise();
}

void SystemConfig::initialise() {
    log_level = "debug";
    wasm_memory_mode = "pool";
}

void SystemConfig::print() {
    SPDLOG_INFO("log level : {}", log_level);
    SPDLOG_INFO("wasm memory mode : {}", wasm_memory_mode);
}


}