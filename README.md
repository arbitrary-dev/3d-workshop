# 3D workshop in C++

```
cmake -G Ninja -S . -B build -D CMAKE_EXPORT_COMPILE_COMMANDS=1 \
  && ln -s build/compile_commands.json
cd build
ninja && test\runUnitTests
```
