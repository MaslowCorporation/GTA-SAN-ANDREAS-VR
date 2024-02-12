#ifndef CheckLua_H
#define CheckLua_H

//#include <string> // Include string header for std::string

// Lua is a C library, and we're in C++ land,
// so we need extern so things work well
extern "C"
{
#include "../../Dependencies/Lua/include/lua.h"
#include "../../Dependencies/Lua/include/lauxlib.h"
#include "../../Dependencies/Lua/include/lualib.h"
}


bool CheckLua(lua_State *L, int r); // Function declaration

#endif // CheckLua_H
