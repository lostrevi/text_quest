#include "Map.h"

void Map::init(std::string PATH)
{
    load_Map_data(PATH);
}

std::vector<Room> Map::Get_rooms()
{
   return Rooms;
}

void Map::draw_Map(Pos player_loc)
{
    std::cout << "Drawing Map | S = starting location | ";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << "P";
    SetConsoleTextAttribute(hConsole,7);
    std::cout << " = Player | # = A room\n";
    std::cout << "Play location [" << player_loc.x << "," << player_loc.y << "]\n";
    std::cout << "-----------------------------------------------\n";

    for( int y = 10; y > -10; y-- )
    {
        for( int x = 20; x > -21; x-- )
        {
                bool room_found = false;
                for(int i = 0; i < Rooms.size(); i++)
                {

                    if(Rooms[i].Loc.x == x && Rooms[i].Loc.y == y && Rooms[i].discovered)
                    {
                        room_found = true;
                        if(player_loc.x == x && player_loc.y == y)
                        {
                            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(hConsole, 10);
                            std::cout << "P";
                            SetConsoleTextAttribute(hConsole, 7);
                        }
                        else if(Rooms[i].Loc.x == 0 && Rooms[i].Loc.y == 0)
                        {
                            std::cout << "S";
                        }
                        else
                        {
                            std::cout << "#";
                        }

                    }
                }
                if(!room_found)
                {
                    std::cout << " ";
                }
        }
        std::cout << "\n";
    }

    std::cout << "Press Enter\n";
    std::cin.get();
    std::cin.ignore();

}

Room Map::Get_room(Pos Loc)
{
    for(int i = 0; i < Rooms.size(); i++)
    {
        if(Rooms[i].Loc.x == Loc.x && Rooms[i].Loc.y == Loc.y)
        {
            return Rooms[i];
        }
    }

    std::cout << "[ C++/lua load ERROR ] Room could not be found or wrong warp\n";
}

Room* Map::Get_room_ref(Pos Loc)
{
    for(int i = 0; i < Rooms.size(); i++)
    {
        if(Rooms[i].Loc.x == Loc.x && Rooms[i].Loc.y == Loc.y)
        {
            return &Rooms[i];
        }
    }

    std::cout << "[ C++/lua load ERROR ] Room could not be found or wrong warp\n";
}

