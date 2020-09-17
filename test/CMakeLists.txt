# ------------------------------------------------------------------------------
# SECTION: add unit tests
# ------------------------------------------------------------------------------
add_executable(runUnitTests
  vector.cpp
  matrix.cpp
)

target_link_libraries(runUnitTests
  Lib
  gtest
  gtest_main # TODO a custom main for tests with logging to stderr
)

add_test(Vector runUnitTests)
