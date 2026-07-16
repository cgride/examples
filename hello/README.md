# Cgride Hello Example

This is the minimal Cgride project.

It shows the basic project shape:

```text
hello/
├── cgride.cpp
└── src/
    └── main.cpp
```

## Project description

The build is described in `cgride.cpp`.

Cgride uses C++ as the project description language. There is no separate config file.

```cpp
#include <cgride/project.hpp>

void cgride_configure(cgride::project::Project &project)
{
  auto &app = project.executable("hello");

  app.sources("src/main.cpp");
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
Hello from Cgride
```

## What this example shows

This example shows:

- one executable target;
- one source file;
- a `cgride.cpp` project description;
- the normal `cgride build` and `cgride run` workflow.
