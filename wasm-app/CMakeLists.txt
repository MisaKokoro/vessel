cmake_minimum_required(VERSION 3.20)
project(wasm-app)

set(WASI_SDK_DIR "/opt/wasi-sdk")
set(CMAKE_CXX_COMPILER "${WASI_SDK_DIR}/bin/clang++")
set(CMAKE_C_COMPILER "${WASI_SDK_DIR}/bin/clang")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fno-exceptions -z stack-size=409600")
## 不导出malloc和free函数会导致生成的wasm文件的page size 不是 64KB，然后会导致WAMRWasmModule.cc:186代码判断出错
set (CMAKE_CXX_FLAGS                  "${CMAKE_CXX_FLAGS} -Wl,--export=malloc")
set (CMAKE_CXX_FLAGS                  "${CMAKE_CXX_FLAGS} -Wl,--export=free")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nostdlib -Wl,--no-entry -Wl,--allow-undefined")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -z stack-size=409600")
set (CMAKE_C_FLAGS                  "${CMAKE_C_FLAGS} -Wl,--export=malloc")
set (CMAKE_C_FLAGS                  "${CMAKE_C_FLAGS} -Wl,--export=free")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -nostdlib -Wl,--no-entry -Wl,--allow-undefined")

# set(CMAKE_BUILD_TYPE "Release")

# include_directories("/usr/local/include")
add_subdirectory(testc)
file(GLOB SUBDIR_LIST RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/ ${CMAKE_CURRENT_SOURCE_DIR}/test_*)

# 遍历匹配到的目录，使用 add_subdirectory 将它们添加到当前项目中
foreach(subdir ${SUBDIR_LIST})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
        add_subdirectory(${subdir})
    endif()
endforeach()