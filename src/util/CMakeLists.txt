
add_library(
    util
    OBJECT
    file.cc
    gid.cc
    memory.cc
    log.cc
    config.cc
)

set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:util>
    PARENT_SCOPE)