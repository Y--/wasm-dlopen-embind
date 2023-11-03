#include <dlfcn.h>
#include <emscripten.h>
#include <stdio.h>

int main() {
  EM_ASM({
    const xhr = new XMLHttpRequest();
    xhr.open("GET", "side.wasm.b64", false);
    xhr.send(null);
    const uInt8Array = Uint8Array.from(atob(xhr.response), cpa);
    WebAssembly.validate(uInt8Array);
    FS.writeFile("side", new Uint8Array(uInt8Array));
    function cpa(m) { return m.codePointAt(0); }
  });

  auto lib_ptr = dlopen("side", RTLD_NOW | RTLD_LOCAL);
  auto func_ptr = dlsym(lib_ptr, "_Z9side_funcv");
  if (!func_ptr) {
    printf("Error: '%s'\n", dlerror());
    return 1;
  }

  printf("Got: %d\n", ((int (*)(void))func_ptr)());
  return 0;
}
