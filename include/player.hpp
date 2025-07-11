#pragma once

#include "deck.hpp"
#include <array>
#include <concepts>
#include <optional>
#include <stdexcept>

class Player {
public:
  using PartialPocket = std::array<std::optional<Cards::Card>, 2>;
  using PocketCards = std::array<Cards::Card, 2>;

  Player() noexcept = default;
  explicit Player(int starting_balance) noexcept(false)
      : chips(starting_balance) {
    if (starting_balance < 0) {
      throw std::invalid_argument(
          "Starting balance for a player must be positive.");
    }
  }

  template <typename T>
    requires std::same_as<std::remove_cvref_t<T>, Cards::Card>
  void add_card(T &&card) noexcept(false) {
    PartialPocket::iterator slot =
        std::find(this->hand.begin(), this->hand.end(), std::nullopt);
    if (slot == this->hand.end()) {
      throw std::length_error("Player hand is already full");
    }
    *slot = std::forward<T>(card);
  };

  [[nodiscard]] PocketCards show_hand() const noexcept(false);
  void reset_hand() noexcept;

  void bet(int bet_amount) noexcept(false);
  void credit(int credit_amount) noexcept(false);
  [[nodiscard]] int check_balance() const noexcept;
  [[nodiscard]] bool is_broke() const noexcept;

private:
  int chips;
  PartialPocket hand;
};
