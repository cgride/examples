# Cgride Examples

This repository contains example projects for Cgride.

The examples show the intended Cgride project model:

```text
Build C++ with C++.
```

A Cgride project is described with a `cgride.cpp` file. The build description is written in C++, not in a custom config format and not in CMake.

## Structure

```text
examples/
├── hello/
├── static-library/
├── multiple-targets/
└── embedded-api/
```

## Requirements

You need the `cgride` command available in your `PATH`.

Check the installed version:

```bash
cgride --version
```

## Examples

### `hello`

A minimal executable project.

```text
hello/
├── cgride.cpp
└── src/
    └── main.cpp
```

Build it:

```bash
cd hello
cgride build
```

Run it:

```bash
cgride run
```

Expected output:

```text
Hello from Cgride
```

### `static-library`

A project with one library target and one executable target.

```text
static-library/
├── cgride.cpp
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

Build it:

```bash
cd static-library
cgride build
```

Run it:

```bash
cgride run
```

Expected output:

```text
Hello from the Cgride static library example
```

### `multiple-targets`

A project with two executable targets.

```text
multiple-targets/
├── cgride.cpp
├── server/
│   └── src/
│       └── main.cpp
└── worker/
    └── src/
        └── main.cpp
```

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

Expected output for `server`:

```text
Hello from the Cgride server target
```

Expected output for `worker`:

```text
Hello from the Cgride worker target
```

### `embedded-api`

A direct C++ API example.

```text
embedded-api/
└── main.cpp
```

This example shows how another C++ program can use Cgride as a library through the public umbrella header:

```cpp
#include <cgride/cgride.hpp>
```

It demonstrates the lower-level embedding model behind the CLI.

The normal user-facing examples are `hello`, `static-library`, and `multiple-targets`.

## Build all CLI examples

From the repository root:

```bash
for dir in hello static-library multiple-targets; do
  echo "==> $dir"
  cd "$dir"
  cgride build
  cd ..
done
```

## Run all CLI examples

From the repository root:

```bash
cd hello
cgride run
cd ..

cd static-library
cgride run
cd ..

cd multiple-targets
cgride run --target server
cgride run --target worker
cd ..
```

## Project format

The official user-facing Cgride project format is:

```text
project/
├── cgride.cpp
└── src/
    └── main.cpp
```

The `cgride.cpp` file is real C++ code. It describes the project, targets, sources, include directories, links, and build settings by using the Cgride C++ API.

Cgride does not use these examples to promote multiple project formats.

For these examples:

```text
cgride.cpp      official user project description
main.cpp        normal C++ source file
cgride command  user-facing build and run interface
```

No `cgride.config` file is used.

No `CMakeLists.txt` file is used for the user-facing examples.

## Current examples

The current examples cover:

- one executable target;
- one library target linked into an executable;
- multiple executable targets;
- direct use of the public Cgride C++ API.

## Notes

These examples are intentionally small.

They are meant to validate the public Cgride shape before larger examples are added.
