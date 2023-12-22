#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>


#define LENGTH 1000

int main() {
    int fd;
    char str[LENGTH + 1]; // +1 用于存放字符串结束符 '\0'
    int i;

    // 用于生成随机种子
    srand(time(NULL));

    // 生成随机字符串
    for (i = 0; i < LENGTH; ++i) {
        str[i] = 'A' + (rand() % 26); // 生成随机字母（A-Z）
    }
    str[LENGTH] = '\0'; // 添加字符串结束符

    // 打开文件
    struct timeval start_time;
    struct timeval end_time;
    gettimeofday(&start_time, NULL);
    for (int i = 0; i < 1000; i++) {
        fd = open("a.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }

        // 写入文件
        if (write(fd, str, LENGTH) == -1) {
            perror("Error writing to file");
            close(fd);
            return EXIT_FAILURE;
        }

        // 关闭文件
        close(fd);
    }
    gettimeofday(&end_time, NULL);

    long elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + end_time.tv_usec - start_time.tv_usec;
    printf("open and close use %ld us\n", elapsed_time);
    printf("Successfully wrote to file a.txt\n");

    return EXIT_SUCCESS;
}
