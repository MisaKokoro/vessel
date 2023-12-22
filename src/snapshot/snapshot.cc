#include "snapshot/snapshot.h"
#include "util/log.h"

using namespace util;
namespace snapshot {

SnapshotData::SnapshotData(size_t sizeIn) : SnapshotData(sizeIn, sizeIn) {}

SnapshotData::SnapshotData(size_t sizeIn, size_t maxSizeIn)
    : size_(sizeIn), max_size_(maxSizeIn) {
    if (max_size_ == 0) {
        max_size_ = size_;
    }

    data_ = allocateVirtualMemory(max_size_);
    std::string fd_label = "snap_" + std::to_string(std::rand());
    fd_ = createFd(size_, fd_label);
    mapMemoryShared({data_.get(), size_}, fd_);
}

SnapshotData::SnapshotData(std::span<const uint8_t> dataIn)
  : SnapshotData(dataIn.size()) {
    writeData(dataIn);
}

SnapshotData::SnapshotData(std::span<const uint8_t> dataIn, size_t maxSizeIn)
  : SnapshotData(dataIn.size(), maxSizeIn) {
    writeData(dataIn);
}

SnapshotData::~SnapshotData() {
    if (fd_ > 0) {
        SPDLOG_TRACE("Closing fd {}", fd_);
        ::close(fd_);
        fd_ = -1;
    }
}
uint8_t* SnapshotData::validatedOffsetPtr(uint32_t offset) {
    if (offset > size_) {
        SPDLOG_ERROR("Out of bounds snapshot access: {} > {}", offset, size_);
        throw std::runtime_error("Out of bounds snapshot access");
    }

    return data_.get() + offset;
}

void SnapshotData::writeData(std::span<const uint8_t> buffer, uint32_t offset/*= 0*/) {
    size_t regionEnd = offset + buffer.size();
    // Copy in new data
    uint8_t* copyTarget = validatedOffsetPtr(offset);
    ::memcpy(copyTarget, buffer.data(), buffer.size());
}

void SnapshotData::mapToMemory(std::span<uint8_t> target) {
    // Note we only need a shared lock here as we are not modifying data and the
    // OS will handle synchronisation of the mapping itself

    if (target.size() > size_) {
        SPDLOG_ERROR("Mapping target memory larger than snapshot ({} > {})",
                     target.size(),
                     size_);
        throw std::runtime_error("Target memory larger than snapshot");
    }

    mapMemoryPrivate(target, fd_);
}


}