#include "deck.hpp"
#include "player.hpp"
#include "poker.hpp"
#include <array>
#include <iostream>

int main() {
  std::cout << "Welcome to poker!\n";
  Cards::Deck deck;

  std::array<Player, 6> players = {Player(50), Player(50), Player(50),
                                   Player(50), Player(50), Player(50)};

  Poker::Table<6> poker_table(deck, players);
  poker_table.deal_pocket_cards();

  for (const Player player : poker_table.players) {
    std::cout << "Hand: " << player.show_hand() << "\n";
  }

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