void Map::load_Map_data(std::string PATH)
{
    std::string FILE = PATH;
    std::vector<item> Items_temp; //used to clone
    std::vector<Door> Doors_temp;
    std::vector<Event> Event_temp;

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    if(CheckLua(L, luaL_dofile(L, FILE.c_str())))
    {
        lua_getglobal(L, "Level");
        if(lua_istable(L, -1))
        {
            //Item add
            lua_pushstring(L, "Items"); //this adds a string to -1 which is the key name
            lua_gettable(L, -2); //this puts the table on -1 based on the key name

            if(lua_istable(L, -1))
            {
                lua_pushnil(L);

                while(lua_next(L, -2) != 0) ///////////////////////VERY COOL///////////////////////
                {
                    if(lua_istable(L, -1))
                    {
                        item TEMP_ITEM;

                        lua_pushstring(L, "Name");
                        lua_gettable(L, -2);
                        TEMP_ITEM.Name = lua_tostring(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Description");
                        lua_gettable(L, -2);
                        TEMP_ITEM.Description = lua_tostring(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Useable");
                        lua_gettable(L, -2);
                        TEMP_ITEM.Useable = lua_toboolean(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Flag");
                        lua_gettable(L, -2);
                        TEMP_ITEM.Flag = lua_tostring(L, -1);
                        lua_pop(L, 1);

                        //send to Temp holder
                        Items_temp.push_back(TEMP_ITEM);

                    }

                    lua_pop(L, 1);//used in while loop
                }



                lua_pop(L, 1);//used to get rid of the null
            } //end of Items

            //Doors add
            lua_pushstring(L, "Doors"); //this adds a string to -1 which is the key name
            lua_gettable(L, -2); //this puts the table on -1 based on the key name

            if(lua_istable(L, -1))
            {
                lua_pushnil(L);

                while(lua_next(L, -2) != 0) ///////////////////////VERY COOL///////////////////////
                {
                    if(lua_istable(L, -1))
                    {
                        Door TEMP_DOOR;

                        lua_pushstring(L, "Name");
                        lua_gettable(L, -2);
                        TEMP_DOOR.Name = lua_tostring(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Description");
                        lua_gettable(L, -2);
                        TEMP_DOOR.Description = lua_tostring(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Locked");
                        lua_gettable(L, -2);
                        TEMP_DOOR.Locked = lua_toboolean(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Key");
                        lua_gettable(L, -2);
                        std::string item_target = lua_tostring(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Active_Flag");
                        lua_gettable(L, -2);
                        TEMP_DOOR.Active_Flag = lua_tostring(L, -1);
                        lua_pop(L, 1);

                        //get item
                        bool Found_item = false;
                        for(int i = 0; i < Items_temp.size(); i++)
                        {
                            if(item_target == Items_temp[i].Name)
                            {
                                TEMP_DOOR.Key = Items_temp[i];
                                Found_item = true;
                            }
                        }
                        if(!Found_item)
                            std::cout << "[Lua file Error] Make sure the of the Key for door : \'" << TEMP_DOOR.Name << "/' is correct. key not found\n";


                        //send to Temp holder
                        Doors_temp.push_back(TEMP_DOOR);

                    }

                    lua_pop(L, 1);//used in while loop
                }



                lua_pop(L, 1);//used to get rid of the null
            } //end of Doors



            //Events add
            lua_pushstring(L, "Events"); //this adds a string to -1 which is the key name
            lua_gettable(L, -2); //this puts the table on -1 based on the key name

            if(lua_istable(L, -1))
            {
                lua_pushnil(L);

                while(lua_next(L, -2) != 0) ///////////////////////VERY COOL///////////////////////
                {
                    if(lua_istable(L, -1))
                    {
                        Event TEMP_Event;

                        lua_pushstring(L, "Flag_Active");
                        lua_gettable(L, -2);
                        TEMP_Event.Flag_Active = lua_tostring(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Name");
                        lua_gettable(L, -2);
                        TEMP_Event.Name = lua_tostring(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Event_text");
                        lua_gettable(L, -2);
                        TEMP_Event.Event_text = lua_tostring(L, -1);
                        lua_pop(L, 1);


                        lua_pushstring(L, "Options"); //this adds a string to -1 which is the key name
                        lua_gettable(L, -2); //this puts the table on -1 based on the key name

                        if(lua_istable(L, -1)) //THIS IS SUPER BROKEN RIGHT NOW FIX WHEN HAVE TIME.
                        {
                            lua_pushnil(L);

                            while(lua_next(L, -2) != 0) ///////////////////////VERY COOL///////////////////////
                            {
                                if(lua_isstring(L, -1))
                                {
                                    //std::cout << "[ C++ Note ] Get text and put into proper vector : " << lua_tostring(L, -1) << "\n";
                                    TEMP_Event.Options.push_back(lua_tostring(L, -1));
                                }

                                lua_pop(L, 1);
                            }
                            lua_pop(L, 1);
                        }

                        lua_pushstring(L, "Add_flags"); //this adds a string to -1 which is the key name
                        lua_gettable(L, -2); //this puts the table on -1 based on the key name

                        if(lua_istable(L, -1)) //THIS IS SUPER BROKEN RIGHT NOW FIX WHEN HAVE TIME.
                        {
                            lua_pushnil(L);

                            while(lua_next(L, -2) != 0) ///////////////////////VERY COOL///////////////////////
                            {
                                if(lua_isstring(L, -1))
                                {
                                    //std::cout << "[ C++ Note ] Get text and put into proper vector : " << lua_tostring(L, -1) << "\n";
                                    TEMP_Event.Flags.push_back(lua_tostring(L, -1));
                                }

                                lua_pop(L, 1);
                            }
                            lua_pop(L, 1);
                        }



                        //send to Temp holder
                        Event_temp.push_back(TEMP_Event);

                    }

                    lua_pop(L, 1);//used in while loop
                }



                lua_pop(L, 1);//used to get rid of the null
            } //end of Events




            std::cout << "Testing loading (Remove once loading is working 100%)\n";
            //testing
            for(int i = 0; i < Items_temp.size(); i++)
            {
                std::cout << "ITEM| Name : " << Items_temp[i].Name << " | Des : " << Items_temp[i].Description
                    << "Flag : " << Items_temp[i].Flag << "\n";
            }

            for(int i = 0; i < Doors_temp.size(); i++)
            {
                std::cout << "Door| Name : " << Doors_temp[i].Name << " | Des : " << Doors_temp[i].Description << "\n";
                std::cout << "\t-->Key needed for door is : " << Doors_temp[i].Key.Name << "\n";
            }

            for(int i = 0; i < Event_temp.size(); i++)
            {
                std::cout << "Event| Name : " << Event_temp[i].Name << " | Text : " << Event_temp[i].Event_text << " | A_flag : " << Event_temp[i].Flag_Active << "\n";
                std::cout << "Options : \n";
                for(int x = 0; x < Event_temp[i].Options.size(); x++ )
                {
                    std::cout << "\t->" << Event_temp[i].Options[x] << "\n";
                }
                std::cout << "Flags : \n";
                for(int x = 0; x < Event_temp[i].Flags.size(); x++ )
                {
                    std::cout << "\t->" << Event_temp[i].Flags[x] << "\n";
                }
            }



            //Loading the room from the file.
            //Item ROOMS
            lua_pushstring(L, "Rooms"); //this adds a string to -1 which is the key name
            lua_gettable(L, -2); //this puts the table on -1 based on the key name

            if(lua_istable(L, -1))
            {
                lua_pushnil(L);

                while(lua_next(L, -2) != 0) ///////////////////////VERY COOL///////////////////////
                {
                    if(lua_istable(L, -1))
                    {
                        Room TEMP_ROOM;

                        lua_pushstring(L, "North");
                        lua_gettable(L, -2);
                        TEMP_ROOM.North_wall = lua_toboolean(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "West");
                        lua_gettable(L, -2);
                        TEMP_ROOM.West_wall = lua_toboolean(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "East");
                        lua_gettable(L, -2);
                        TEMP_ROOM.East_wall = lua_toboolean(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "South");
                        lua_gettable(L, -2);
                        TEMP_ROOM.South_wall = lua_toboolean(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Pos_x");
                        lua_gettable(L, -2);
                        TEMP_ROOM.Loc.x = lua_tointeger(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Pos_y");
                        lua_gettable(L, -2);
                        TEMP_ROOM.Loc.y = lua_tointeger(L, -1);
                        lua_pop(L, 1);

                        lua_pushstring(L, "Description");
                        lua_gettable(L, -2);
                        TEMP_ROOM.Description = lua_tostring(L, -1);
                        lua_pop(L, 1);


                        //adding objects
                        lua_pushstring(L, "Objects"); //this adds a string to -1 which is the key name
                        lua_gettable(L, -2); //this puts the table on -1 based on the key name


                        if(lua_istable(L, -1)) //THIS IS SUPER BROKEN RIGHT NOW FIX WHEN HAVE TIME.
                        {
                            lua_pushnil(L);

                            while(lua_next(L, -2) != 0) ///////////////////////VERY COOL///////////////////////
                            {
                                if(lua_isstring(L, -1))
                                {
                                    //std::cout << "[ C++ Note ] Get text and put into proper vector : " << lua_tostring(L, -1) << "\n";
                                    std::string Target = lua_tostring(L, -1);

                                    for(int i = 0; i < Items_temp.size(); i++)
                                    {
                                        if(Items_temp[i].Name == Target)
                                        {
                                            TEMP_ROOM.Items.push_back(Items_temp[i]);
                                        }
                                    }

                                    //for doors the target mus be changed
                                    char Dir = Target[0];
                                    Target.erase (Target.begin());

                                    //std::cout << " [C++ Test] Target : " << Target << " | Dir : " << Dir << "\n";

                                    for(int i = 0; i < Doors_temp.size(); i++)
                                    {
                                        if(Doors_temp[i].Name == Target)
                                        {
                                            Door TEMP = Doors_temp[i];
                                            TEMP.facing = Dir;
                                            TEMP_ROOM.Doors.push_back(TEMP);
                                        }
                                    }

                                }

                                lua_pop(L, 1);
                            }
                            lua_pop(L, 1);
                        }



                       //adding Events
                        lua_pushstring(L, "Events"); //this adds a string to -1 which is the key name
                        lua_gettable(L, -2); //this puts the table on -1 based on the key name


                        if(lua_istable(L, -1)) //THIS IS SUPER BROKEN RIGHT NOW FIX WHEN HAVE TIME.
                        {
                            lua_pushnil(L);

                            while(lua_next(L, -2) != 0) ///////////////////////VERY COOL///////////////////////
                            {
                                if(lua_isstring(L, -1))
                                {
                                    //std::cout << "[ C++ Note ] Get text and put into proper vector : " << lua_tostring(L, -1) << "\n";
                                    std::string Target = lua_tostring(L, -1);

                                    for(int i = 0; i < Event_temp.size(); i++)
                                    {
                                        if(Event_temp[i].Name == Target)
                                        {
                                            TEMP_ROOM.Events.push_back(Event_temp[i]);
                                        }
                                    }

                                }

                                lua_pop(L, 1);
                            }
                            lua_pop(L, 1);
                        }


                        lua_pushstring(L, "exitRoom");
                        lua_gettable(L, -2);
                        TEMP_ROOM.exit_room = lua_toboolean(L, -1);
                        lua_pop(L, 1);


                        //send to Temp holder
                        Rooms.push_back(TEMP_ROOM);

                    }

                    lua_pop(L, 1);//used in while loop
                }



                lua_pop(L, 1);//used to get rid of the null
            } //end of ROOM


        }


    }

    //Everything should be done and loaded at this point

    std::cout << "\n Room Data looker (Remove once loading via lua is tested and shown to be working)\n";
    for(int i = 0; i < Rooms.size(); i++)
    {
        std::cout << "--------------------------------\n";
        std::cout << "Room (x,y) : " << Rooms[i].Loc.x << " , " << Rooms[i].Loc.y;
        if(Rooms[i].exit_room)
            std::cout << " [EXIT ROOM] ";
        std::cout << "\n";
        std::cout << "Open Directions : ";
        if(!Rooms[i].North_wall)
            std::cout << " North ,";
        if(!Rooms[i].West_wall)
            std::cout << " West ,";
        if(!Rooms[i].East_wall)
            std::cout << " East ,";
        if(!Rooms[i].South_wall)
            std::cout << " South ,";
        std::cout << "\n";

        std::cout << "Description : " << Rooms[i].Description << "\n";
        std::cout << "Doors in room: \n";
        for(int x = 0; x < Rooms[i].Doors.size(); x++)
        {
            std::cout << Rooms[i].Doors[x].Name << " | " << Rooms[i].Doors[x].Description
            << " | Facing : " << Rooms[i].Doors[x].facing << "\n";
        }
        std::cout << "Doors in Items: \n";
        for(int x = 0; x < Rooms[i].Items.size(); x++)
        {
            std::cout << Rooms[i].Items[x].Name << " | " << Rooms[i].Items[x].Description << "\n";
        }

        std::cout << "Events : (if any) \n";
        for(int x = 0; x < Rooms[i].Events.size(); x++ )
        {
            std::cout << Rooms[i].Events[x].Name << " | " << "Active Flag: " << Rooms[i].Events[x].Flag_Active
                << " | Text : " << Rooms[i].Events[x].Event_text << "\n";
        }


    }



}
