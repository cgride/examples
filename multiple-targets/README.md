# Cgride Multiple Targets Example

This example shows a Cgride project with two executable targets.

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

## Project description

The project is described with C++ in `cgride.cpp`.

```cpp
#include <cgride/project.hpp>

void cgride_configure(cgride::project::Project &project)
{
  auto &server = project.executable("server");

  server.sources("server/src/main.cpp");

  auto &worker = project.executable("worker");

  worker.sources("worker/src/main.cpp");
}
```

## Build

Build the default target:

```bash
cgride build
```

Build a specific target:

```bash
cgride build --target server
cgride build --target worker
```

## Run

Run the server target:

```bash
cgride run --target server
```

Run the worker target:

```bash
cgride run --target worker
```

## Expected output

Server:

```text
Hello from the Cgride server target
```

Worker:

```text
Hello from the Cgride worker target
```

## What this example shows

This example shows:

- multiple executable targets;
- target selection with `--target`;
- separate source folders;
- a project described with `cgride.cpp`.
