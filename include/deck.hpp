#pragma once

#include <array>

// Compile-time access control via constrained template forward declaration.
// Full declaration in include/poker.hpp
namespace Poker {
template <std::size_t seats>
  requires(seats >= 2 && seats < 10)
class Table;
}

namespace Cards {
enum class Suit : uint8_t { CLUB, DIAMOND, HEART, SPADE };

enum class Rank : uint8_t {
  TWO = 2,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE,
};

struct Card {
  Suit suit;
  Rank rank;

  Card() noexcept = default;
  Card(Suit suit, Rank rank) noexcept : suit(suit), rank(rank) {}
};

class Deck {
  template <std::size_t seats>
    requires(seats >= 2 && seats < 10)
  friend class ::Poker::Table;

public:
  Deck() noexcept;
  void shuffle() noexcept;

private:
  std::array<Card, 52> cards;
  std::size_t top = 0;

  [[nodiscard]] Card draw() noexcept(false);
  void burn() noexcept(false);
  std::array<Card, 3> flop();
  Card turn();
  Card river();
};

} // namespace Cards
