#!/usr/bin/env bash

if [ ! -d "$SDL2/build" ]
then
    echo "Start configuring $SDL2"
    cd $SDL2
    ./configure
    make clean all
    cd $PROJECT_ROOT
fi
echo "$SDL2 succesfully configured"

if [ ! -d "$SDL2_image/.libs" ]
then
    echo "Start configuring $SDL2_image"
    cd $SDL2_image
    ./configure CPPFLAGS="-I${SDL2}/include" LDFLAGS="-L${SDL2_libs}"
    make clean all
    cd $PROJECT_ROOT
fi
echo "$SDL2_image succesfully configured"

if [ ! -d "$SDL2_ttf/.libs" ]
then
    echo "Start configuring $SDL2_ttf"
    cd $SDL2_ttf
    ./configure CPPFLAGS="-I${SDL2}/include" LDFLAGS="-L${SDL2_libs}"
    make clean all
    cd $PROJECT_ROOT
fi
echo "$SDL2_ttf succesfully configured"

if [ ! -d "$XML_PARSER/build" ]
then
    echo "Start configuring $XML_PARSER"
    cd $XML_PARSER
    mkdir $XML_PARSER/build
    cd $XML_PARSER/build
    cmake ../ -DCXML_BUILD_SHARED_LIB=ON
    make clean all
    cd $PROJECT_ROOT
fi
echo "$XML_PARSER succesfully configured"

if [ ! -d "$PROJECT_ROOT/external/include" ]
then
    mkdir -p "$PROJECT_ROOT/external/include/SDL2"
    mkdir -p "$PROJECT_ROOT/external/include/parser"
    ln -s ${SDL2}/include/*\.h external/include/SDL2/
    ln -s ${SDL2_image}/*\.h external/include/SDL2/
    ln -s ${SDL2_ttf}/*\.h external/include/SDL2/
    ln -s ${XML_PARSER}/include/* external/include/parser
fi

if [ ! -d "$PROJECT_ROOT/build" ]
then
    mkdir build
    cd $PROJECT_ROOT/build
    cmake ../ -DCMAKE_EXPORT_COMPILE_COMMANDS=1                                                                         \
        -DCMAKE_LIBRARY_PATH="$SDL2/build/.libs;$SDL2_image/.libs;$SDL2_ttf/.libs;$XML_PARSER/build"                                      \
        -DCMAKE_BUILD_TYPE=Debug
fi

cd $PROJECT_ROOT/build
make clean all
