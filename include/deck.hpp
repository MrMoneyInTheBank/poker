#pragma once

#include <array>
#include <stdexcept>

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
public:
  Deck() noexcept;
  void shuffle() noexcept;
  [[nodiscard]] Card draw() noexcept(false);
  void burn() noexcept(false);
  std::array<Card, 3> flop();
  Card turn();
  Card river();

private:
  std::array<Card, 52> cards;
  std::size_t top = 0;
};

class EmptyDeckError : public std::out_of_range {
public:
  explicit EmptyDeckError(const char *msg) : std::out_of_range(msg) {}
};

} // namespace Cards
