# Design Decisions

This document outlines the key design decisions made in the core files of this project: `deck.hpp`, `player.hpp`, `poker.hpp`, and their corresponding implementation files. The focus is on safety, extensibility, and modern C++ best practices.

## 1. Compile-Time Safety and Access Control

- **Poker::Table as Friend**: The `Cards::Deck` class restricts access to its card-drawing and dealing methods (`draw`, `burn`, `flop`, `turn`, `river`) by making `Poker::Table` a friend class template. Only `Poker::Table` (with 2-9 seats) can manipulate the deck, ensuring that deck exhaustion is prevented at compile time.
- **Template Constraints**: The `Poker::Table` class is a template constrained to 2-9 seats using C++20 concepts. This prevents invalid table sizes at compile time and ensures the deck is never overdrawn during play.

## 2. Encapsulation and Responsibility

- **Deck Encapsulation**: The internal state of the deck (array of cards, top index) is private. Only the table can access deck operations, enforcing a clear separation of concerns.
- **Player Abstraction**: The `Player` class models a poker player with a chip balance and a two-card hand. It provides methods for betting, crediting, hand management, and balance checks, encapsulating all player-related logic.
- **Table as Game Orchestrator**: The `Poker::Table` class manages the array of players and the deck, acting as the central authority for game flow and enforcing rules at compile time.

## 3. Error Handling

- **Compile-Time Guarantees**: By restricting deck access to the table and constraining table size, the design eliminates the possibility of runtime empty deck errors.
- **Runtime Checks for Player**: The `Player` class throws exceptions for invalid operations (e.g., negative starting balance, overfilling hand, betting more than available chips, showing incomplete hand). This ensures robust error handling for user actions.

## 4. Modern C++ Features

- **Strong Typing**: Use of `enum class` for suits and ranks ensures type safety.
- **`std::array`**: Fixed-size containers are used for cards, hands, and player arrays, providing memory efficiency and safety.
- **`std::optional`**: Player hands use `std::optional` to represent empty card slots, making hand state explicit.
- **`noexcept` and Attributes**: Constructors and non-throwing functions are marked `noexcept` for clarity and optimization.
- **Randomness**: Deck shuffling uses a thread-safe Mersenne Twister (`std::mt19937`) seeded with high-entropy values.

## 5. Extensibility and Maintainability

- **Separation of Interface and Implementation**: Header files declare interfaces, while source files implement logic, supporting clean builds and IDE integration.
- **Future-Proofing**: The design anticipates future features (e.g., hand evaluation, multiplayer, GUI) by keeping responsibilities modular and interfaces clear.

## 6. Example: Deck and Table Relationship

```cpp
// deck.hpp
class Deck {
  template <std::size_t seats>
    requires(seats >= 2 && seats < 10)
  friend class ::Poker::Table;
  // ...
};

// poker.hpp
template <std::size_t seats>
  requires(seats >= 2 && seats < 10)
class Table {
  std::array<Player, seats> players;
  Cards::Deck deck;
  // ...
};
```

This ensures only valid tables can manipulate the deck, and only in ways that are safe by design.

## 7. Summary

The codebase prioritizes safety, clarity, and modern C++ idioms. Compile-time constraints and encapsulation prevent common errors, while runtime checks in player logic ensure robust user interaction. The architecture is modular and ready for future expansion. 