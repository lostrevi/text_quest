#include "world.h"

void World::init(std::string PATH)
{
    m_map.init(PATH);

    clear_screen();
    update();
}

void World::update()
{
    bool win = false;
    while(m_loop)
    {
        if( m_map.Get_room(m_player.Loc).exit_room )
        {
            m_loop = false;
            win = true;
            break;
        }


        Take_command();
    }

    //Do win state stuff
    if(win)
    {
        clear_screen();

        std::cout << "	           .---.                                                 " << std::endl;
        std::cout << "          /. ./|  ,--,                                             " << std::endl;
        std::cout << "      .--'.  ' ;,--.'|         ,---,      ,---,             __  ,-." << std::endl;
        std::cout << "     /__./ \\ : ||  |,      ,-+-. /  | ,-+-. /  |          ,' ,'/ /|" << std::endl;
        std::cout << " .--'.  '   \\' .`--'_     ,--.'|'   |,--.'|'   |   ,---.  '  | |' |" << std::endl;
        std::cout << "/___/ \\ |    ' ',' ,'|   |   |  ,\"' |   |  ,\"' |  /     \\ |  |   ,'" << std::endl;
        std::cout << ";   \\  \\;      :'  | |   |   | /  | |   | /  | | /    /  |'  :  /  " << std::endl;
        std::cout << " \\   ;  `      ||  | :   |   | |  | |   | |  | |.    ' / ||  | '   " << std::endl;
        std::cout << "  .   \\    .\\  ;'  : |__ |   | |  |/|   | |  |/ '   ;   /|;  : |   " << std::endl;
        std::cout << "   \\   \\   ' \\ ||  | '.'||   | |--' |   | |--'  '   |  / ||  , ;   " << std::endl;
        std::cout << "    :   '  |--\" ;  :    ;|   |/     |   |/      |   :    | ---'    " << std::endl;
        std::cout << "     \\   \\ ;    |  ,   / '---'      '---'        \\   \\  /          " << std::endl;
        std::cout << "      '---\"      ---`-'                           `----'           " << std::endl;
        std::cout << "                                                                   " << std::endl;
        std::cout << "-------------------------------------------------------------------\n";
        std::cout << "You did it you were able to get out!\n";
        std::cout << "Hit Enter to exit.\n";
        std::cin.get();
        std::cin.ignore();

    }

}

