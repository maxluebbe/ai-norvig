#include "environment.h"

namespace aich2 {
    Environment::Environment(Room *r, Position *robot, Position *home) {
        room_ = r;
        robot_position_ = robot;
        home_position_ = home;
        collision_ = false;
    }

    void Environment::CommandRobot(RobotAction a) {
        // Reset collision detection.
        collision_ = false;
        Position next = robot_position_->NextPosition();

        // Perform action.
        switch (a) {
            case FORWARD:
                if (room_->IsValidPosition(&next)) {
                    *robot_position_ = next;
                } else {
                    collision_ = true;
                }
                break;
            case RIGHT_90:
                robot_position_->RotateRight();
                break;
            case LEFT_90:
                robot_position_->RotateLeft();
                break;
            case CLEAN_DIRT:
                if (room_->CleanSquare(robot_position_)) {
                    //scorer_.IncrementSquaresCleaned();
                }
                break;
            case TURN_OFF:
                //if (!myPosition.CoordinatesEqual(&homePosition)) {
                    //scorer_.TurnedOffNotAtHome();
                //}
                break;
        
        }
    }
    void Environment::ReadSensor(SensorReading *s) {
        s->infared_sensor = home_position_->CoordinatesEqual(robot_position_);
        s->photo_sensor = room_->GetSquare(robot_position_) == DIRT;
        s->touch_sensor = collision_; // Reset on a successful move.
    }
} // namespace aich2