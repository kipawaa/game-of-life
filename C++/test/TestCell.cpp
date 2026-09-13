#include "Cell.hpp"
#include "StandardCell.hpp"
#include "gtest/gtest.h"
#include <memory>

TEST(TestCell, Equality) {
  StandardCell a;
  StandardCell b;

  ASSERT_EQ(a, b);
  ASSERT_EQ(b, a);

  EXPECT_TRUE(a.equals(b));
  EXPECT_TRUE(b.equals(a));

  EXPECT_TRUE(a == b);
  EXPECT_TRUE(b == a);
}

TEST(TestCell, PointerEquality) {
  std::unique_ptr<Cell> a = std::make_unique<StandardCell>();
  std::unique_ptr<Cell> b = std::make_unique<StandardCell>();

  ASSERT_EQ(*a, *b);
  ASSERT_EQ(*b, *a);
}
