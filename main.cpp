#include "world.h"


void Draw_header()
{
    std::cout << "+------------------------------------------------------------------+" << std::endl;
    std::cout << "|  _____           _               _     _ _           _   _____   |" << std::endl;
    std::cout << "| |_   _|         (_)             | |   | (_)         | | / __  \\  |" << std::endl;
    std::cout << "|   | |_   _ _ __  _ _ __   __ _  | |__ | |_ _ __   __| | `' / /'  |" << std::endl;
    std::cout << "|   | | | | | '_ \\| | '_ \\ / _` | | '_ \\| | | '_ \\ / _` |   / /    |" << std::endl;
    std::cout << "|   | | |_| | |_) | | | | | (_| | | |_) | | | | | | (_| | ./ /___  |" << std::endl;
    std::cout << "|   \\_/\\__, | .__/|_|_| |_|\\__, | |_.__/|_|_|_| |_|\\__,_| \\_____/  |" << std::endl;
    std::cout << "|       __/ | |             __/ |                                  |" << std::endl;
    std::cout << "|      |___/|_|            |___/                                   |" << std::endl;
    std::cout << "|                                                                  |" << std::endl;
    std::cout << "+------------------------------------------------------------------+" << std::endl;

    std::cout << "[s] start\n";
}

int main()
{
    srand(time(nullptr)); //seeding random

    /*
    std::cout << " +--------------------------------------------------------------------+" << std::endl;
    std::cout << "|___________              __    ________                          __   |" << std::endl;
    std::cout << "|\\__    ___/___ ___  ____/  |_  \\_____  \\  __ __   ____   _______/  |_ |" << std::endl;
    std::cout << "|  |    |_/ __ \\\\  \\/  /\\   __\\  /  / \\  \\|  |  \\_/ __ \\ /  ___/\\   __\\|" << std::endl;
    std::cout << "|  |    |\\  ___/ >    <  |  |   /   \\_/.  \\  |  /\\  ___/ \\___ \\  |  |  |" << std::endl;
    std::cout << "|  |____| \\___  >__/\\_ \\ |__|   \\_____\\ \\_/____/  \\___  >____  > |__|  |" << std::endl;
    std::cout << "|             \\/      \\/               \\__>           \\/     \\/        |" << std::endl;
    std::cout << " +--------------------------------------------------------------------+" << std::endl;
    */ //old title



    Draw_header();

    std::cout << "[e] exit\n\n>";
    std::string input;
    std::cin >> input;
    if(input == "s" || input == "start" || input == "Start" || input == "START" || input == "S")
    {
        //start a game
        clear_screen();
        Draw_header();
        std::cout << "\t-> [s] Main Game(Working on)\n";
        std::cout << "\t-> [t] Test Room\n";
        std::cout << "\t-> [c] Custom\n>";
        bool Good_input = false;
        while(!Good_input)
        {
            std::cin >> input;

            if(input == "s" || input == "S")
            {
                Good_input = true;
                std::cout << "starting...\n";
                World Master_world;
                Master_world.init(MAP_DATA_PATH_MAIN_GAME);
            }
            else if(input == "t" || input == "T")
            {
                Good_input = true;
                std::cout << "starting...\n";
                World Master_world;
                Master_world.init(MAP_DATA_PATH);
            }
            else if(input == "c" || input == "C")
            {
                Good_input = true;
                std::cout << "\t\t-> Path : ";
                std::string Path;
                std::cin >> Path;
                World Master_world;
                Master_world.init(Path);
            }
        }





    }

    std::cout << "exiting\n";

    return 0;
}



/*
room run order
check for events
if(event A_Flag == N or A_Flag == Flag held by the player)
    Run event code as long is event done is false
finish event code

Then give options listed below.

*/



/*
game play commands

move - you can move N,W,E,S
    -> game will tell you if there is a door by getting the doors Name
Take - pick up item on the floor if there is one
Inv - check to see what items you have
    -> look - shows Des. of item
    -> trash - get rid of an item
open - open door with times on hand
look -> shows door(N,W,E,S) Des or item if (F)


Simple as that all the map data is loaded from file. this includes items and doors.

*/







