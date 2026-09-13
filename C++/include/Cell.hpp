#include <array>
#include <ostream>

#pragma once

class Cell {
public:
  virtual ~Cell() = default;

  using Neighbourhood = std::array<std::array<const Cell *, 3>, 3>;

  virtual void print(std::ostream &os) const = 0;
  virtual bool equals(const Cell &other) const = 0;

  [[nodiscard]] friend bool operator==(const Cell &lhs,
                                       const Cell &rhs) noexcept {
    return lhs.equals(rhs);
  }

  [[nodiscard]] friend bool operator!=(const Cell &lhs,
                                       const Cell &rhs) noexcept {
    return !lhs.equals(rhs);
  }

  friend std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    cell.print(os);
    return os;
  }

  [[nodiscard]] virtual bool
  shouldSpawn(const Neighbourhood &neighbours) const = 0;
  [[nodiscard]] virtual bool
  shouldDespawn(const Neighbourhood &neighbours) const = 0;
};
