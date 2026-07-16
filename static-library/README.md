# Cgride Static Library Example

This example shows a Cgride project with two targets:

```text
core static library
        ↓
app executable
```

The project is described with C++ in `cgride.cpp`.

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

## Project description

The `core` target is a static library.

The `app` target is an executable that links with `core`.

```cpp
#include <cgride/project.hpp>

void cgride_configure(cgride::project::Project &project)
{
  auto &core = project.static_library("core");

  core.sources("core/src/message.cpp");
  core.include_dirs("core/include");

  auto &app = project.executable("app");

  app.sources("app/src/main.cpp");
  app.links(core);
}
```

## Build

From this directory:

```bash
cgride build
```

## Run

```bash
cgride run
```

## Expected output

```text
Hello from the Cgride static library example
```

## What this example shows

This example shows:

- one static library target;
- one executable target;
- source files in different folders;
- public include directories;
- linking one target with another target;
- a project described with `cgride.cpp`.
