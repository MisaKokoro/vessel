#include "struct.h"

// some helper types
using Buffer = std::vector<uint8_t>;
using OutputAdapter = bitsery::OutputBufferAdapter<Buffer>;
using InputAdapter = bitsery::InputBufferAdapter<Buffer>;
extern "C" {
int bitsery_arr_sum(uint8_t* buf, int size) {
    MyVector res;
    Buffer buffer(buf, buf + size);
    int sum = 0;
    auto state = bitsery::quickDeserialization<InputAdapter>({buffer.begin(), static_cast<size_t>(size)}, res);
    for (int d : res.vec) {
        sum += d * d;
    }
    return sum;
}
}

int main()
{
    return 0;
}