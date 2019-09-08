#include "scorer.h"

namespace aich2 {
    Scorer::Scorer() {
        squares_cleaned_ = 0;
        actions_taken_ = 0;
        turned_off_not_at_home_ = false;
    }
    int Scorer::score() const {
        int score = squares_cleaned_ * 100 - actions_taken_;
        if (turned_off_not_at_home_) {
            score -= 1000;
        }
        return score;            
    }
    void Scorer::IncrementActions() {
        actions_taken_++;
    }
    void Scorer::IncrementSquaresCleaned() {
        squares_cleaned_++;
    }
    void Scorer::TurnedOffNotAtHome() {
        turned_off_not_at_home_ = true;
    }
} // namespace aich2