#ifndef AICH2_POSITION_H
#define AICH2_POSITION_H

#include "common.h"

namespace aich2 {
class Position {
    private:
        int x_, y_;
        CompassDirection d_;
    public:
        Position();
        Position(int x, int y, CompassDirection d);
        int x() const;
        int y() const;
        CompassDirection direction() const;
        void RotateLeft();
        void RotateRight();
        Position NextPosition();
        bool CoordinatesEqual(const Position *other);
};
}
#endif