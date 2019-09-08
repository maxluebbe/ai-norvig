#include <iostream>
#include <gtest/gtest.h>

#include "ch2.h"
#include "scorer.h"

namespace {
  class SimulatorTest : public ::testing::Test {};

  TEST_F(SimulatorTest, SmokeTest) {
    aich2::Room r = aich2::Room(1,1);
    aich2::Agent a = aich2::Agent();
    aich2::Simulator s = aich2::Simulator(&r, &a);
    int score = s.simulate(0);
    EXPECT_EQ(0, score);
  }
} // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}