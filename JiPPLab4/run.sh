#!/bin/bash

if [ ! -d './build' ]; then
    echo `mkdir build`
fi

if [ -f "CMakeLists.txt" ]; then
    echo `cmake -B build`
    exit
fi