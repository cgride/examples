# Cgride Embedded API Example

This example shows how a C++ program can use Cgride as a library.

Unlike the other examples, this one does not use `cgride.config`.

It includes the umbrella Cgride header, creates a project in memory, discovers a toolchain, creates a build request, and calls the build engine directly.

```text
embedded-api/
├── CMakeLists.txt
└── src/
    └── main.cpp
```

## Build with Vix

From this directory:

```bash
vix build --build-target cgride_embedded_api_example -v
```

## Run the built example

After building, run the produced executable from the Vix build directory:

```bash
./build-ninja/cgride_embedded_api_example
```

For a release build:

```bash
vix build --preset release --build-target cgride_embedded_api_example -v
./build-release/cgride_embedded_api_example
```

## What this example demonstrates

The example demonstrates the public embedding flow:

1. Include the full Cgride API.
2. Create a `cgride::project::Project`.
3. Add an executable target.
4. Discover the local C++ toolchain.
5. Create `cgride::engine::BuildOptions`.
6. Create a `cgride::engine::BuildRequest`.
7. Call `cgride::engine::BuildEngine`.

## Why this matters

Cgride is not only a CLI.

The engine is meant to be reusable by other tools:

- runtimes;
- frameworks;
- IDE integrations;
- project generators;
- developer tools;
- higher-level build workflows.

A tool can create a Cgride project model in memory and call the engine directly without exposing Cgride as a user-facing command.
