#include <iostream>

constexpr std::array<std::string_view, 4> SuitNames{"♣", "♦", "♥", "♠"};

constexpr std::array<std::string_view, 13> RankNames{
    "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};

constexpr std::string_view to_string(Cards::Suit s) {
  return SuitNames[static_cast<std::size_t>(s)];
}
constexpr std::string_view to_string(Cards::Rank r) {
  return RankNames[static_cast<std::size_t>(r) - 2];
}

std::ostream &operator<<(std::ostream &os, const Cards::Card &c) {
  return os << to_string(c.rank) << to_string(c.suit);
}

