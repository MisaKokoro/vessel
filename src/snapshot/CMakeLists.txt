
add_library(
    snapshot
    OBJECT
    snapshot.cc
    snapshot_registry.cc
)

set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:snapshot>
    PARENT_SCOPE)
