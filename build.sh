#!/bin/sh
if ! [ -d build ]; then
  cmake -G "CodeBlocks - Ninja" . -Bbuild
fi
cmake --build build
cp build/kirid kirid
