#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/time.h>

int main() {
    struct timeval start_time, end_time;
    long elapsed_time;

    size_t size = 4096;  // 分配的内存大小为 4KB

    // 获取开始时间
    gettimeofday(&start_time, NULL);

    void *addr;

    // 使用 mmap 分配内存
    for (int i = 0; i < 10000; i++) {
        addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (addr == MAP_FAILED) {
            perror("mmap");
            exit(EXIT_FAILURE);
        }
    }

    // 获取结束时间
    gettimeofday(&end_time, NULL);

    // 计算时间差并打印
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + 
                   (end_time.tv_usec - start_time.tv_usec);
    printf("Time taken by mmap: %ld us\n", elapsed_time);

    // 解除内存映射
    if (munmap(addr, size) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    return 0;
}
