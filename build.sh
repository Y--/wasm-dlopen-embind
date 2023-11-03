#!/bin/bash

rm -rf build
mkdir build
cd build

emcc ../main.cc  -s MAIN_MODULE -s WASM=1 -o hello.html --shell-file ../template.html

emcc ../side.cc -s SIDE_MODULE -s LINKABLE=1 -o side.wasm

base64 -i side.wasm -o side.wasm.b64