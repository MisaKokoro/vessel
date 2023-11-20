#include <vector>
#include <span>

#include "snapshot/snapshot.h"
#include "util/log.h"
#include "util/macros.h"

#define MEM_SIZE 4096
using namespace snapshot;
using namespace util;
int main() {
    std::vector<uint8_t> origin_data(4096);
    for (int i = 0; i < 100; i++) {
        origin_data[i] = i;
    }
    std::span<uint8_t> linear_mem(origin_data);
    
    // 创建一个快照
    SnapshotData snapshot(linear_mem);

    // 从快照中恢复数据
    auto restore_data = allocateVirtualMemory(MEM_SIZE);
    uint8_t *memory_base = restore_data.get();
    std::span<uint8_t> restore_mem = {memory_base, MEM_SIZE};
    snapshot.mapToMemory(restore_mem);

    for (int i = 0; i < 101; i++) {
        SPDLOG_INFO("{}", memory_base[i]);
    }

    // 先为快照申请内存
    // int size = MEM_SIZE;
    // auto data = allocateVirtualMemory(size);
    // claimVirtualMemory({ BYTES(data.get()), size });
    // int memfd = createFd(MEM_SIZE, "memfd_for_test");
    // mapMemoryShared({ data.get(), size }, memfd);

    // // 然后把线性内存中的内容写入快照
    // size_t regionEnd = linear_mem.size();
    // uint8_t* copyTarget = data.get();
    // ::memcpy(copyTarget, linear_mem.data(), linear_mem.size());

    // // 从快照中恢复数据

    // mapMemoryPrivate(restore_mem, memfd);



    return 0;

}