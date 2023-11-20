add_subdirectory(snapshot)
add_subdirectory(util)
add_subdirectory(wasmx)

add_library(vessel STATIC ${ALL_OBJECT_FILES})

set(VESSEL_LIBS
    util
    snapshot
    wasmx        
)

set(VESSEL_THIRDPARTY_LIBS
    wamr
    # vessel::common_dependencies
    spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>
)

target_link_libraries(
    vessel
    PRIVATE
    ${VESSLE_LIBS}
    ${VESSEL_THIRDPARTY_LIBS}
)

# message("a ${VESSEL_THIRD_PARTY_INCLUDE_DIR}")
# message("b ${VESSEL_SRC_INCLUDE_DIR}")

target_include_directories(
    vessel
    PUBLIC
    ${VESSEL_THIRD_PARTY_INCLUDE_DIR}
    ${VESSEL_SRC_INCLUDE_DIR}
)