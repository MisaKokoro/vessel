#include "util/gid.h"
namespace util {
unsigned int generateGid() {
    return ++gid;
}
}