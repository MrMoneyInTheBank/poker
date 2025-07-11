#include "deck.hpp"
#include "player.hpp"
#include <array>

namespace Poker {

template <std::size_t seats>
  requires(seats >= 2 && seats < 10)
class Table {
public:
  Table() = default;
  Table(const Cards::Deck &deck) : deck(deck){};

  void add_player(const Player &player) noexcept(false) {
    typename Players::iterator slot =
        std::find(this->players.begin(), this->players.end(), std::nullopt);

    if (slot == this->players.end()) {
      throw std::runtime_error("Cannot add player to full table.");
    }

    *slot = player;
  }

  bool table_full() const noexcept {
    typename Players::const_iterator slot =
        std::find(this->players.begin(), this->players.end(), std::nullopt);

    return slot == this->players.end();
  }

  Players players;

private:
  Cards::Deck deck;
};

} // namespace Poker
