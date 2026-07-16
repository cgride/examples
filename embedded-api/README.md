# Cgride Embedded API Example

This example shows how another C++ program can use Cgride directly as a library.

It does not describe a user project with `cgride.cpp`.

Instead, it shows the lower-level C++ API used behind the CLI.

```text
embedded-api/
└── main.cpp
```

## What this example shows

This example includes the public umbrella header:

```cpp
#include <cgride/cgride.hpp>
```

Then it creates a project in memory, creates targets, configures sources, discovers a toolchain, builds a request, and calls the build engine directly.

## Build

From this directory:

```bash
cgride build main.cpp --out embedded-api
```

## Run

```bash
./embedded-api
```

## Expected output

```text
Cgride embedded API example completed
```

## Why this example exists

The normal user-facing Cgride project format is:

```text
project/
├── cgride.cpp
└── src/
    └── main.cpp
```

This example is different.

It is for tools that want to embed Cgride directly:

- runtimes;
- frameworks;
- IDE integrations;
- project generators;
- developer tools;
- higher-level build workflows.

Those tools can use the Cgride C++ API directly instead of exposing Cgride configuration files to their users.
