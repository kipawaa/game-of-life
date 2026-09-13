#include "Board.hpp"
#include <chrono>
#include <cstddef>
#include <iostream>
#include <thread>

int main() {
  Board<39, 55> board;
  board.randomize(0.5);

  size_t gen = 0;
  while (!board.isEmpty()) {
    std::cout << "\033[H\033[2J" << std::flush;
    std::cout << board;
    std::cout << "generation: " << gen << "\n";

    gen++;
    board.step();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  return 0;
}