void World::Take_command()
{
    std::string input = "";
    //clear_screen();

    //debug
        //std::cout << "m_play (x,y) : " << m_player.Loc.x << " , " << m_player.Loc.y << "\n";

    //EVENT LOGIC BEFORE TAKE_COMMAND LOGIC
    Check_and_do_event();
    Check_door_Flags();

    //show room info
    display_current_room_info();
    Room *current_r = m_map.Get_room_ref(m_player.Loc);
    current_r->discovered = true;



    std::cout << "---------------------------------------------\n>";
    std::cin >> input;

    clear_screen();

    if(input == "ping") //test command
    {
        std::cout << "\t -> Pong\n";
    }
    else if(input == "n" || input == "N" || input == "north")
    {
        if(!current_r->North_wall)
        {
            bool door_not_found = true;
            for(int i = 0; i < current_r->Doors.size(); i++ )
            {
                if(current_r->Doors[i].facing == 'n')
                {
                    door_not_found = false;
                    std::cout << "You walk North to the " << current_r->Doors[i].Description << "\n";
                    if(!current_r->Doors[i].Locked)
                    {
                        //std::cout << "You open the unlocked door.\n";
                        m_player.Loc.y ++;
                    }
                    else
                    {
                        //std::cout << "you try to unlock it with your items\n";
                        current_r->Doors[i].Unlock_door(m_player.Invetory);
                    }
                }

            }

            if(door_not_found)
            {
                std::cout << "You walk thought the path.\n";
                m_player.Loc.y ++;
            }

        }
        else
            std::cout << "You walk into a wall\n";
    }
    else if(input == "w" || input == "W" || input == "west")
    {
        if(!current_r->West_wall)
        {
            bool door_not_found = true;
            for(int i = 0; i < current_r->Doors.size(); i++ )
            {
                if(current_r->Doors[i].facing == 'w')
                {
                    door_not_found = false;
                    std::cout << "You walk West to the " << current_r->Doors[i].Description << "\n";
                    if(!current_r->Doors[i].Locked)
                    {
                        //std::cout << "You open the unlocked door.\n";
                        m_player.Loc.x --;
                    }
                    else
                    {
                        //std::cout << "you try to unlock it with your items\n";
                        current_r->Doors[i].Unlock_door(m_player.Invetory);
                    }
                }

            }
            if(door_not_found)
            {
                std::cout << "You walk thought the path.\n";
                m_player.Loc.x --;
            }
        }
        else
            std::cout << "You walk into a wall\n";
    }
    else if(input == "e" || input == "E" || input == "east")
    {
        if(!current_r->East_wall)
        {
            bool door_not_found = true;
            for(int i = 0; i < current_r->Doors.size(); i++ )
            {
                if(current_r->Doors[i].facing == 'e')
                {
                    door_not_found = false;
                    std::cout << "You walk East to the " << current_r->Doors[i].Description << "\n";
                    if(!current_r->Doors[i].Locked)
                    {
                        //std::cout << "You open the unlocked door.\n";
                        m_player.Loc.x ++;
                    }
                    else
                    {
                        //std::cout << "you try to unlock it with your items\n";
                        current_r->Doors[i].Unlock_door(m_player.Invetory);
                    }
                }

            }
            if(door_not_found)
            {
                std::cout << "You walk thought the path.\n";
                m_player.Loc.x ++;
            }
        }
        else
            std::cout << "You walk into a wall\n";
    }
    else if(input == "s" || input == "S" || input == "south")
    {
        if(!current_r->South_wall)
        {
            bool door_not_found = true;
            for(int i = 0; i < current_r->Doors.size(); i++ )
            {
                if(current_r->Doors[i].facing == 's')
                {
                    door_not_found = false;
                    std::cout << "You walk South to the " << current_r->Doors[i].Description << "\n";
                    if(!current_r->Doors[i].Locked)
                    {
                        //std::cout << "You open the unlocked door.\n";
                        m_player.Loc.y --;
                    }
                    else
                    {
                        //std::cout << "you try to unlock it with your items\n";
                        current_r->Doors[i].Unlock_door(m_player.Invetory);
                    }
                }

            }
            if(door_not_found)
            {
                std::cout << "You walk thought the path.\n";
                m_player.Loc.y --;
            }
        }
        else
            std::cout << "You walk into a wall\n";
    }
    else if(input == "g" || input == "G")
    {
        std::cout << "You look at the ground and see...";
        if(current_r->Items.size() > 0)
        {
            for( int i = 0; i < current_r->Items.size(); i++ )
            {
                bool Good_input = false;
                while(!Good_input)
                {
                    std::cout << current_r->Items[i].Description << "\n do you want to pick it up (y/n)";
                    std::string input = "";
                    std::cin >> input;

                    if(input == "y" || input == "Y" || input == "yes" || input == "YES")
                    {
                        Good_input = true;

                        if(current_r->Items[i].Flag != "N") //added flag as long as it's not "N"
                            m_player.Flags.push_back(current_r->Items[i].Flag);

                        m_player.Invetory.push_back(current_r->Items[i]);
                                //this should remove items from the room vector
                                if(i != 0)
                                    current_r->Items.erase(current_r->Items.begin() + i);
                                if(i == 0)
                                    current_r->Items.erase(current_r->Items.begin());

                    }
                    else if(input == "n" || input == "N" || input == "no" || input == "NO")
                    {
                        std::cout << "You leave it there.\n";
                        Good_input = true;
                    }
                }
            }
        }
        else
        {
            std::cout << "Nothing\n";
        }
    }
    else if(input == "i" || input == "I" || input == "inventory")
    {
        std::cout << "+----------------------------------------+\n";
        std::cout << "|                  ITEMS                 |\n";
        std::cout << "+----------------------------------------+\n";

        if(m_player.Invetory.size() == 0)
            std::cout << "...Nothing\n";

        for(int i = 0; i < m_player.Invetory.size(); i++)
        {
            if(m_player.Invetory[i].Useable)
                std::cout << "U";
            else if(m_player.Invetory[i].delete_me)
                std::cout << "D";
            else
                std::cout << " ";
            std::cout << "-> " << m_player.Invetory[i].Name << " | " << m_player.Invetory[i].Description << "\n";
        }
    }
    else if(input == "m" || input == "M" || input == "map" || input == "MAP" || input == "Map")
    {
        clear_screen();
        m_map.draw_Map(m_player.Loc);
        clear_screen();
    }
    else
    {
        std::cout << "+-----------------------------------+\n";
        std::cout << "|       +   ----Help----   +        |\n";
        std::cout << "| [n] move North/open North door    |\n";
        std::cout << "| [w] move West/open West door      |\n";
        std::cout << "| [e] move East/open East door      |\n";
        std::cout << "| [s] move South/open South door    |\n";
        std::cout << "| [g] Look at whats on the ground   |\n";
        std::cout << "| [i] check you Inventory           |\n";
        std::cout << "| [m] view map                      |\n";
        std::cout << "| [ping] - Test command             |\n";
        std::cout << "+-----------------------------------+\n";
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
                if(current_r.Doors[i].Locked)
                    std::cout << "[n] Try to open the " << current_r.Doors[i].Description << "\n";
                else
                {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 10);
                        std::cout << "[n] Opened the " << current_r.Doors[i].Description << "\n";
                        SetConsoleTextAttribute(hConsole, 7);
                }

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
                if(current_r.Doors[i].Locked)
                    std::cout << "[w] Try to open the " << current_r.Doors[i].Description << "\n";
                else
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 10);
                        std::cout << "[w] Opened the " << current_r.Doors[i].Description << "\n";
                        SetConsoleTextAttribute(hConsole, 7);
                    }
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
                if(current_r.Doors[i].Locked)
                    std::cout << "[e] Try to open the " << current_r.Doors[i].Description << "\n";
                else
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 10);
                        std::cout << "[e] Opened the " << current_r.Doors[i].Description << "\n";
                        SetConsoleTextAttribute(hConsole, 7);
                    }
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
                if(current_r.Doors[i].Locked)
                    std::cout << "[s] Try to open the " << current_r.Doors[i].Description << "\n";
                else
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, 10);
                        std::cout << "[s] Opened the " << current_r.Doors[i].Description << "\n";
                        SetConsoleTextAttribute(hConsole, 7);
                    }
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

