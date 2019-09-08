#include <gtest/gtest.h>
#include "common.h"
#include "position.h"

namespace {
class PositionTest : public ::testing::Test {};

TEST_F(PositionTest, TestPositionProperties) {
  aich2::Position p = aich2::Position(1, 2, aich2::NORTH);
  EXPECT_EQ(1, p.x());
  EXPECT_EQ(2, p.y());
  EXPECT_EQ(aich2::NORTH, p.direction());
}

TEST_F(PositionTest, TestRotateRight) {
  aich2::Position p = aich2::Position(1, 2, aich2::NORTH);
  EXPECT_EQ(aich2::NORTH, p.direction());
  
  p.RotateRight();
  EXPECT_EQ(aich2::EAST, p.direction());

  p.RotateRight();
  EXPECT_EQ(aich2::SOUTH, p.direction());

  p.RotateRight();
  EXPECT_EQ(aich2::WEST, p.direction());

  p.RotateRight();
  EXPECT_EQ(aich2::NORTH, p.direction());
}

TEST_F(PositionTest, TestRotateLeft) {
  aich2::Position p = aich2::Position(1, 2, aich2::NORTH);
  EXPECT_EQ(aich2::NORTH, p.direction());

  p.RotateLeft();
  EXPECT_EQ(aich2::WEST, p.direction());

  p.RotateLeft();
  EXPECT_EQ(aich2::SOUTH, p.direction());

  p.RotateLeft();
  EXPECT_EQ(aich2::EAST, p.direction());
}

TEST_F(PositionTest, TestCoordinatesEqual) {
  aich2::Position p = aich2::Position(1, 2, aich2::NORTH);
  aich2::Position d_diff = aich2::Position(1, 2, aich2::SOUTH);
  aich2::Position x_diff = aich2::Position(0, 2, aich2::NORTH);
  aich2::Position y_diff = aich2::Position(1, 0, aich2::NORTH);

  // Direction is different, but not checked.
  EXPECT_TRUE(p.CoordinatesEqual(&d_diff));
  EXPECT_FALSE(p.CoordinatesEqual(&x_diff));
  EXPECT_FALSE(p.CoordinatesEqual(&y_diff));
}

TEST_F(PositionTest, TestNextPosition) {
  aich2::Position north = aich2::Position(1, 1, aich2::NORTH);
  aich2::Position south = aich2::Position(1, 1, aich2::SOUTH);
  aich2::Position east = aich2::Position(1, 1, aich2::EAST);
  aich2::Position west = aich2::Position(1, 1, aich2::WEST);
  
  aich2::Position next = north.NextPosition();
  EXPECT_EQ(1, next.x());
  EXPECT_EQ(0, next.y());

  next = south.NextPosition();
  EXPECT_EQ(1, next.x());
  EXPECT_EQ(2, next.y());

  next = east.NextPosition();
  EXPECT_EQ(2, next.x());
  EXPECT_EQ(1, next.y());

  next = west.NextPosition();
  EXPECT_EQ(0, next.x());
  EXPECT_EQ(1, next.y());
}
} // namespace