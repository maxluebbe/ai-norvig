/**
 * Artificial Intelligence (Russell & Norvig) - Chapter 2 - Common Library
 * 
 * Code for implementing Vaccuum Robot Simulation.
 * 
 * Max Luebbe - August 2019
 */

#ifndef CH2_H
#define CH2_H

#include "common.h"
#include "position.h"
#include "room.h"
#include "scorer.h"

namespace aich2 {

/**
 * Base class for implementing a Vaccuuming AI Agent.
 * Default implementation just turns the robot off.
 */
class Agent {
    public:
        RobotAction decide(const SensorReading *s);
};

class Simulator {

    private:
        Room *myRoom;
        Position myPosition, homePosition;
        SensorReading mySensorReading;
        Agent *myAgent;
        bool collision;
        Scorer scorer_;
        void commandRobot(RobotAction a);
        void readSensor(SensorReading *s);

    public:
        // Constructor builds robot, takes room and agent as params.
        Simulator(Room *r, Agent *a);
        
        /**
         * Run simulation. Returns performance score.
         */
        int simulate(int maxSteps);
};

} // namespace aich2
#endif