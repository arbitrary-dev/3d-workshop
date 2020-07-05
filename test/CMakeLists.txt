# ------------------------------------------------------------------------------
# SECTION: add unit tests
# ------------------------------------------------------------------------------
add_executable(runUnitTests
  vector.cpp
)

target_link_libraries(runUnitTests
  Lib
  gtest
  gtest_main
)

add_test(Vector runUnitTests)
