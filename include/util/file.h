#pragma once
#include <vector>
#include <string>
namespace util {
std::vector<uint8_t> readFileToBytes(const std::string& path);
}