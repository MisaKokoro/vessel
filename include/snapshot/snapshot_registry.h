#pragma once

#include <shared_mutex>
#include <string>
#include <unordered_map>


#include "snapshot/snapshot.h"

namespace snapshot {

class SnapshotRegistry {
  public:
    SnapshotRegistry() = default;

    std::shared_ptr<SnapshotData> getSnapshot(
      const std::string& key);

    bool snapshotExists(const std::string& key);

    void registerSnapshot(const std::string& key,
                          std::shared_ptr<SnapshotData> data);

    void deleteSnapshot(const std::string& key);

    size_t getSnapshotCount();

    void clear();

  private:
    std::unordered_map<std::string,
                       std::shared_ptr<SnapshotData>> snapshot_map_;

    // std::shared_mutex snapshotsMx;

    int writeSnapshotToFd(const std::string& key,
                          SnapshotData& data);
};

SnapshotRegistry& getSnapshotRegistry();

}
