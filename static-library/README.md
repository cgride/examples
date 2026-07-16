# Cgride Static Library Example

This example shows a project with a small static-library-style component and an executable that uses it.

```text
static-library/
├── cgride.config
├── core/
│   ├── include/
│   │   └── core/
│   │       └── message.hpp
│   └── src/
│       └── message.cpp
└── app/
    └── src/
        └── main.cpp
```

## Project shape

The config describes two targets:

```text
[project]
name = static-library

[target.core]
kind = static_library
sources = core/src/message.cpp
include_dirs = core/include

[target.app]
kind = executable
sources = app/src/main.cpp
links = core
```

The dependency shape is:

```text
core static library
        ↓
app executable
```

## Build with Vix

From this directory:

```bash
vix build app/src/main.cpp --out static-library-app -- -Icore/include core/src/message.cpp
```

## Run with Vix

```bash
vix run app/src/main.cpp -- -Icore/include core/src/message.cpp
```

## Expected output

```text
Hello from the Cgride static library example
```

## Notes

This example keeps a future Cgride project configuration file while remaining buildable today with Vix.

The `core` target is represented as a library target in `cgride.config`. For the current Vix command, `core/src/message.cpp` is passed as an additional source file and `core/include` is passed as an include directory.
