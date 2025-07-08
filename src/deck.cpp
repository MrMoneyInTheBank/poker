#include "deck.hpp"
#include <algorithm>
#include <array>
#include <random>

namespace {
constexpr std::size_t SuitCount = 4;
constexpr std::size_t RankCount = 13;
constexpr std::size_t DeckSize = SuitCount * RankCount;

constexpr std::array<Cards::Suit, SuitCount> Suits{
    Cards::Suit::CLUB, Cards::Suit::DIAMOND, Cards::Suit::HEART,
    Cards::Suit::SPADE};

constexpr std::array<Cards::Rank, RankCount> Ranks{
    Cards::Rank::TWO, Cards::Rank::THREE, Cards::Rank::FOUR,  Cards::Rank::FIVE,
    Cards::Rank::SIX, Cards::Rank::SEVEN, Cards::Rank::EIGHT, Cards::Rank::NINE,
    Cards::Rank::TEN, Cards::Rank::JACK,  Cards::Rank::QUEEN, Cards::Rank::KING,
    Cards::Rank::ACE};

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

Cards::Card Deck::draw() {
  if (this->top == DeckSize) {
    throw EmptyDeckError("No more cards to draw.");
  }
  return this->cards[this->top++];
}

void Deck::burn() {
  if (this->top == DeckSize) {
    throw EmptyDeckError("No more cards to burn.");
  }
  this->top++;
}

std::array<Cards::Card, 3> Deck::flop() {
  return {this->draw(), this->draw(), this->draw()};
}

Cards::Card Deck::turn() { return this->draw(); }

Cards::Card Deck::river() { return this->draw(); }
} // namespace Cards
