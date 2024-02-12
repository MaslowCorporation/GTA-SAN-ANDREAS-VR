#include "CheckLua.h"
//#include <iostream>

// Little error checking utility function
bool CheckLua(lua_State* L, int r)
{
    if (r != LUA_OK)
    {
        //std::string errormsg = lua_tostring(L, -1);
        //std::cout << errormsg << std::endl;
        return false;
    }

    // std::cout << "The Lua script was successfully executed." << std::endl;

    return true;
}
