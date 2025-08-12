# ⏱ Console Stopwatch

A simple console-based stopwatch application written in C++. This project is a replica of the macOS Stopwatch app, designed for practicing data structures (such as `std::stack`) and expanding C++ knowledge.

## 👨🏽‍💻 Features

- **Start, Pause, and Reset:** Control the stopwatch with intuitive commands.
- **Lap Functionality:** Record lap times and view splits.
- **Stack Data Structure:** Lap and split times are managed using stacks for efficient storage and retrieval.
- **Console Interface:** Clean and interactive text-based UI.

## 📝 Project Structure

```
include/
    menu.h
    stopwatch.h
    utils.h
src/
    main.cpp
    menu.cpp
    stopwatch.cpp
    utils.cpp
Makefile
```

## 🛠️ How to Build and Run

This project uses a `Makefile` for easy compilation and execution.

### Build

```sh
make
```

### Run

```sh
make run
```

### Clean

```sh
make clean
```

## 🚀 Usage

- Follow the on-screen menu to start, pause, reset, and record laps.
- Lap times and splits are displayed in a tabular format.

## 💡 Motivation

This project was created to:

- Practice using stacks and other data structures in C++.
- Learn more about time measurement and console applications.
- Replicate a familiar utility from macOS in a cross-platform way.
