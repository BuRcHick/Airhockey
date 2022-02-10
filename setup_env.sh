#!/usr/bin/env bash

export PROJECT_ROOT="$(pwd)"

export SDL2="${PROJECT_ROOT}/external/libs/SDL2"
export SDL2_CONFIG="${SDL2}/sdl2-config"

export SDL2_image="${PROJECT_ROOT}/external/libs/SDL2_image"
export SDL2_ttf="${PROJECT_ROOT}/external/libs/SDL2_ttf"

export SDL2_libs="${SDL2}/build/.libs"
export SDL2_image_libs="${SDL2_image}/.libs"
export SDL2_ttf_libs="${SDL2_ttf}/.libs"

export XML="${PROJECT_ROOT}/external/libs/xml"
