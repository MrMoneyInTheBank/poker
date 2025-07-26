#pragma once

#include "deck.hpp"
#include "player.hpp"
#include <array>

namespace Poker {

template <std::size_t seats>
  requires(seats >= 2 && seats < 10)
class Table {
  using Players = std::array<Player, seats>;

public:
  Table() = default;
  Table(const Cards::Deck &deck, const std::array<Player, seats> &players)
      : players(players), deck(deck){};
  void deal_cards() noexcept(false) {
    for (std::size_t i = 0; i < 2 * seats; i++) {
      this->players[i % seats].add_card(this->deck.draw());
    }
  }


  }

  }

  Players players;

private:
  Cards::Deck deck;
};

} // namespace Poker
