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

Deck::Deck() {
  std::size_t deck_position = 0;
  for (const Suit &suit : Suits) {
    for (const Rank &rank : Ranks) {
      this->cards[deck_position++] = Card(suit, rank);
    }
  }
  this->shuffle();
}

void Deck::shuffle() {
  std::shuffle(this->cards.begin(), this->cards.end(), rng);
}

Card Deck::draw() { return this->cards[this->top++]; }
void Deck::burn() { this->top++; }

std::array<Card, 3> Deck::flop() {
  this->burn();
  return {
    this->draw(), 
    this->draw(), 
    this->draw()
  };
}
Card Deck::turn() {
  this->burn();
  return this->draw();
}

Card Deck::river() {
  this->burn();
  return this->draw();
}
} // namespace Cards
