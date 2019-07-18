#!/bin/bash

FILES=$(find ./kernel -type f \( -name '*.h' -o -name '*.c' \))
echo $FILES
clang-format -i ${FILES}