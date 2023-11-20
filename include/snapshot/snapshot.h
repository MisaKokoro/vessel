#pragma once
#include "util/memory.h"

namespace snapshot {
class SnapshotData {
public:
    SnapshotData() = default;

    explicit SnapshotData(size_t sizeIn);

    SnapshotData(size_t sizeIn, size_t maxSizeIn);

    explicit SnapshotData(std::span<const uint8_t> dataIn);

    SnapshotData(std::span<const uint8_t> dataIn, size_t maxSizeIn);

    SnapshotData(const SnapshotData&) = delete;

    SnapshotData& operator=(const SnapshotData&) = delete;

    ~SnapshotData();

    void mapToMemory(std::span<uint8_t> target);


    size_t getSize() const { return size_; }

    size_t getMaxSize() const { return max_size_; }
private:
    // void mapToMemory(uint8_t* target, bool shared);

    void writeData(std::span<const uint8_t> buffer, uint32_t offset = 0);

    uint8_t* validatedOffsetPtr(uint32_t offset);
private:
    int fd_;
    util::MemoryRegion data_;
    size_t size_ = 0;
    size_t max_size_ = 0;
};

}