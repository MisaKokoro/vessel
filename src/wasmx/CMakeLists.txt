
add_library(
    wasmx
    OBJECT
    WamrManager.cc
    WAMRWasmModule.cc
    WasmModule.cc
)

set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:wasmx>
    PARENT_SCOPE)