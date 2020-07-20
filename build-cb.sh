#!/bin/zsh

cmake -B build -S . -G "CodeBlocks - Unix Makefiles" --trace-source=CMakeLists.txt --trace-expand
cmake --build build
