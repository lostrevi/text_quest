#ifndef WORLD_H
#define WORLD_H

#include "Map.h"

struct Player //might move later
{
    Pos Loc = {0,0}; //this should always be that
    std::vector<std::string> Flags; //this is where he will keep flags
    std::vector<item> Invetory; //this invetory wowowowowo.
    bool dead = false;
};


class World
{
    public:
        void init();
        void update();
        void Take_command();

    private:
        void display_current_room_info();
        void Check_and_do_event();

        Map m_map;
        Player m_player;

        bool m_loop = true;
};

#endif // WORLD_H
