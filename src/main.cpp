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

  Poker::Table<2> poker_table(deck);
  poker_table.add_player(human);
  poker_table.add_player(computer);

  poker_table.deal_cards();

  std::array<Cards::Card, 2> ansh = poker_table.players[0]->show_hand();
  std::array<Cards::Card, 2> comp = poker_table.players[1]->show_hand();
  std::cout << "Ansh hand\n";
  std::cout << ansh[0] << ", " << ansh[1];
  std::cout << "\nComp hand\n";
  std::cout << comp[0] << ", " << comp[1] << "\n";
}
