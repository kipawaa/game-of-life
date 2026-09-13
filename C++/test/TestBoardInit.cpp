#include "Board.hpp"
#include "gtest/gtest.h"

TEST(TestBoardInit, list) {
  Board<3, 3> board;
  board = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};

  EXPECT_EQ(board[0][0], nullptr);
  EXPECT_NE(board[0][1], nullptr);
  EXPECT_EQ(board[0][2], nullptr);

  EXPECT_NE(board[1][0], nullptr);
  EXPECT_EQ(board[1][1], nullptr);
  EXPECT_NE(board[1][2], nullptr);

  EXPECT_EQ(board[2][0], nullptr);
  EXPECT_NE(board[2][1], nullptr);
  EXPECT_EQ(board[2][2], nullptr);
}
