# Boost Library Demonstration

This repository contains a demonstration of various functionalities provided by the Boost C++ Libraries. Boost is a collection of peer-reviewed, portable C++ source libraries that provide a range of functionalities to enhance and extend the capabilities of the C++ Standard Library.

## Overview

The `boost_demo.cpp` file demonstrates the following functionalities:

1. **Boost.Algorithm**: String manipulation functions.
2. **Boost.LexicalCast**: Safe and convenient type casting.
3. **Boost.Regex**: Regular expressions for pattern matching.
4. **Boost.UUID**: Generation of universally unique identifiers.
5. **Boost.Any**: Type-safe container for single values of any type.
6. **Boost.Optional**: Handling of optional (nullable) values.
7. **Boost.Filesystem**: Operations on files and directories.
8. **Boost.DateTime**: Date and time handling.
9. **Boost.Variant**: Type-safe union of multiple types.
10. **Boost.Shared_Ptr**: Reference-counted smart pointers.
11. **Boost.Thread**: Multithreading utilities.
12. **Boost.ASIO**: Asynchronous I/O operations.
13. **Boost.Numeric.Ublas**: Linear algebra operations.
14. **Boost.Algorithm**: Clamping values within a specified range.
15. **Boost.Random**: Random number generation.
16. **Boost.Functional.Hash**: Hashing utilities.
17. **Boost.Range**: Range-based algorithms for container manipulation.
18. **Boost.Container**: Advanced containers.
19. **Boost.Chrono**: Measuring time durations and intervals.
20. **Boost.Graph**: Graph data structures and algorithms.

## Prerequisites

Ensure you have the following installed:

- **GCC**: GNU Compiler Collection (g++)
- **Boost Libraries**: Comprehensive collection of C++ libraries.

On Ubuntu, you can install the necessary dependencies using:

```bash
sudo apt-get update
sudo apt-get install g++ libboost-all-dev
```

## Compiling and Running

### Using Makefile

A `Makefile` is provided to simplify the compilation and execution process. To compile and run the program, use the following commands:

```bash
make
./boost_demo
```

### Manual Compilation

Alternatively, you can manually compile and run the program using the following commands:

```bash
g++ boost_demo.cpp -o boost_demo -lboost_system -lboost_filesystem -lboost_regex -lboost_date_time -lboost_thread -lboost_chrono -lboost_graph -lboost_program_options -lpthread
./boost_demo
```

## System Requirements

To build and run the project, your system must meet the following requirements:

- **Operating System**: Ubuntu 22.04.4 LTS (Jammy Jellyfish)
- **GCC**: Version 11.4.0 or higher
- **Boost Libraries**: Version 1.74 or higher

### Check System Information

You can check your system information by running the provided script:

```bash
./gather_system_info.sh
```

This script will generate a `system_info.txt` file with detailed information about your system's environment, installed software versions, and hardware.

## Detailed Description of Functionalities

### 1. Boost.Algorithm
String manipulation functions such as converting to uppercase and lowercase, and splitting strings.

### 2. Boost.LexicalCast
Safe and convenient type casting between strings and numeric types.

### 3. Boost.Regex
Regular expressions for pattern matching within strings.

### 4. Boost.UUID
Generation of universally unique identifiers for various use cases.

### 5. Boost.Any
Type-safe container capable of holding a value of any type.

### 6. Boost.Optional
Handling of optional (nullable) values with safety and convenience.

### 7. Boost.Filesystem
Operations on files and directories, such as creation, reading, and writing.

### 8. Boost.DateTime
Handling and manipulation of dates and times.

### 9. Boost.Variant
Type-safe union, allowing a variable to hold one of several specified types.

### 10. Boost.Shared_Ptr
Reference-counted smart pointers for automatic memory management.

### 11. Boost.Thread
Utilities for creating and managing threads for parallel execution.

### 12. Boost.ASIO
Asynchronous I/O operations, useful for networking and other asynchronous tasks.

### 13. Boost.Numeric.Ublas
Linear algebra operations, including matrix manipulations.

### 14. Boost.Algorithm
Clamping values within a specified range to ensure they fall within the desired limits.

### 15. Boost.Random
Random number generation with various distributions.

### 16. Boost.Functional.Hash
Hashing utilities for generating hash values for various data types.

### 17. Boost.Range
Range-based algorithms for convenient container manipulation.

### 18. Boost.Container
Advanced containers such as vectors with extended functionalities.

### 19. Boost.Chrono
Measuring time durations and intervals for performance and timing purposes.

### 20. Boost.Graph
Graph data structures and algorithms, including breadth-first search.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request with your changes.

## Author

Galen Wilkerson
```

### `Makefile`

# Makefile for Boost Library Demonstration

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Boost Libraries to link
BOOST_LIBS = -lboost_system -lboost_filesystem -lboost_regex -lboost_date_time -lboost_thread -lboost_chrono -lboost_graph -lboost_program_options -lpthread

# Target executable
TARGET = boost_demo

# Source file
SRC = boost_demo.cpp

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(BOOST_LIBS)

# Clean target
clean:
	rm -f $(TARGET)
```

### Instructions

1. **Place `README.md` and `Makefile` in your repository root**: Save the above `README.md` and `Makefile` in the root directory of your repository.
2. **Commit and Push**: Add, commit, and push the changes to your GitHub repository:

    ```bash
    git add README.md Makefile
    git commit -m "Add README and Makefile for Boost Library Demonstration"
    git push origin main
    ```

3. **Compile and Run**: Clone your repository locally and use the provided `Makefile` to compile and run the program.

This setup will provide a comprehensive introduction to the Boost library and demonstrate various functionalities, along with easy-to-follow instructions for compilation and execution.
