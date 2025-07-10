#include "player.hpp"

void Player::addCard(const Cards::Card &card) {
  HandType::iterator slot =
      std::find(this->hand.begin(), this->hand.end(), std::nullopt);
  if (slot == this->hand.end()) {
    throw std::length_error("Player hand is already full");
  }

  *slot = card;
}

[[nodiscard]] Player::PocketCards Player::showHand() const noexcept(false) {
  if (not this->hand[0].has_value() || not this->hand[1].has_value()) {
    throw std::logic_error("Can't show empty/partial hand");
  }
  return {*this->hand[0], *this->hand[1]};
}

void Player::resetHand() noexcept { this->hand.fill(std::nullopt); }

void Player::bet(int bet_amount) noexcept(false) {
  if (bet_amount > chips) {
    throw std::invalid_argument("Bet amount cannot be greater than balance.");
  } else if (bet_amount <= 0) {
    throw std::invalid_argument("Bet amount must be positive.");
  }
  this->chips -= bet_amount;
}

void Player::credit(int credit_amount) noexcept(false) {
  if (credit_amount < 0) {
    throw std::invalid_argument("Credit amount must be positive.");
  }
  this->chips += credit_amount;
}

[[nodiscard]] int Player::checkBalance() const noexcept { return this->chips; }

[[nodiscard]] bool Player::isBroke() const noexcept { return this->chips == 0; }
