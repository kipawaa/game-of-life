#include "Board.hpp"
#include "StandardCell.hpp"
#include "gtest/gtest.h"
#include <memory>

TEST(StabilityTests, Square) {
  Board<6, 6> stepBoard;
  stepBoard[2][2] = std::make_unique<StandardCell>();
  stepBoard[2][3] = std::make_unique<StandardCell>();
  stepBoard[3][2] = std::make_unique<StandardCell>();
  stepBoard[3][3] = std::make_unique<StandardCell>();

  stepBoard.step();

  Board<6, 6> board;
  board[2][2] = std::make_unique<StandardCell>();
  board[2][3] = std::make_unique<StandardCell>();
  board[3][2] = std::make_unique<StandardCell>();
  board[3][3] = std::make_unique<StandardCell>();
  ASSERT_EQ(board, stepBoard);
};
