add_library(Lib
  vector.cpp
  matrix.cpp
)

target_link_libraries(Lib
  glog::glog
)
