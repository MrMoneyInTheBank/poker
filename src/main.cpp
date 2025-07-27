#include "deck.hpp"
#include "player.hpp"
#include "poker.hpp"
#include <array>
#include <iostream>

int main() {
  std::cout << "Welcome to poker!\n";
  Cards::Deck deck;

  Player human(50);
  Player computer(50);

  Poker::Table<2> poker_table(deck, {human, computer});

  poker_table.deal_pocket_cards();

  std::array<Cards::Card, 2> ansh = poker_table.players[0].show_hand();
  std::array<Cards::Card, 2> comp = poker_table.players[1].show_hand();

  std::cout << "Ansh hand\n";
  std::cout << ansh[0] << " " << ansh[1];
  std::cout << "\nComp hand\n";
  std::cout << comp[0] << " " << comp[1] << "\n";

  poker_table.flop();
  poker_table.turn();
  poker_table.river();

  std::cout << "\nCommunity cards\n";
  for (auto card : poker_table.community_cards) {
    if (card.has_value()) {
      std::cout << card.value() << " ";
    }
  }
  std::cout << std::endl;
}
