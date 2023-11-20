include(FindGit)
find_package(Git REQUIRED)
include(FetchContent)

#------------- 将所有的第三方包, 全部打包成一个依赖库 ------------------------
# 创建一个INTERFACE库，一个INTERFACE库不会直接创建编译目标文件, 与下面的INTERFACE并不是同一概念
add_library(common_dependencies INTERFACE)
#----------------------- SpdLog ------------------------------------
#cmake -DSPDLOG_BUILD_ALL=false -DSPDLOG_BUILD_SHARED=false -DSPDLOG_ENABLE_PCH=false -DSPDLOG_BUILD_EXAMPLE_HO=false -DSPDLOG_BUILD_TESTS_HO=false -DSPDLOG_BUILD_BENCH=false -DSPDLOG_SANITIZE_ADDRESS=false -DSPDLOG_BUILD_WARNINGS=false ..
find_package(spdlog QUIET)
if (NOT spdlog_FOUND)
    message("SpdLog not found. Downloading it from source...")
    FetchContent_Declare(
            spdlog
            GIT_REPOSITORY https://github.com/gabime/spdlog.git
            GIT_TAG v1.9.2
            GIT_SHALLOW true
    )
    set(SPDLOG_BUILD_ALL OFF CACHE BOOL "")
    set(SPDLOG_BUILD_SHARED OFF CACHE BOOL "")
    set(SPDLOG_ENABLE_PCH OFF CACHE BOOL "")
    set(SPDLOG_BUILD_EXAMPLE_HO OFF CACHE BOOL "")
    set(SPDLOG_BUILD_TESTS_HO OFF CACHE BOOL "")
    set(SPDLOG_BUILD_BENCH OFF CACHE BOOL "")
    set(SPDLOG_SANITIZE_ADDRESS OFF CACHE BOOL "")
    set(SPDLOG_BUILD_WARNINGS OFF CACHE BOOL "")

    FetchContent_MakeAvailable(spdlog)
endif ()
# INTERFACE 表示, coroutine_wasm::common_dependencies本身不会链接后面一系列的库及其头文件,
# 而链接coroutine_wasm::common_dependencies的库或者可执行程序会链接这些库及其头文件,
# INTERFACE与PRIVATE的效果刚好相反. 而PUBLIC则是两者都会链接库及其头文件.
# 详见https://blog.csdn.net/weixin_43862847/article/details/119762230
target_link_libraries(common_dependencies INTERFACE spdlog)

add_library(vessel::common_dependencies ALIAS common_dependencies)