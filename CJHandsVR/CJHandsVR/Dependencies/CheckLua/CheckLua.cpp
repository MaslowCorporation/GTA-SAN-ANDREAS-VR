#include "CheckLua.h"
#include <iostream>

// Lua is a C library, and we're in C++ land,
// so we need extern so things work well
extern "C"
{
#include "../../Dependencies/Lua/include/lua.h"
#include "../../Dependencies/Lua/include/lauxlib.h"
#include "../../Dependencies/Lua/include/lualib.h"
}

// Little error checking utility function
bool CheckLua(lua_State *L, int r)
{
    if (r != LUA_OK)
    {
        std::string errormsg = lua_tostring(L, -1);
        std::cout << errormsg << std::endl;
        return false;
    }

    // std::cout << "The Lua script was successfully executed." << std::endl;

    return true;
}
