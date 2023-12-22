set (CMAKE_C_FLAGS                  "${CMAKE_C_FLAGS} -D_WASI_EMULATED_MMAN")
add_executable(test_mmap.wasm main.c)
target_link_libraries(test_mmap.wasm -lwasi-emulated-mman)