#ifndef AICH2_COMMON_H
#define AICH2_COMMON_H
namespace aich2{
enum RoomSquare {EMPTY, DIRT, BLOCKED};
enum RobotAction {FORWARD, RIGHT_90, LEFT_90, CLEAN_DIRT, TURN_OFF};
enum CompassDirection {NORTH, SOUTH, EAST, WEST};

// env?
struct SensorReading {
    bool touch_sensor;
    bool photo_sensor;
    bool infared_sensor;
};

}
#endif