#include <array>
#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>

#include "Cell.hpp"
#include "StandardCell.hpp"

using Neighbourhood = std::array<std::array<const Cell *, 3>, 3>;

template <std::size_t Width, std::size_t Height> class Board {
public:
  constexpr Board() = default;

  [[nodiscard]] constexpr const std::array<std::unique_ptr<Cell>, Height> &
  operator[](size_t row) const {
    return cells_[row];
  }
  [[nodiscard]] constexpr std::array<std::unique_ptr<Cell>, Height> &
  operator[](std::size_t row) {
    return cells_[row];
  }

  friend std::ostream &operator<<(std::ostream &os, const Board &board) {
    // top line
    os << "\u250C";
    for (std::size_t i = 0; i < 3 * Width; i++) {
      os << "\u2500";
    }
    os << "\u2510\n";

    // board
    for (std::size_t row = 0; row < Width; row++) {
      os << "\u2502";
      for (std::size_t col = 0; col < Height; col++) {
        const auto &current = board[row][col];
        if (current) {
          os << *current;
        } else {
          os << "   ";
        }
      }
      os << "\u2502\n";
    }

    // bottom line
    os << "\u2514";
    for (std::size_t i = 0; i < 3 * Width; i++) {
      os << "\u2500";
    }
    os << "\u2518\n";

    return os;
  }

  [[nodiscard]] const Neighbourhood getNeighbours(std::size_t row,
                                                  std::size_t col) const {
    // std::cout << "Board::getNeighbours\n";
    Neighbourhood neighbours;

    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (dx == 0 && dy == 0) {
          neighbours[1 + dy][1 + dx] = 0;
          continue;
        }

        if (0 <= row + dy && row + dy < Height && 0 <= col + dx &&
            col + dx < Width) {

          neighbours[1 + dy][1 + dx] = cells_[row + dy][col + dx].get();
        } else {
          neighbours[1 + dy][1 + dx] = nullptr;
        }
      }
    }

    return neighbours;
  }

  void step() {
    std::array<std::array<std::unique_ptr<Cell>, Width>, Height> next_cells{};
    // std::cout << "Board::step\n";
    for (std::size_t row = 0; row < Height; row++) {
      for (std::size_t col = 0; col < Width; col++) {
        const auto &current = cells_[row][col];
        const Neighbourhood neighbours = this->getNeighbours(row, col);

        // TODO: iterate over cell types once there are multiple, with a
        // way of determining priority
        if (current) {
          if (!(current->shouldDespawn(neighbours))) {
            next_cells[row][col] = std::make_unique<StandardCell>();
          }
        } else {
          if (StandardCell().shouldSpawn(neighbours)) {
            next_cells[row][col] = std::make_unique<StandardCell>();
          }
        }
      }
    }
    cells_ = std::move(next_cells);
  }

private:
  std::array<std::array<std::unique_ptr<Cell>, Width>, Height> cells_{};
};
