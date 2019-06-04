#ifndef ROOM_H
#define ROOM_H

#include "Objects.h"


struct Room
{
    bool North_wall = false;//simple block flags
    bool West_wall = false;
    bool East_wall = false;
    bool South_wall = false;
    bool exit_room = false; //if you enter this room the game ends and you won.
    Pos Loc;
    //std::vector<Objects*> objects;
    std::vector<Door> Doors;
    std::vector<item> Items;
    std::vector<Event> Events;
    std::string Description; // flaver text for room.

};

#endif // ROOM_H
