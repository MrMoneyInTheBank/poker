#include "deck.hpp"
#include "player.hpp"
#include <array>

namespace Poker {

template <std::size_t seats>
  requires(seats >= 2 && seats < 10)
class Table {
public:
  Table() = default;
  Players players;

private:
  Cards::Deck deck;
};

} // namespace Poker
