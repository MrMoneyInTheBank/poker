#pragma once

#include <array>
#include <string_view>

// Compile-time access control via constrained template forward declaration.
// Full declaration in include/poker.hpp
namespace Poker {
template <std::size_t seats>
  requires(seats >= 2 && seats < 10)
class Table;
}

namespace Cards {

constexpr std::size_t SuitCount = 4;
constexpr std::size_t RankCount = 13;

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

constexpr std::array<Suit, SuitCount> Suits{Suit::CLUB, Suit::DIAMOND,
                                            Suit::HEART, Suit::SPADE};

constexpr std::array<Cards::Rank, RankCount> Ranks{
    Rank::TWO,   Rank::THREE, Rank::FOUR, Rank::FIVE, Rank::SIX,
    Rank::SEVEN, Rank::EIGHT, Rank::NINE, Rank::TEN,  Rank::JACK,
    Rank::QUEEN, Rank::KING,  Rank::ACE};

constexpr std::array<std::string_view, 4> SuitNames{
    "\u2663", // club
    "\u2666", // diamond
    "\u2665", // heart
    "\u2660"  // spade
};

struct Card {
  Suit suit;
  Rank rank;

  Card() = default;
  Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}
};

class Deck {
  template <std::size_t seats>
    requires(seats >= 2 && seats < 10)
  friend class ::Poker::Table;

public:
  Deck();
  void shuffle();

private:
  std::array<Card, SuitCount * RankCount> cards;
  std::size_t top = 0;

  [[nodiscard]] Card draw() noexcept(false);
  void burn() noexcept(false);
  std::array<Card, 3> flop();
  Card turn();
  Card river();
};

} // namespace Cards
