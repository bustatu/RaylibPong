# Raylib Pong

> Important resource: https://www.raylib.com/cheatsheet/cheatsheet.html

### Current Compatibility
| OS          | Default Compiler |  Last Manual Build  |                   Compile Status                     |
| ----------- | ---------------- | ------------------- | ---------------------------------------------------- |
| **macOS**   | Clang++          | `Big Sur 11.0.1`    | ![macOS Status](../../workflows/macOS/badge.svg)     |
| **Linux**   | G++              | `Ubuntu 20.04 LTS`  | ![Linux Status](../../workflows/Ubuntu/badge.svg)    |
| **Windows** | MinGW (G++)      | `Windows 10 19041`  | ![Windows Status](../../workflows/Windows/badge.svg) |

## Getting Started

### Installing Dependencies

Before building the project, you will need to install all relevant dependencies for your platform so that the project has access to all the tools required, and raylib can compile and link correctly. You can find intructions for installing dependencies on macOS, Linux, and Windows in the [docs file on installing dependencies](docs/InstallingDependencies.md).

### Building the Project
Once you have cloned this repository and installed dependencies, building the project is as simple as running these two commands in its root directory:

#### macOS & Linux
```console
$ make setup
$ make
```

#### Windows
```console
> mingw32-make setup
> mingw32-make
```

The first command will clone in the lastest C++ bindings and targeted version of raylib, copy across any relevant header files into `/includes`, and build a static library file from them, placing it in `/lib`. The second command then compiles, runs and cleans up your project using the source code in `/src/main.cpp`.

*If a window pops up, congratulations, you've successfully built the project and you can now play the game!*