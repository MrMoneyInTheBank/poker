#pragma once

#include "deck.hpp"
#include <array>
#include <optional>
#include <stdexcept>

class Player {
public:
  using HandType = std::array<std::optional<Cards::Card>, 2>;

  Player() noexcept = default;
  explicit Player(int starting_balance) : chips(starting_balance) {
    if (starting_balance < 0) {
      throw std::invalid_argument(
          "Starting balance for a player must be positive.");
    }
  }

  void addCard(const Cards::Card &card);
  [[nodiscard]] std::array<Cards::Card, 2> showHand() const;
  void resetHand() noexcept;

  void bet(int bet_amount);
  void credit(int credit_amount) noexcept;
  [[nodiscard]] int checkBalance() const noexcept;
  [[nodiscard]] bool isBroke() const noexcept;

private:
  int chips;
  HandType hand;
};
