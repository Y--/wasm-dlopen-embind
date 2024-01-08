# Build

```bash
$ ./build.sh
```

# Run

```bash
$ python3 svr.py
$ open http://localhost:8081/build/hello.html
```

# Current output in the console:

```
Starting side_func
hello.js:1 Got typed_memory_view
hello.js:1 Uncaught (in promise) TypeError: Cannot read properties of undefined (reading 'apply')
    at stubs.<computed> (hello.js:1:19547)
    at d2c5c7ca:0xa56
    at stubs.<computed> (hello.js:1:19547)
    at d2c5c7ca:0x971
    at hello.wasm:0x5a4f
    at callMain (hello.js:1:95427)
    at doRun (hello.js:1:95813)
    at run (hello.js:1:95985)
    at runCaller (hello.js:1:95061)
    at removeRunDependency (hello.js:1:5486)
```

And a quick look at the missing symbol where the exception occurs shows `_emval_take_value` to be missing.
Changing `O3` to `O2` in the main module compilation solves the issue.
