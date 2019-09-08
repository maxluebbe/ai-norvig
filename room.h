#ifndef AICH2_ROOM_H
#define AICH2_ROOM_H

#include "common.h"
#include "position.h"

namespace aich2 {
/**
 * Representation of a Room to be vaccumed. 
 */
class Room {
    private:
        int height_, length_;
        RoomSquare **squares;
    public:
        Room(int height, int length);
        ~Room();
        // Return contents of given position in Room.
        RoomSquare GetSquare(const Position *p);
        // If square contains dirt, remove it and return true. Return false otherwise.
        bool CleanSquare(const Position *p);
        // Return true if position is possible for Robot to occupy.
        bool IsValidPosition(const Position *p);
        // Set position in room with given type of square. Returns false if out of bounds.
        bool SetSquare(int x, int y, RoomSquare s);
};
}
#endif