#include "Objects.h"



void Door::Unlock_door(std::vector<item> Items)
{

    std::cout << "\t You go to open the door.\n";
    if(Locked)
    {
        if(rand()% 2 == 1)
            std::cout << "\t\"Damn, it's locked.\"\n";
        else if(rand()% 2 == 1)
            std::cout << "\t\"Locked!\"\n";
        else
            std::cout << "\t\"I can't get it opened.\"";

        std::cout << "\tYou try to open it ...";


        bool door_unlocked = false;
        for(int i = 0; i < Items.size(); i++)
        {
            if(Items[i].Name == Key.Name)
                door_unlocked = true;
        }

        if(door_unlocked)
        {
            std::cout << "\t\nYou were able to get it opened thanks to : " << Key.Name << " \n";
            Locked = false;
        }
        else
        {
            std::cout << "\t\nNothing you have was able to open it\n";
        }

    }
    else
    {
        std::cout << "\tIt was unlocked\n";
    }
    std::cout << "+--------------------------------------------+\n";
}
