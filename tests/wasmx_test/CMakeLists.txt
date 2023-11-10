set(WASMX_TEST_SOURCES main.cc)
add_executable(wamrTest ${WASMX_TEST_SOURCES})

target_link_libraries(wamrTest wamrlib wasmx)
# set_target_properties(shell PROPERTIES OUTPUT_NAME bustub-shell)
