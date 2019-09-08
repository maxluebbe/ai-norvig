#include <gtest/gtest.h>

#include "common.h"
#include "position.h"
#include "room.h"

namespace {
  class RoomTest : public ::testing::Test {};

  TEST_F(RoomTest, TestInitiallyClean) {
    aich2::Room r = aich2::Room(2,2);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        aich2::Position p = aich2::Position(i,j, aich2::NORTH);
        EXPECT_EQ(aich2::EMPTY, r.GetSquare(&p));
      }
    }
  }

  TEST_F(RoomTest, TestEmptyIsValid) {
    aich2::Room r = aich2::Room(2,2);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        aich2::Position p = aich2::Position(i,j, aich2::NORTH);
        EXPECT_EQ(aich2::EMPTY, r.GetSquare(&p));
        EXPECT_TRUE(r.IsValidPosition(&p));
      }
    }
  }

  TEST_F(RoomTest, TestBlockedInvalidPosition) {
    aich2::Room r = aich2::Room(1, 1);
    aich2::Position p = aich2::Position(0, 0, aich2::NORTH);
    EXPECT_TRUE(r.IsValidPosition(&p));
    r.SetSquare(0, 0, aich2::BLOCKED);
    EXPECT_FALSE(r.IsValidPosition(&p));
  }
  
  TEST_F(RoomTest, TestOutOfBoundsInvalidPosition) {
    aich2::Room r = aich2::Room(1, 1);
    aich2::Position north = aich2::Position(0, -1, aich2::NORTH);
    aich2::Position south = aich2::Position(0, 1, aich2::NORTH);
    aich2::Position west = aich2::Position(-1, 0, aich2::NORTH);
    aich2::Position east = aich2::Position(1, 0, aich2::NORTH);
    EXPECT_FALSE(r.IsValidPosition(&north));
    EXPECT_FALSE(r.IsValidPosition(&south));
    EXPECT_FALSE(r.IsValidPosition(&west));
    EXPECT_FALSE(r.IsValidPosition(&east));
  }

  TEST_F(RoomTest, TestSetSquare) {
    aich2::Room r = aich2::Room(1,1);
    aich2::Position p = aich2::Position(0, 0, aich2::NORTH);
    EXPECT_EQ(aich2::EMPTY, r.GetSquare(&p));
    EXPECT_TRUE(r.SetSquare(0, 0, aich2::BLOCKED));
    EXPECT_EQ(aich2::BLOCKED, r.GetSquare(&p));
  }

  TEST_F(RoomTest, TestSetSquareFailsOutOfBounds) {
    aich2::Room r = aich2::Room(1,1);
    EXPECT_FALSE(r.SetSquare(-1, 0, aich2::BLOCKED));
    EXPECT_FALSE(r.SetSquare(0, -1, aich2::BLOCKED));
    EXPECT_FALSE(r.SetSquare(1, 0, aich2::BLOCKED));
    EXPECT_FALSE(r.SetSquare(0, 1, aich2::BLOCKED));
  }

  TEST_F(RoomTest, TestCleanSquareWhenDirty) {
    aich2::Room r = aich2::Room(1,1);
    aich2::Position p = aich2::Position(0, 0, aich2::NORTH);
    r.SetSquare(0, 0, aich2::DIRT);
    EXPECT_TRUE(r.CleanSquare(&p));
    EXPECT_EQ(aich2::EMPTY, r.GetSquare(&p));
  }

  TEST_F(RoomTest, TestCleanSquareWhenNotDirty) {
    aich2::Room r = aich2::Room(1,1);
    aich2::Position p = aich2::Position(0, 0, aich2::NORTH);
    EXPECT_FALSE(r.CleanSquare(&p));
    EXPECT_EQ(aich2::EMPTY, r.GetSquare(&p));
  }
} // namespace