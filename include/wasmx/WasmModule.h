#pragma once
#include <atomic>
#include <exception>
#include <mutex>
#include <string>
#include <sys/uio.h>
#include <thread>
#include <tuple>
#include <span>

#include "snapshot/snapshot.h"
#define WASM_BYTES_PER_PAGE 65536
#define MAX_WASM_MEM 4294901760 // 4 * 1024 * 1024 * 1024 - 64 * 1024

namespace wasm {

bool isWasmPageAligned(int32_t offset);

class WasmModule {
  public:
    WasmModule();

    // explicit WasmModule(int threadPoolSizeIn);

    virtual ~WasmModule();

    // ----- Module lifecycle -----

    // void bindToFunction(faabric::Message& msg, bool cache = true);

    // int32_t executeTask(int threadPoolIdx,
    //                     int msgIdx,
    //                     std::shared_ptr<faabric::BatchExecuteRequest> req);

    // 执行函数先用字符串传递数据，msg暂时为函数名
    // virtual int32_t executeFunction(std::string msg);
    bool isBound();

    void bindToFunction(const std::string& msg, bool cache = true);




    // ----- Memory management -----
    virtual uint8_t* wasmPointerToNative(uint32_t wasmPtr) = 0;

    virtual size_t getMemorySizeBytes() = 0;

    virtual size_t getMaxMemoryPages() = 0;

    virtual uint8_t* getMemoryBase() = 0;

    virtual void doBindToFunction(const std::string& msg, bool cache) = 0;


    // ----- Snapshot/ restore -----
    std::shared_ptr<snapshot::SnapshotData> getSnapshotData();

    std::span<uint8_t> getMemoryView();

    std::string snapshot(bool locallyRestorable = true);

    void restore(const std::string& snapshotKey);

    // ----- Debugging -----
    // virtual void printDebugInfo();

  protected:
    uint32_t current_brk_ = 0;
    bool isbound_ = false;


};

// Convenience functions
size_t getNumberOfWasmPagesForBytes(size_t nBytes);

uint32_t roundUpToWasmPageAligned(uint32_t nBytes);

size_t getPagesForGuardRegion();

/*
 * Exception thrown when wasm module terminates
 */
class WasmExitException : public std::exception
{
  public:
    explicit WasmExitException(int exitCode)
      : exitCode(exitCode)
    {}

    int exitCode;
};

}
