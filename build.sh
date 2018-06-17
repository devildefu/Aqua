#!/bin/sh
if ! [ -d build ] & ! [ -d build/i686 ]; then  
  mkdir build
  mkdir build/i686
elif ! [ -d build/i686 ]; then
  mkdir build/i686
fi
make
