#include "Board.hpp"
#include "gtest/gtest.h"

TEST(StabilityTests, Square) {
  Board<2, 2> stepBoard;
  stepBoard = {{1, 1}, {1, 1}};

  stepBoard.step();

  Board<2, 2> expectedBoard;
  expectedBoard = {{1, 1}, {1, 1}};

  ASSERT_EQ(stepBoard, expectedBoard);
};

TEST(StabilityTests, HorizontalRing) {
  Board<4, 3> stepBoard;
  stepBoard = {{0, 1, 1, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}};

  stepBoard.step();

  Board<4, 3> expectedBoard;
  expectedBoard = {{0, 1, 1, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}};

  ASSERT_EQ(stepBoard, expectedBoard);
}

TEST(StabilityTests, VerticalRing) {
  Board<3, 4> stepBoard;
  stepBoard = {{0, 1, 0}, {1, 0, 1}, {1, 0, 1}, {0, 1, 0}};

  stepBoard.step();

  Board<3, 4> expectedBoard;
  expectedBoard = {{0, 1, 0}, {1, 0, 1}, {1, 0, 1}, {0, 1, 0}};

  ASSERT_EQ(stepBoard, expectedBoard);
}

TEST(StabilityTests, Circle) {
  Board<4, 4> stepBoard;
  stepBoard = {{0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}};

  stepBoard.step();

  Board<4, 4> expectedBoard;
  expectedBoard = {{0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}};

  ASSERT_EQ(stepBoard, expectedBoard);
}
