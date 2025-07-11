#include "deck.hpp"
#include "player.hpp"
#include "poker.hpp"
#include <array>
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

int main() {
  std::cout << "Welcome to poker!\n";
  Cards::Deck deck;
  Player human(50);
  Player computer(50);

  Poker::Table<2> poker_table(deck);
  poker_table.add_player(human);
  poker_table.add_player(computer);

  poker_table.deal_cards();

  std::array<Cards::Card, 2> ansh = poker_table.players[0]->showHand();
  std::array<Cards::Card, 2> comp = poker_table.players[1]->showHand();
  std::cout << "Ansh hand\n";
  std::cout << ansh[0] << ", " << ansh[1];
  std::cout << "\nComp hand\n";
  std::cout << comp[0] << ", " << comp[1] << "\n";
}
