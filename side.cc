#include <emscripten.h>
#include <emscripten/val.h>
#include <stdio.h>

EMSCRIPTEN_KEEPALIVE int side_func() {
  printf("Starting side_func\n");
  uint8_t buffer[1] = {0};
  auto tmv = emscripten::typed_memory_view(1, buffer);
  printf("Got typed_memory_view\n");
  emscripten::val memory_view = emscripten::val(tmv);
  printf("created mem_view\n");
  return 42;
}