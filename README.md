# Poker Game

A C++ implementation of a poker game system with robust deck, player, and table management capabilities.

## Overview

This project provides a robust foundation for poker game development with a well-structured deck management system. It includes:

- **Card representation** with suits and ranks
- **Deck management** with shuffling and drawing capabilities
- **Compile-time safety** for deck exhaustion (no runtime empty deck errors)
- **Player and table abstractions** for extensible game logic
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
  - `Cards::Deck` class: Manages a 52-card deck. Deck operations (draw, burn, flop, turn, river) are only accessible to the `Poker::Table` class via friendship, ensuring compile-time safety against running out of cards.
- **`player.hpp`**: Defines the `Player` class
  - Represents a poker player with a chip balance and a two-card hand
  - Provides methods for betting, crediting, hand management, and balance checks
  - Enforces non-negative starting balances at construction
- **`poker.hpp`**: Declares the `Poker::Table` class template
  - Manages a table of 2-9 players and a deck
  - Ensures at compile time that the deck cannot be overdrawn during play
  - Acts as the only class with privileged access to deck operations

#### Source Files (`src/`)
- **`deck.cpp`**: Implements deck functionality
  - Deck initialization with all 52 cards
  - Fisher-Yates shuffle algorithm using Mersenne Twister
  - Card drawing, burning, and dealing (flop, turn, river) with access restricted to `Poker::Table`
- **`player.cpp`**: Implements player logic
  - Hand management, betting, and balance operations
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
- **Compile-time deck safety**: The `Poker::Table` class template ensures at compile time that the deck cannot be overdrawn, eliminating runtime empty deck errors.
- **Player abstraction**: The `Player` class models chip management, hand state, and betting logic.

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

### LSP Support
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

This project is licensed under the MIT License. You are free to use, modify, and distribute this code for any purpose.

See the [LICENSE](LICENSE) file for details.