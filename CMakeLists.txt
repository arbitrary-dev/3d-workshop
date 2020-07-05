cmake_minimum_required (VERSION 3.14.6)
project(3D_WORKSHOP)

include_directories(inc)
add_subdirectory(src)

# ------------------------------------------------------------------------------
# SECTION: Google Test (gtest) unit testing framework
# ------------------------------------------------------------------------------
add_subdirectory(external/gtest EXCLUDE_FROM_ALL)

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

# ------------------------------------------------------------------------------
# SECTION: add unit tests
# ------------------------------------------------------------------------------
add_subdirectory(test)
