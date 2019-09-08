#include "ch2.h"
#include "common.h"
#include "room.h"
#include "scorer.h"
namespace aich2 {

RobotAction Agent::decide(const SensorReading *s) {
    // Default agent implementation does nothing.
    return TURN_OFF;
}

// Simulator
Simulator::Simulator(Room *r, Agent *a) {
    myRoom = r;

    // Initialize Robot Position.
    myPosition = Position(0, 0, NORTH);

    // Initialize Home Position.
    homePosition = Position(0, 0, NORTH);
    collision = false;

    // Initialize sensor.
    readSensor(&mySensorReading);
}

void Simulator::commandRobot(RobotAction a) {
    // Increment actions count.
    scorer_.IncrementActions();

    // Reset collision detection.
    collision = false;
    Position next = myPosition.NextPosition();

    // Perform action.
    switch (a) {
        case FORWARD:
            if (myRoom->IsValidPosition(&next)) {
                myPosition = next;
            } else {
                collision = true;
            }
            break;
        case RIGHT_90:
            myPosition.RotateRight();
            break;
        case LEFT_90:
            myPosition.RotateLeft();
            break;
        case CLEAN_DIRT:
            if (myRoom->CleanSquare(&myPosition)) {
                scorer_.IncrementSquaresCleaned();
            }
            break;
        case TURN_OFF:
            if (!myPosition.CoordinatesEqual(&homePosition)) {
                scorer_.TurnedOffNotAtHome();
            }
            break;
    }
}

void Simulator::readSensor(SensorReading *s) {
    s->infared_sensor = homePosition.CoordinatesEqual(&myPosition);
    s->photo_sensor = myRoom->GetSquare(&myPosition) == DIRT;
    s->touch_sensor = collision; // Reset on a successful move.
}

int Simulator::simulate(int maxSteps) {
    int stepCount = 0;
    bool robotActive = true;
    while (stepCount < maxSteps && robotActive) {
        stepCount++;
        readSensor(&mySensorReading);
        RobotAction nextAction = myAgent->decide(&mySensorReading);
        commandRobot(nextAction);
        robotActive = (nextAction != TURN_OFF);
    }
    return scorer_.score();
}
}  // namespace aich2