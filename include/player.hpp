#pragma once

#include "deck.hpp"


class Player {
public:
  using HandType = std::array<std::optional<Cards::Card>, 2>;

  explicit Player(int starting_balance) : chips(starting_balance) {
    if (starting_balance < 0) {
      throw std::invalid_argument("Starting balance for a player must be positive.");
    } 
  }
private:
  int chips;
  HandType hand;
};
