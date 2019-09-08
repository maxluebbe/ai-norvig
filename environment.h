#ifndef AICH2_ENVIRONMENT_H
#define AICH2_ENVIRONMENT_H

#include "common.h"
#include "position.h"
#include "room.h"

namespace aich2 {
class Environment {
    private:
        Room *room_;
        Position *robot_position_, *home_position_;
        bool collision_;
    public:
        explicit Environment(Room *r=0, Position *robot=0, Position *home=0);
        void CommandRobot(RobotAction a);
        void ReadSensor(SensorReading *s);
};
} // namespace aich2
#endif