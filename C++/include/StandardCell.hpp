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

  [[nodiscard]] bool
  shouldSpawn(const Neighbourhood &neighbours) const override {
    // std::cout << "StandardCell::shouldSpawn\n";
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
    for (std::size_t x = 0; x < 3; x++) {
      for (std::size_t y = 0; y < 3; y++) {
        numLiving += (neighbours[x][y] != nullptr);
      }
    }
    return numLiving;
  }
};
