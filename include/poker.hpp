#pragma once

#include "deck.hpp"
#include "player.hpp"
#include <array>

namespace Poker {

template <std::size_t seats>
  requires(seats >= 2 && seats < 10)
class Table {
  using Players = std::array<Player, seats>;
  using CommunityCards = std::array<std::optional<Cards::Card>, 5>;

public:
  Table() = default;
  Table(const Cards::Deck &deck, const std::array<Player, seats> &players)
      : players(players), deck(deck){};
  // TODO
  // probably best to make this a private method
  // later and invoke it via a main game loop
  void deal_cards() noexcept(false) {
    for (std::size_t i = 0; i < 2 * seats; i++) {
      this->players[i % seats].add_card(this->deck.draw());
    }
  }

  void flop() {
    std::array<Cards::Card, 3> flop_cards = this->deck.flop();

    for (size_t idx = 0; idx < 3; idx++) {
      community_cards[idx] = flop_cards[idx];
    }
  }

  void turn() {
    Cards::Card turn_card = this->deck.turn();
    community_cards[3] = turn_card;
  }

  void river() {
    Cards::Card river_card = this->deck.river();
    community_cards[3] = river_card;
  }

  Players players;
  CommunityCards community_cards;

private:
  Cards::Deck deck;
};

} // namespace Poker
