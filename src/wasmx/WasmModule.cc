#include "wasmx/WasmModule.h"
#include "util/gid.h"
#include "snapshot/snapshot_registry.h"
#include "util/log.h"

namespace wasm {

WasmModule::WasmModule() {}

WasmModule::~WasmModule() {}
bool WasmModule::isBound() {
    return isbound_;
}

void WasmModule::bindToFunction(const std::string& msg, bool cache/*=true*/) {
    if (isbound_) {
        throw std::runtime_error("Cannot bind a module twice");
    }

    isbound_ = true;
    doBindToFunction(msg, cache);
}

std::shared_ptr<snapshot::SnapshotData> WasmModule::getSnapshotData() {
    uint8_t* mem_base = getMemoryBase();
    size_t current_size = current_brk_;
    size_t max_size = MAX_WASM_MEM;

    auto snap = std::make_shared<snapshot::SnapshotData>(
        std::span<const uint8_t>(mem_base, current_size), 
        max_size);

    return snap;
}

std::span<uint8_t> WasmModule::getMemoryView() {
    uint8_t* memBase = getMemoryBase();
    size_t currentSize = current_brk_;
    return std::span<uint8_t>(memBase, currentSize);
}

std::string WasmModule::snapshot(bool locallyRestorable) {
    uint32_t gid = util::generateGid();
    std::string snapKey = "wamr_" + std::to_string(gid);

    std::shared_ptr<snapshot::SnapshotData> data = getSnapshotData();

    snapshot::SnapshotRegistry& reg = snapshot::getSnapshotRegistry();
    reg.registerSnapshot(snapKey, data);

    return snapKey;
}

void WasmModule::restore(const std::string& snapshotKey) {
    if (!isBound()) {
        SPDLOG_ERROR("Must bind wasm module before restoring snapshot {}",
                     snapshotKey);
        throw std::runtime_error("Cannot restore unbound wasm module");
    }

    snapshot::SnapshotRegistry& reg = snapshot::getSnapshotRegistry();

    // Expand memory if necessary
    auto data = reg.getSnapshot(snapshotKey);
    // setMemorySize(data->getSize());

    // Map the snapshot into memory
    uint8_t* memoryBase = getMemoryBase();
    data->mapToMemory({ memoryBase, data->getSize() });
}


}