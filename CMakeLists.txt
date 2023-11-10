# Copyright (C) 2022 Intel Corporation.  All rights reserved.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

cmake_minimum_required(VERSION 3.0)
project(vessel)


function(vessel_private_lib lib_name)
    add_library(${lib_name} STATIC ${ARGN})
    target_link_libraries(${lib_name} PUBLIC vessel::common_deps)
    add_library(vessel::${lib_name} ALIAS ${lib_name})
endfunction()
################ wasm application ###############
# -DWAMR_BUILD_BULK_MEMORY=1
# set(WAMR_BUILD_BULD_MEMORY 1) 

# include
set(WAMR_ROOT_DIR ${PROJECT_SOURCE_DIR}/third_party/wamr)
set(WAMR_SHARED_DIR ${WAMR_ROOT_DIR}/core/shared)
set(WAMR_IWASM_DIR ${WAMR_ROOT_DIR}/core/iwasm)
set(VESSEL_SRC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(VESSEL_THIRD_PARTY_INCLUDE_DIR
    ${WAMR_SHARED_DIR}/include
    ${WAMR_SHARED_DIR}/utils
    ${WAMR_IWASM_DIR}/include
    ${WAMR_IWASM_DIR}/common
)
include_directories(${VESSEL_SRC_INCLUDE_DIR})

set (CMAKE_EXPORT_COMPILE_COMMANDS 1)
add_subdirectory(src/wasmx)
add_subdirectory(wasm-app)
add_subdirectory(testcase)
add_subdirectory(tests/wasmx_test)
