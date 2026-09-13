#include <array>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <ostream>
#include <random>

#include "Cell.hpp"
#include "StandardCell.hpp"

using Neighbourhood = std::array<std::array<const Cell *, 3>, 3>;

template <std::size_t Width, std::size_t Height> class Board {
public:
  const static size_t width = Width;
  const static size_t height = Height;

  constexpr Board() = default;

  // Overload operator= for 2D initializer lists
  Board &operator=(std::initializer_list<std::initializer_list<int>> grid) {
    std::size_t row = 0;
    for (const auto &rowList : grid) {
      if (row >= height)
        break;
      std::size_t col = 0;
      for (int cellState : rowList) {
        if (col >= width)
          break;

        if (cellState != 0) {
          cells_[row][col] = std::make_unique<StandardCell>();
        } else {
          cells_[row][col] = nullptr;
        }
        ++col;
      }
      ++row;
    }
    return *this;
  }

  [[nodiscard]] bool operator==(const Board &other) const {
    if (other.height != height || other.width != width) {
      std::cerr << "differing dimensions\n";
      return false;
    }

    for (std::size_t row = 0; row < Height; row++) {
      for (std::size_t col = 0; col < Width; col++) {
        const auto &thisCell = cells_[row][col];
        const auto &otherCell = other[row][col];

        if (!thisCell && !otherCell) {
          continue;
        }

        if (!thisCell || !otherCell) {
          return false;
        }

        if (*thisCell != *otherCell) {
          return false;
        }
      }
    }
    return true;
  }

  [[nodiscard]] constexpr const std::array<std::unique_ptr<Cell>, Width> &
  operator[](size_t row) const {
    return cells_[row];
  }
  [[nodiscard]] constexpr std::array<std::unique_ptr<Cell>, Width> &
  operator[](std::size_t row) {
    return cells_[row];
  }

  friend std::ostream &operator<<(std::ostream &os, const Board &board) {
    // start on a new line
    os << "\n";
    // top line
    os << "\u250C";
    for (std::size_t i = 0; i < 3 * width; i++) {
      os << "\u2500";
    }
    os << "\u2510\n";

    // board
    for (std::size_t row = 0; row < height; row++) {
      os << "\u2502";
      for (std::size_t col = 0; col < width; col++) {
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
    for (std::size_t i = 0; i < 3 * width; i++) {
      os << "\u2500";
    }
    os << "\u2518\n";

    return os;
  }

  void randomize(double fillProbability = 0.2) {
    // Standard C++ Mersenne Twister engine seeded with random_device
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dist(fillProbability);

    for (std::size_t row = 0; row < Height; ++row) {
      for (std::size_t col = 0; col < Width; ++col) {
        if (dist(gen)) {
          cells_[row][col] = std::make_unique<StandardCell>();
        } else {
          cells_[row][col] = nullptr;
        }
      }
    }
  }

  [[nodiscard]] bool isEmpty() const {
    for (std::size_t row = 0; row < Height; ++row) {
      for (std::size_t col = 0; col < Width; ++col) {
        if (cells_[row][col]) {
          return false;
        }
      }
    }
    return true;
  }

  [[nodiscard]] const Neighbourhood getNeighbours(std::size_t row,
                                                  std::size_t col) const {
    // std::cout << "Board::getNeighbours\n";
    Neighbourhood neighbours;

    for (int dy = -1; dy <= 1; dy++) {
      for (int dx = -1; dx <= 1; dx++) {
        int neighbourRow = static_cast<int>(row) + dy;
        int neighbourCol = static_cast<int>(col) + dx;

        if (0 <= neighbourRow && neighbourRow < static_cast<int>(height) &&
            0 <= neighbourCol && neighbourCol < static_cast<int>(width)) {

          neighbours[1 + dy][1 + dx] = cells_[neighbourRow][neighbourCol].get();
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
