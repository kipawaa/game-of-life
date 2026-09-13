#include "Board.hpp"
#include "StandardCell.hpp"
#include "gtest/gtest.h"
#include <memory>

TEST(UpdateTests, NoNeighbourDespawn) {
  Board<3, 3> board;
  board[1][1] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}
TEST(UpdateTests, NoNeighbourNoSpawn) {
  Board<3, 3> board;

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, OneNeighbourDespawn) {
  Board<3, 3> board;
  board[1][1] = std::make_unique<StandardCell>();

  board[0][0] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, OneNeighbourNoSpawn) {
  Board<3, 3> board;

  board[0][0] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, TwoNeighbourNoDespawn) {
  Board<3, 3> board;
  board[1][1] = std::make_unique<StandardCell>();

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_NE(board[1][1], nullptr);
}

TEST(UpdateTests, TwoNeighbourNoSpawn) {
  Board<3, 3> board;

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, ThreeNeighbourNoDespawn) {
  Board<3, 3> board;
  board[1][1] = std::make_unique<StandardCell>();

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_NE(board[1][1], nullptr);
}

TEST(UpdateTests, ThreeNeighbourSpawn) {
  Board<3, 3> board;

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_NE(board[1][1], nullptr);
}

TEST(UpdateTests, FourNeighbourDespawn) {
  Board<3, 3> board;
  board[1][1] = std::make_unique<StandardCell>();

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();
  board[1][0] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, FourNeighbourNoSpawn) {
  Board<3, 3> board;

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();
  board[1][0] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, FiveNeighbourDespawn) {
  Board<3, 3> board;
  board[1][1] = std::make_unique<StandardCell>();

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();
  board[1][0] = std::make_unique<StandardCell>();
  board[1][2] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, FiveNeighbourNoSpawn) {
  Board<3, 3> board;

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();
  board[1][0] = std::make_unique<StandardCell>();
  board[1][2] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, SixNeighbourDespawn) {
  Board<3, 3> board;
  board[1][1] = std::make_unique<StandardCell>();

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();
  board[1][0] = std::make_unique<StandardCell>();
  board[1][2] = std::make_unique<StandardCell>();
  board[2][0] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, SixNeighbourNoSpawn) {
  Board<3, 3> board;

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();
  board[1][0] = std::make_unique<StandardCell>();
  board[1][2] = std::make_unique<StandardCell>();
  board[2][0] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, SevenNeighbourDespawn) {
  Board<3, 3> board;
  board[1][1] = std::make_unique<StandardCell>();

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();
  board[1][0] = std::make_unique<StandardCell>();
  board[1][2] = std::make_unique<StandardCell>();
  board[2][0] = std::make_unique<StandardCell>();
  board[2][1] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, SevenNeighbourNoSpawn) {
  Board<3, 3> board;

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();
  board[1][0] = std::make_unique<StandardCell>();
  board[1][2] = std::make_unique<StandardCell>();
  board[2][0] = std::make_unique<StandardCell>();
  board[2][1] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, EightNeighbourDespawn) {
  Board<3, 3> board;
  board[1][1] = std::make_unique<StandardCell>();

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();
  board[1][0] = std::make_unique<StandardCell>();
  board[1][2] = std::make_unique<StandardCell>();
  board[2][0] = std::make_unique<StandardCell>();
  board[2][1] = std::make_unique<StandardCell>();
  board[2][2] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}

TEST(UpdateTests, EightNeighbourNoSpawn) {
  Board<3, 3> board;

  board[0][0] = std::make_unique<StandardCell>();
  board[0][1] = std::make_unique<StandardCell>();
  board[0][2] = std::make_unique<StandardCell>();
  board[1][0] = std::make_unique<StandardCell>();
  board[1][2] = std::make_unique<StandardCell>();
  board[2][0] = std::make_unique<StandardCell>();
  board[2][1] = std::make_unique<StandardCell>();
  board[2][2] = std::make_unique<StandardCell>();

  board.step();

  ASSERT_EQ(board[1][1], nullptr);
}