void World::Check_door_Flags()
{
    Room *current_r = m_map.Get_room_ref(m_player.Loc);

    for( int i = 0; i < current_r->Doors.size(); i++ )
    {
        for( int x = 0; x < m_player.Flags.size(); x++ )
        {
            if( current_r->Doors[i].Active_Flag == m_player.Flags[x] )
            {
                if(current_r->Doors[i].Locked && current_r->Doors[i].Active_Flag != "N" )
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 12);

                    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                    std::cout << "!!! -> You hear something click.!!!\n";
                    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";

                    SetConsoleTextAttribute(hConsole, 7);

                    current_r->Doors[i].Locked = false;
                }
            }
        }
    }

}

void World::Check_and_do_event()
{
    //Resrived event flags R = Redo event (later) | N = Do nothing

    bool Redo_event = false;

    Room *current_r = m_map.Get_room_ref(m_player.Loc);

    for(int i = 0; i < current_r->Events.size(); i++)
    {
        if(!current_r->Events[i].Done) // make sure event is not done yet
        {
            bool Do_event = false;
                for(int x = 0; x < m_player.Flags.size(); x++) //check player flags
                {
                    if(current_r->Events[i].Flag_Active == m_player.Flags[x])
                    {
                        Do_event = true;
                    }
                }
                if(current_r->Events[i].Flag_Active == "N") //see it a auto event with "N"
                    Do_event = true;



                if(Do_event) // run the event
                {
                    std::cout << "+---------------------------------+\n";
                    std::cout << "|               EVENT             |\n";
                    std::cout << "+---------------------------------+\n";

                    std::cout << current_r->Events[i].Event_text << "\n";
                    std::cout << "----------------------------------\n";
                    for(int z = 0; z < current_r->Events[i].Options.size(); z++)
                    {
                        std::cout << "[" << z+1 << "] " << current_r->Events[i].Options[z];
                        std::cout << std::endl;
                    }

                    bool Good_input = false;

                    while(!Good_input)
                    {
                       std::cout << ">";
                       std::string INPUT = "";
                       std::cin >> INPUT;

                       int Index = std::atoi(INPUT.c_str());

                       if(Index <= current_r->Events[i].Options.size() + 1  && Index > 0)
                       {
                           //good
                           if(current_r->Events[i].Flags[Index - 1] != "N" && current_r->Events[i].Flags[Index - 1] != "R")
                           {
                                m_player.Flags.push_back(current_r->Events[i].Flags[Index - 1]);
                           }

                           if(current_r->Events[i].Flags[Index - 1] == "R")
                           {
                               Redo_event = true;
                           }


                           Good_input = true;
                       }
                       else
                       {
                           std::cout << "Input was not one of the options.\n";
                       }

                    }

                    if(!Redo_event)
                    current_r->Events[i].Done = true; //close the event
                }

        }
    }
}













