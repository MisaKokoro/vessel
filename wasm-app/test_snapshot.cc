#include <stdio.h>

int data[1024] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};

extern "C" {
__attribute__((export_name("get_data_addr")))
int* get_data_addr() {
    return data;
}

__attribute__((export_name("mod_data")))
void mod_data() {
    for (int i = 0; i < 10; i++) {
        data[i] = 10 - i;
    }
}

__attribute__((export_name("show_data")))
void show_data() {
    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
}

int main() {
    return 0;
}

