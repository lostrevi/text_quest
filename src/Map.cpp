#include "Map.h"

void Map::init()
{
    load_Map_data();
}

void Map::load_Map_data()
{
    std::vector<item> Items_temp; //used to clone
    std::vector<Door> Doors_temp;
    std::vector<Event> Event_temp;

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    if(CheckLua(L, luaL_dofile(L, MAP_DATA_PATH.c_str())))
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
                                    std::cout << "[ C++ Note ] Get text and put into proper vector : " << lua_tostring(L, -1) << "\n";
                                }

                                lua_pop(L, 1);
                            }
                            lua_pop(L, 1);
                        }



                        //send to Temp holder
                        //Doors_temp.push_back(TEMP_DOOR);

                    }

                    lua_pop(L, 1);//used in while loop
                }



                lua_pop(L, 1);//used to get rid of the null
            } //end of Events




            std::cout << "Testing loading (Remove once loading is working 100%)\n";
            //testing
            for(int i = 0; i < Items_temp.size(); i++)
            {
                std::cout << "ITEM| Name : " << Items_temp[i].Name << " | Des : " << Items_temp[i].Description << "\n";
            }

            for(int i = 0; i < Doors_temp.size(); i++)
            {
                std::cout << "Door| Name : " << Doors_temp[i].Name << " | Des : " << Doors_temp[i].Description << "\n";
                std::cout << "\t-->Key needed for door is : " << Doors_temp[i].Key.Name << "\n";
            }


        }


    }

}
