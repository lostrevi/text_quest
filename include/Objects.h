#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <cstdlib>

extern "C"
{
#include "../LUA535/include/lua.h"
#include "../LUA535/include/lauxlib.h"
#include "../LUA535/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "LUA535/liblua53.a")
#endif

//movement note
//check for paths on the map
//then check for doors facing that direction
//then give options
//locked doors can't be walked thought


const static std::string MAP_DATA_PATH = "Data/Map_data.lua";


// Little error checking utility function
static bool CheckLua(lua_State *L, int r)
{
	if (r != LUA_OK)
	{
		std::string errormsg = lua_tostring(L, -1);
		std::cout << "[lua Error] " << errormsg << std::endl;
		return false;
	}
	return true;
}



struct item
{
    std::string Name;
    std::string Description;
    bool Useable;
    bool delete_me = false;
};


struct Pos
{
    int x;
    int y;
};


struct Objects
{
    Pos Loc;
    bool used_dead = false;
};

struct Chest : public Objects //not being used
{
    item Item_inside;
    bool opened = false;
};

struct Door : public Objects
{
    bool Locked;
    std::string Name;
    std::string Description;
    item Key;
    void Unlock_door(std::vector<item> Items);
    char facing; // n = north, s = south, e = east, w = west;
};

//Flag is just a string that it checks the name of to see if it has been activated.

struct Event
{
    std::string Flag_Active;
    std::string Name;
    std::string Event_text;
    std::vector<std::string> Options;
    std::vector<std::string> Flags; //used to give flags
    bool Done = false;
};

#endif // OBJECTS_H
