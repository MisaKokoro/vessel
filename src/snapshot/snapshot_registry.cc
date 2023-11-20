#include "snapshot/snapshot_registry.h"
#include  "util/log.h"

namespace snapshot {


std::shared_ptr<SnapshotData> SnapshotRegistry::getSnapshot(
  const std::string& key) {

    if (key.empty()) {
        SPDLOG_ERROR("Attempting to get snapshot with empty key");
        throw std::runtime_error("Getting snapshot with empty key");
    }

    if (snapshot_map_.find(key) == snapshot_map_.end()) {
        SPDLOG_ERROR("Snapshot for {} does not exist", key);
        throw std::runtime_error("Snapshot doesn't exist");
    }

    return snapshot_map_[key];
}

bool SnapshotRegistry::snapshotExists(const std::string& key) {
    return snapshot_map_.find(key) != snapshot_map_.end();
}

void SnapshotRegistry::registerSnapshot(
  const std::string& key,
  std::shared_ptr<SnapshotData> data) {

    SPDLOG_DEBUG("Registering snapshot {} size {} max {}",
                 key,
                 data->getSize(),
                 data->getMaxSize());

    snapshot_map_.insert_or_assign(key, std::move(data));
}

void SnapshotRegistry::deleteSnapshot(const std::string& key) {
    SPDLOG_DEBUG("Deleting snapshot {}", key);
    snapshot_map_.erase(key);
}

size_t SnapshotRegistry::getSnapshotCount() {
    return snapshot_map_.size();
}

void SnapshotRegistry::clear() {
    SPDLOG_DEBUG("Deleting all snapshots");
    snapshot_map_.clear();
}

SnapshotRegistry& getSnapshotRegistry() {
    static SnapshotRegistry reg;
    return reg;
}

}