#pragma once

#include "Cell.hpp"
#include <cstddef>
#include <iostream>
#include <ostream>

class StandardCell : public Cell {
public:
  StandardCell() = default;

  void print(std::ostream &os) const override {
    os << "\u2588"
          "\u2588"
          "\u2588";
  }

  [[nodiscard]] bool equals(const Cell &other) const override {
    return dynamic_cast<const StandardCell *>(&other) != nullptr;
  }

  [[nodiscard]] bool shouldSpawn(const Neighbourhood &neighbours)
      const override { // std::cout << "StandardCell::shouldSpawn\n";
    return getNumLivingNeighbours(neighbours) == 3;
  }

  [[nodiscard]] bool
  shouldDespawn(const Neighbourhood &neighbours) const override {
    // std::cout << "StandardCell::shouldDespawn\n";
    std::size_t numLiving = getNumLivingNeighbours(neighbours);
    return numLiving > 3 || numLiving < 2;
  }

private:
  [[nodiscard]] std::size_t
  getNumLivingNeighbours(const Neighbourhood &neighbours) const {
    std::size_t numLiving = 0;
    for (std::size_t row = 0; row < 3; row++) {
      for (std::size_t col = 0; col < 3; col++) {
        if (row == 1 && col == 1) {
          continue;
        }
        numLiving += (neighbours[row][col] != nullptr);
      }
    }
    return numLiving;
  }
};
