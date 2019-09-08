#include "common.h"
#include "position.h"

namespace aich2 {
Position::Position(int x, int y, CompassDirection d) {
    x_ = x;
    y_ = y;
    d_ = d;
}

Position::Position() {
    Position(0,0,NORTH);
}

void Position::RotateRight() {
    switch(d_) {
        case NORTH:
            d_ = EAST;
            break;
        case EAST:
            d_ = SOUTH;
            break;
        case SOUTH:
            d_ = WEST;
            break;
        case WEST:
            d_ = NORTH;
            break;
    }
}
void Position::RotateLeft() {
    switch (d_) {
        case NORTH:
            d_ = WEST;
            break;
        case EAST:
            d_ = NORTH;
            break;
        case SOUTH:
            d_ = EAST;
            break;
        case WEST:
            d_ = SOUTH;
            break;
    }
}

int Position::x() const {
    return x_;
}

int Position::y() const {
    return y_;
}

CompassDirection Position::direction() const {
    return d_;
}

bool Position::CoordinatesEqual(const Position *other) {
    return x_ == other->x_ && y_ == other->y_;
}

Position Position::NextPosition() {
    int next_x = x_;
    int next_y = y_;
    CompassDirection next_direction = d_;
    switch (next_direction) {
        case NORTH:
            next_y -= 1;
            break;
        case EAST:
            next_x += 1;
            break;
        case SOUTH:
            next_y += 1;
            break;
        case WEST:
            next_x -= 1;
            break;
    }
    return Position(next_x, next_y, next_direction);
}
} // namespace aich2