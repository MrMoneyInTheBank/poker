#include "deck.hpp"
#include <algorithm>
#include <array>
#include <random>

namespace {
static std::random_device entropy_seed;
static std::seed_seq seed{
    entropy_seed(), entropy_seed(), entropy_seed(),
    entropy_seed(), entropy_seed(), entropy_seed(),
    entropy_seed(), entropy_seed(), entropy_seed(),
};
static std::mt19937 rng(seed);
} // namespace

namespace Cards {

Deck::Deck() noexcept {
  std::size_t deck_position = 0;
  for (const Suit &suit : Suits) {
    for (const Rank &rank : Ranks) {
      this->cards[deck_position++] = Card(suit, rank);
    }
  }
  this->shuffle();
}

void Deck::shuffle() noexcept {
  std::shuffle(this->cards.begin(), this->cards.end(), rng);
}

Cards::Card Deck::draw() { return this->cards[this->top++]; }

void Deck::burn() { this->top++; }

std::array<Cards::Card, 3> Deck::flop() {
  return {this->draw(), this->draw(), this->draw()};
}

Cards::Card Deck::turn() { return this->draw(); }

Cards::Card Deck::river() { return this->draw(); }
} // namespace Cards
