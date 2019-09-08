#include "ch2.h"

int main(void) {
    using namespace aich2;
    Room r = Room(2,2);
    Agent a;
    Simulator s = Simulator(&r, &a);
    int score = s.simulate(10);
    return 0;
}