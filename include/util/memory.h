#pragma once

#include <cstdint>
#include <functional>
#include <memory>
#include <span>
#include <string>
#include <unistd.h>
#include <vector>

namespace util {
/*
 * Typedef used to enforce RAII on mmapped memory regions
 */
typedef std::unique_ptr<uint8_t[], std::function<void(uint8_t*)>> MemoryRegion;

static const long HOST_PAGE_SIZE = sysconf(_SC_PAGESIZE);

// -------------------------
// Allocation
// -------------------------

MemoryRegion allocatePrivateMemory(size_t size);

MemoryRegion allocateSharedMemory(size_t size);

MemoryRegion allocateVirtualMemory(size_t size);

void claimVirtualMemory(std::span<uint8_t> region);

void mapMemoryPrivate(std::span<uint8_t> target, int fd);

void mapMemoryShared(std::span<uint8_t> target, int fd);

void resizeFd(int fd, size_t size);

void writeToFd(int fd, off_t offset, std::span<const uint8_t> data);

int createFd(size_t size, const std::string& fdLabel);

void appendDataToFd(int fd, std::span<uint8_t> data);

}