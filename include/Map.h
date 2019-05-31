#ifndef MAP_H
#define MAP_H

#include "Room.h"

class Map
{
    public:
        void init();
        void load_Map_data();

    private:
        std::vector<Room> Rooms;
};

#endif // MAP_H
