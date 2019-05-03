#!/bin/sh
if ! [ -d build ]; then
  cmake -H. -Bbuild -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=toolchain-i686-pc.cmake
fi
cmake --build build