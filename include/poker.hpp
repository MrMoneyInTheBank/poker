#include "deck.hpp"
#include "player.hpp"
#include <array>

namespace Poker {

template <std::size_t seats>
  requires(seats >= 2 && seats < 10)
class Table {
public:
  Table() = default;

private:
  std::array<Player, seats> players;
  Cards::Deck deck;
};

} // namespace Poker
