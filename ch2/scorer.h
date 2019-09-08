#ifndef AICH2_SCORER_H
#define AICH2_SCORER_H
namespace aich2 {
class Scorer {
    private:
     int squares_cleaned_, actions_taken_;
     bool turned_off_not_at_home_;

    public:
        // Create a new scorer for Vacuum Simulation.
        explicit Scorer();
        // Return performance measure score.
        int score() const;
        // Increment the count of actions taken by the Agent.
        void IncrementActions();
        // Increment the count of squares cleaned by the Agent.
        void IncrementSquaresCleaned();
        // Track that the Agent turned the robot in wrong location.
        void TurnedOffNotAtHome(); 
};
} // namespace aich2
#endif