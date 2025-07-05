# Poker Game

A C++ implementation of a poker deck management system with card drawing, shuffling, and deck manipulation capabilities.

## Overview

This project provides a robust foundation for poker game development with a well-structured deck management system. It includes:

- **Card representation** with suits and ranks
- **Deck management** with shuffling and drawing capabilities
- **Error handling** for edge cases like empty decks
- **Modern C++ features** including strong typing and exception safety

## System Prerequisites

### Required Software
- **GCC/G++ compiler** (version 8.0 or later) or **Clang** (version 7.0 or later)
- **Make** (GNU Make 3.81 or later)
- **CMake** (optional, for IDE integration)

### Operating System Support
- **Linux** (Ubuntu 18.04+, CentOS 7+, etc.)
- **macOS** (10.14+)
- **Windows** (with WSL, MinGW, or Cygwin)

### C++ Standard
This project uses **C++20** standard features including:
- `std::array` for fixed-size containers
- `enum class` for type-safe enumerations
- `[[nodiscard]]` and `[[maybe_unused]]` attributes
- `noexcept` specifications
- Structured bindings and other modern C++ features

## Building the Project

### Debug Build
To build with debug symbols and without optimizations:

```bash
# Clean any previous builds
make clean

# Build with debug flags
CXXFLAGS="-std=c++20 -Wall -Wextra -g -O0" make build
```

### Release Build
To build with optimizations for production:

```bash
# Clean any previous builds
make clean

# Build with release optimizations (default)
make build
```

The release build uses `-O3` optimization level by default.

### Build Targets

- `make build` - Compiles the project and creates the executable
- `make run` - Builds and runs the executable
- `make clean` - Removes build artifacts

### Build Output
- **Executable**: `bin/poker`
- **Object files**: `build/*.o`
- **Build directories**: Created automatically if they don't exist

## Running the Project

### Basic Execution
```bash
# Build and run in one command
make run

# Or build first, then run
make build
./bin/poker
```

### Current Functionality
The current implementation outputs "Hello Poker" to demonstrate the build system is working correctly. The deck management system is implemented and ready for integration into a full poker game.

## Code Organization

### Directory Structure
```
poker/
├── include/          # Header files
│   └── deck.hpp     # Deck and Card class declarations
├── src/             # Source files
│   ├── deck.cpp     # Deck and Card class implementations
│   └── main.cpp     # Main entry point
├── build/           # Object files (generated)
├── bin/             # Executable (generated)
├── Makefile         # Build configuration
└── compile_commands.json  # IDE integration
```

### Code Architecture

#### Header Files (`include/`)
- **`deck.hpp`**: Contains the core poker domain classes
  - `Cards::Suit` enum: CLUB, DIAMOND, HEART, SPADE
  - `Cards::Rank` enum: TWO through ACE
  - `Cards::Card` struct: Represents a single playing card
  - `Cards::Deck` class: Manages a 52-card deck
  - `Cards::EmptyDeckError` exception: Handles deck exhaustion

#### Source Files (`src/`)
- **`deck.cpp`**: Implements deck functionality
  - Deck initialization with all 52 cards
  - Fisher-Yates shuffle algorithm using Mersenne Twister
  - Card drawing with bounds checking
  - Card burning (discarding without drawing)
- **`main.cpp`**: Application entry point

### Design Patterns
- **RAII**: Automatic resource management
- **Exception Safety**: Proper error handling with custom exceptions
- **Encapsulation**: Private implementation details in the Deck class
- **Type Safety**: Strong typing with enum classes

### Key Features
- **Thread-safe random number generation** using `std::mt19937`
- **Exception-safe operations** with proper error propagation
- **Memory-efficient** using stack-allocated arrays
- **Modern C++ idioms** including `noexcept` specifications and attributes

## Development

### Adding New Features
1. Add header declarations to `include/`
2. Implement functionality in `src/`
3. Update `main.cpp` to test new features
4. Build and test with `make run`

### IDE Integration
The project includes `compile_commands.json` for IDE support:
- **VSCode**: Install C/C++ extension
- **CLion**: Import as CMake project
- **Vim/Neovim**: Use with clangd or ccls

### LSP Support (Language Server Protocol)
For optimal IDE experience with language servers like **clangd**, you can regenerate the `compile_commands.json` file:

```bash
# Install Bear (if not already installed)
# macOS: brew install bear
# Ubuntu/Debian: sudo apt install bear
# Arch: sudo pacman -S bear

# Generate compile_commands.json
bear -- make clean
bear -- make -j$(nproc)
```

This ensures your LSP has the most up-to-date compilation database for features like:
- **IntelliSense** and code completion
- **Go to definition** and **Find references**
- **Error highlighting** and **semantic analysis**
- **Refactoring** support

### Code Style
- Follow the existing naming conventions
- Use `const` where appropriate
- Include proper error handling
- Add `noexcept` specifications for non-throwing functions

## Future Enhancements
- Full poker game implementation
- Multiple deck support
- Card comparison and hand evaluation
- Network multiplayer support
- GUI interface

## License
[Add your license information here]

## Contributing
[Add contribution guidelines here] 