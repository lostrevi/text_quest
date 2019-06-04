#ifndef MAP_H
#define MAP_H

#include "Room.h"

class Map
{
    public:
        void init();
        void load_Map_data();

        void draw_Map();

        Room Get_room(Pos Loc);
        Room* Get_room_ref(Pos Loc);

        std::vector<Room> Get_rooms();

    private:
        std::vector<Room> Rooms;
};

#endif // MAP_H
