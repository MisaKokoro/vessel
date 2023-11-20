# Copyright (C) 2022 Intel Corporation.  All rights reserved.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

cmake_minimum_required(VERSION 3.20)
project(vessel)
set(CMAKE_CXX_STANDARD 20)
include(cmake/ExternalProjects.cmake)





function(vessel_private_lib lib_name)
    add_library(${lib_name} STATIC ${ARGN})
    target_link_libraries(${lib_name} PUBLIC vessel::common_deps)
    add_library(vessel::${lib_name} ALIAS ${lib_name})
endfunction()
################ wasm application ###############
# -DWAMR_BUILD_BULK_MEMORY=1
# set(WAMR_BUILD_BULD_MEMORY 1) 

# include
## WASM相关
set(WAMR_ROOT_DIR ${PROJECT_SOURCE_DIR}/third_party/wamr)
set(WAMR_SHARED_DIR ${WAMR_ROOT_DIR}/core/shared)
set(WAMR_IWASM_DIR ${WAMR_ROOT_DIR}/core/iwasm)
set(VESSEL_SRC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
## SPDLOG相关
set(VESSEL_SPDLOG_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/third_party/spdlog/include)
set(VESSEL_THIRD_PARTY_INCLUDE_DIR
    ${WAMR_SHARED_DIR}/include
    ${WAMR_SHARED_DIR}/utils
    ${WAMR_IWASM_DIR}/include
    ${WAMR_IWASM_DIR}/aot
    ${WAMR_IWASM_DIR}/common
    ${WAMR_SHARED_DIR}/utils/uncommon
    ${WAMR_SHARED_DIR}/platform/include
## 按理说这里不需要加这个linux的包含目录也应该能够编译
    ${WAMR_SHARED_DIR}/platform/linux
    ${VESSEL_SPDLOG_INCLUDE_DIR}
)

include_directories(${VESSEL_SRC_INCLUDE_DIR} ${VESSEL_THIRD_PARTY_INCLUDE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(src)
add_subdirectory(wasm-app)
add_subdirectory(testcase)
add_subdirectory(tests/module_test)
add_subdirectory(tests/wasmx_test)
add_subdirectory(third_party)


