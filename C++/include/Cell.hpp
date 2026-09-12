#include <array>
#include <ostream>

#pragma once

class Cell {
public:
  virtual ~Cell() = default;

  using Neighbourhood = std::array<std::array<const Cell *, 3>, 3>;

  virtual void print(std::ostream &os) const = 0;

  friend std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    cell.print(os);
    return os;
  }

  [[nodiscard]] virtual bool
  shouldSpawn(const Neighbourhood &neighbours) const = 0;
  [[nodiscard]] virtual bool
  shouldDespawn(const Neighbourhood &neighbours) const = 0;
};
