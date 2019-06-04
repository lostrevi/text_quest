#include "world.h"

void World::init()
{
    m_map.init();


    update();
}

void World::update()
{
    while(m_loop)
    {
        Take_command();
    }
}

void World::Take_command()
{
    std::string input = "";

    //EVENT LOGIC BEFORE TAKE_COMMAND LOGIC

    //show room info
    display_current_room_info();

    std::cout << "---------------------------------------------\n>";
    std::cin >> input;

    if(input == "ping") //test command
    {
        std::cout << "\t -> Pong\n";
    }
    else
    {
        std::cout << "----Help----\n";
        std::cout << "ping - Test command\n";
    }


}



void World::display_current_room_info()
{
    Room current_r = m_map.Get_room(m_player.Loc);

    std::cout << "Room : [" << current_r.Loc.x << " , " << current_r.Loc.y << "]\n";
    std::cout << "Des : " << current_r.Description << "\n\n";
    std::cout << "-------------------------\n";

    std::cout << "Room commands\n";
    std::cout << "-------------------------\n";
    if(!current_r.North_wall)
    {
        bool doorFound = false;
        for(int i = 0; i < current_r.Doors.size(); i++)
        {
            if(current_r.Doors[i].facing == 'n')
            {
               std::cout << "[n] Try to open the " << current_r.Doors[i].Description << "\n";
               doorFound = true;
            }
        }
        if(!doorFound)
            std::cout << "[n] Move North\n";
    }

    if(!current_r.West_wall)
    {
        bool doorFound = false;
        for(int i = 0; i < current_r.Doors.size(); i++)
        {
            if(current_r.Doors[i].facing == 'w')
            {
               std::cout << "[w] Try to open the " << current_r.Doors[i].Description << "\n";
               doorFound = true;
            }
        }
        if(!doorFound)
            std::cout << "[w] Move West\n";
    }

    if(!current_r.East_wall)
    {
        bool doorFound = false;
        for(int i = 0; i < current_r.Doors.size(); i++)
        {
            if(current_r.Doors[i].facing == 'e')
            {
               std::cout << "[e] Try to open the " << current_r.Doors[i].Description << "\n";
               doorFound = true;
            }
        }
        if(!doorFound)
            std::cout << "[e] Move East\n";
    }

    if(!current_r.South_wall)
    {
        bool doorFound = false;
        for(int i = 0; i < current_r.Doors.size(); i++)
        {
            if(current_r.Doors[i].facing == 's')
            {
               std::cout << "[s] Try to open the " << current_r.Doors[i].Description << "\n";
               doorFound = true;
            }
        }
        if(!doorFound)
            std::cout << "[s] Move South\n";
    }


        if(current_r.Items.size() > 0)
        {
            std::cout << "[g] There is something on the ground\n";
        }



}













