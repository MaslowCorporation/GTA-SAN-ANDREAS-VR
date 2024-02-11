#include "CPPLuaBridge.h"
#include <iostream>

// a checker function that checks if the Lua script executed without failure
#include "../../Dependencies/CheckLua/CheckLua.h"

// Lua is a C library, and we're in C++ land,
// so we need extern so things work well
extern "C"
{
#include "../../Dependencies/Lua/include/lua.h"
#include "../../Dependencies/Lua/include/lauxlib.h"
#include "../../Dependencies/Lua/include/lualib.h"
}

// Let's create a bridge between C++ land & Lua land.
int CPPLuaBridge()
{

    // Create a LUA Virtual Machine
    lua_State *L = luaL_newstate();

    // setup the default Lua library
    // (print(""), etc...)
    luaL_openlibs(L);

    // luaL_openlibs(L);
    int r = luaL_dofile(L, "CJHandsVR.lua");

    // execute the LUA script, and check the output
    if (CheckLua(L, r))
    {
        // get the last variable in the memory stack of the LUA VM
        lua_getglobal(L, "a");

        // if this variable's value is a number...
        if (lua_isnumber(L, -1))
        {
            // convert this LUA value into it's C++ twin
            float result_in_cpp = (float)lua_tonumber(L, -1);

            // print some shizzle on the C++ side
            std::cout << "a on the C++ side is equal to " << result_in_cpp << std::endl;
        }
    }

    system("pause");

    // close the LUA VM
    lua_close(L);

    // let's return some shizzle
    return 0;
}