#include "Objects.h"



void Door::Unlock_door(std::vector<item> Items)
{
    std::cout << " You go to open the door.\n";
    if(Locked)
    {
        if(rand()% 2 == 1)
            std::cout << "\"Damn it's locked\"\n";
        else
            std::cout << "\"Locked!\"\n";

        std::cout << "You try to unlock it ...";


        bool door_unlocked = false;
        for(int i = 0; i < Items.size(); i++)
        {
            if(Items[i].Name == Key.Name)
                door_unlocked = true;
        }

        if(door_unlocked)
        {
            std::cout << "\nThe door is unlocked thanks to the item : " << Key.Name << " \n";
            Locked = false;
        }
        else
        {
            std::cout << "\nNothing you have was able to unlock the door\n";
        }

    }
    else
    {
        std::cout << "The door was unlocked\n";
    }
}
