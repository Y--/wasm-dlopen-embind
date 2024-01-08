#!/bin/bash

rm -rf build
mkdir build
cd build



emcc -v ../main.cc  \
  -s WASM=1 \
  -lembind \
  -sMAIN_MODULE=2 \
  -O3 \
  -sEXPORTED_FUNCTIONS='[_main,_malloc,_free,_printf,__ZTVN10__cxxabiv117__class_type_infoE,__emval_take_value,__emval_decref,__ZTIv,_pthread_self,__ZTIN10emscripten11memory_viewIhEE,__ZTSN10emscripten11memory_viewIhEE]' \
  -sDEFAULT_LIBRARY_FUNCS_TO_INCLUDE=_emval_take_value \
  -o hello.html \
  --shell-file ../template.html

emcc -v ../side.cc \
  -sSIDE_MODULE \
  -s LINKABLE=1 \
  -o side.wasm

base64 -i side.wasm -o side.wasm.b64

ls -l hello.js