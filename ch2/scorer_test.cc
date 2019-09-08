#include <gtest/gtest.h>
#include "scorer.h"

namespace {
    class ScorerTest : public ::testing::Test {
        protected:
            aich2::Scorer test_scorer;
            void SetUp() override {
                test_scorer = aich2::Scorer();
            }

    };

    TEST_F(ScorerTest, TestInitialScore) {
        EXPECT_EQ(0, test_scorer.score());
    }

    TEST_F(ScorerTest, TestScoreWhenTurnedOffWrongLocation) {
        test_scorer.IncrementActions();
        test_scorer.IncrementSquaresCleaned();
        test_scorer.TurnedOffNotAtHome();
        EXPECT_EQ(-901, test_scorer.score());
    }

    TEST_F(ScorerTest, TestScore) {
        test_scorer.IncrementActions();
        test_scorer.IncrementSquaresCleaned();
        EXPECT_EQ(99, test_scorer.score());
    }
} // namespace