# Cgride Multiple Targets Example

This example shows a project with two executable targets.

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

## Project shape

The config describes two executable targets:

```text
[project]
name = multiple-targets

[target.server]
kind = executable
sources = server/src/main.cpp

[target.worker]
kind = executable
sources = worker/src/main.cpp
```

## Build with Vix

Build the server executable:

```bash
vix build server/src/main.cpp --out server
```

Build the worker executable:

```bash
vix build worker/src/main.cpp --out worker
```

## Run with Vix

Run the server:

```bash
vix run server/src/main.cpp
```

Run the worker:

```bash
vix run worker/src/main.cpp
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

## Notes

This example keeps the future Cgride multi-target project shape while staying buildable today with Vix single-file mode.

Later, when Cgride target selection is fully connected, the intended commands will be:

```bash
cgride build --target server
cgride build --target worker
cgride run --target server
cgride run --target worker
```
