#!/usr/bin/env bash

export PROJECT_ROOT="$(pwd)"

export SDL2="${PROJECT_ROOT}/external/SDL"
export SDL2_CONFIG="${PROJECT_ROOT}/external/SDL/sdl2-config"

export SDL2_image="${PROJECT_ROOT}/external/SDL_image"
export SDL2_ttf="${PROJECT_ROOT}/external/SDL_ttf"

export SDL2_libs="${SDL2}/build/.libs"
export SDL2_image_libs="${SDL2_image}/.libs"
export SDL2_ttf_libs="${SDL2_ttf}/.libs"
