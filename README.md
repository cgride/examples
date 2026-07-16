# Cgride Examples

This repository contains example projects for Cgride.

The examples show how Cgride is expected to be used from the command line and from the public C++ API.

Cgride itself is an embeddable native C++ build engine. The CLI is only one interface over the engine. These examples keep that distinction clear: some projects are built through `cgride build`, while others show how another C++ program can use Cgride directly as a library.

## Examples

```text
examples/
├── hello/
├── static-library/
├── multiple-targets/
└── embedded-api/
```

## `hello`

A minimal Cgride project.

```text
hello/
├── cgride.config
└── src/
    └── main.cpp
```

This example contains one executable target.

Use it to test the simplest project shape:

```bash
cd hello
cgride build
cgride run
```

## `static-library`

A project with a static library and an executable.

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

This example demonstrates a target-to-target relationship:

```text
core static library
        ↓
app executable
```

Use it to test library creation, include directories, and linking between project targets.

```bash
cd static-library
cgride build
cgride run
```

## `multiple-targets`

A project with more than one executable target.

```text
multiple-targets/
├── cgride.config
├── server/
│   └── src/
│       └── main.cpp
└── worker/
    └── src/
        └── main.cpp
```

This example is useful for testing target selection.

Build the default target:

```bash
cd multiple-targets
cgride build
```

Build a specific target:

```bash
cgride build --target server
cgride build --target worker
```

Run a specific target:

```bash
cgride run --target server
cgride run --target worker
```

## `embedded-api`

A C++ integration example.

```text
embedded-api/
├── CMakeLists.txt
└── src/
    └── main.cpp
```

This example does not use `cgride.config`.

It shows how a C++ program can include the umbrella Cgride API, create a project in memory, discover a toolchain, create a build request, and call the build engine directly.

This is the model intended for runtimes, frameworks, IDE tools, and other developer tools that want to embed Cgride instead of exposing Cgride directly to their users.

Build it with CMake or with a higher-level workflow that has Cgride installed:

```bash
cd embedded-api
vix build --build-target all -v
```

## Build all examples

From this repository root:

```bash
for dir in hello static-library multiple-targets; do
  echo "==> $dir"
  cd "$dir"
  cgride build
  cd ..
done
```

The `embedded-api` example is different because it is a C++ integration program. Build it separately:

```bash
cd embedded-api
vix build
```

## Current status

These examples are intentionally small.

They are designed to validate the public shape of Cgride before adding larger examples.

The current examples cover:

- a minimal executable;
- a static library linked into an executable;
- multiple executable targets;
- direct embedding through the public C++ API.

Future examples may cover:

- compiled `cgride.cpp` configuration;
- generated build graphs;
- custom build directories;
- debug and release profiles;
- incremental rebuild behavior;
- structured diagnostics;
- runtime integration examples.
