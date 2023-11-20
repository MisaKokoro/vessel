#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdexcept>

#include "util/file.h"

namespace util {

std::vector<uint8_t> readFileToBytes(const std::string& path) {
    int fd = open(path.c_str(), O_RDONLY);
    if (fd < 0) {
        throw std::runtime_error("Couldn't open file " + path);
    }

    struct stat statbuf;
    int staterr = fstat(fd, &statbuf);
    if (staterr < 0) {
        throw std::runtime_error("Couldn't stat file " + path);
    }

    size_t fsize = statbuf.st_size;
    // posix_fadvise 是一个 POSIX 标准中定义的函数，用于对文件进行存取模式（access pattern）的建议。
    posix_fadvise(fd, 0, 0, POSIX_FADV_SEQUENTIAL);
    std::vector<uint8_t> result;
    result.resize(fsize);
    int cpos = 0;
    while (cpos < fsize) {
        int rc = read(fd, result.data(), fsize - cpos);
        if (rc < 0) {
            perror("Couldn't read file");
            throw std::runtime_error("Couldn't read file " + path);
        } else {
            cpos += rc;
        }
    }
    close(fd);
    
    return result;
}

}