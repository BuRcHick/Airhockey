#!/usr/bin/env bash

cd $SDL2
./configure
make clean all

cd $PROJECT_ROOT
cd $SDL2_image
./configure CPPFLAGS="-I${SDL2}/include" LDFLAGS="-L${SDL2_libs}"
make clean all

cd $PROJECT_ROOT
cd $SDL2_ttf
./configure CPPFLAGS="-I${SDL2}/include" LDFLAGS="-L${SDL2_libs}"
make clean all

cd $PROJECT_ROOT
mkdir build
cd $PROJECT_ROOT/build
cmake ../
make
