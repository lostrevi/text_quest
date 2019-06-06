#ifndef MAP_H
#define MAP_H

#include "Room.h"

class Map
{
    public:
        void init(std::string PATH);
        void load_Map_data(std::string PATH);

        void draw_Map(Pos player_loc);

        Room Get_room(Pos Loc);
        Room* Get_room_ref(Pos Loc);

        std::vector<Room> Get_rooms();

    private:
        std::vector<Room> Rooms;
};

#endif // MAP_H
