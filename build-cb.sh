#!/bin/zsh

cmake -B build -S . -G "CodeBlocks - Unix Makefiles"
cmake --build build
