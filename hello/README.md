# Cgride Hello Example

This is the minimal Cgride example.

It contains one executable target and one source file.

```text
hello/
├── cgride.config
└── src/
    └── main.cpp
```

## Project shape

The config file describes one executable target:

```text
[project]
name = hello

[target.hello]
kind = executable
sources = src/main.cpp
```

## Build with Vix

From this directory:

```bash
vix build src/main.cpp --out hello
```

## Run with Vix

```bash
vix run src/main.cpp
```

## Expected output

```text
Hello from Cgride
```

## Notes

This example keeps the source layout compatible with the upcoming Cgride project reader while still being easy to build today with Vix single-file mode.
