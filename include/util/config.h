#pragma once

#include <string>

namespace util {
class SystemConfig {
public:
    SystemConfig();
    void print();
public:
    std::string log_level;
    std::string wasm_memory_mode;
private:
    void initialise();
};

SystemConfig& getSystemConfig();
}