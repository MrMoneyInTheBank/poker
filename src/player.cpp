#include "player.hpp"

[[nodiscard]] Player::PocketCards Player::show_hand() const noexcept(false) {
  if (not this->hand[0].has_value() || not this->hand[1].has_value()) {
    throw std::logic_error("Can't show empty/partial hand");
  }
  return {this->hand[0].value(), this->hand[1].value()};
}

void Player::reset_hand() noexcept { this->hand.fill(std::nullopt); }

void Player::bet(int bet_amount) noexcept(false) {
  if (bet_amount > this->chips) {
    throw std::invalid_argument("Bet amount cannot be greater than balance.");
  } else if (bet_amount < 0) {
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

[[nodiscard]] int Player::check_balance() const noexcept { return this->chips; }

[[nodiscard]] bool Player::is_broke() const noexcept {
  return this->chips == 0;
}
