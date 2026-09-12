#include "Board.hpp"
#include "StandardCell.hpp"
#include <chrono>
#include <cstddef>
#include <iostream>
#include <memory>
#include <thread>

int main() {
  Board<16, 16> board;
  board[7][7] = std::make_unique<StandardCell>();
  board[7][8] = std::make_unique<StandardCell>();
  board[8][7] = std::make_unique<StandardCell>();
  board[8][8] = std::make_unique<StandardCell>();
  board[8][9] = std::make_unique<StandardCell>();

  for (std::size_t i = 0; i < 10; i++) {
    std::cout << "\033[H\033[2J" << std::flush;
    std::cout << board;
    std::cout << "generation: " << i << "\n";
    board.step();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  return 0;
}
