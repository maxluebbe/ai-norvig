#include "room.h"

namespace aich2 {
Room::Room(int height, int length) {
    height_ = height;
    length_ = length;
    
    squares = new RoomSquare*[height];
    for (int j = 0; j < height; j++){
        squares[j] = new RoomSquare[length];
        for (int i = 0; i < length; i++) {
            squares[j][i] = EMPTY;
        }
    }
}

Room::~Room() {
    for (int i = 0; i < height_; i++){
        delete[] squares[i];
    }
    delete[] squares;
}

bool Room::SetSquare(int x, int y, RoomSquare rs) {
    if (x >= 0 && y >= 0 && x < length_ && y < height_) {
        squares[y][x] = rs;
        return true;
    }
    return false;
}

RoomSquare Room::GetSquare(const Position *p) {
    return squares[p->y()][p->x()];
}

bool Room::CleanSquare(const Position *p) {
    if (squares[p->y()][p->x()] == DIRT) {
        squares[p->y()][p->x()] = EMPTY;
        return true;
    } else {
        return false;
    }
}

bool Room::IsValidPosition(const Position *p) {
    if (p->x() < 0 || p->x() >= length_) {
        return false;
    } else if (p->y() < 0 || p->y() >= height_) {
        return false;
    } else {
        return squares[p->y()][p->x()] != BLOCKED;
    }
}
} // namespace aich2