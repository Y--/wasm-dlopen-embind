# Build

```bash
$ ./build.sh
```

# Run

```bash
$ python3 -m http.server 8081
$ open http://localhost:8081/build/hello.html
```

# Current output in the console:

```
Starting side_func
Got typed_memory_view
hello.js:675 Aborted(Assertion failed: undefined symbol '_emval_take_value'. perhaps a side module was not linked in? if this global was expected to arrive from a system library, try to build the MAIN_MODULE with EMCC_FORCE_STDLIBS=1 in the environment)
[... stack ...]
hello.js:694 Uncaught (in promise) RuntimeError: Aborted(Assertion failed: undefined symbol '_emval_take_value'. perhaps a side module was not linked in? if this global was expected to arrive from a system library, try to build the MAIN_MODULE with EMCC_FORCE_STDLIBS=1 in the environment)
    at abort (hello.js:694:11)
    at assert (hello.js:368:5)
    at resolveSymbol (hello.js:1883:11)
    at stubs.<computed> (hello.js:1916:43)
    at b9fa315a:0x991
    at stubs.<computed> (hello.js:1920:33)
    at b9fa315a:0x8b7
    at hello.wasm:0x8e94a
    at hello.wasm:0x8e999
    at callMain (hello.js:38055:15)
```
