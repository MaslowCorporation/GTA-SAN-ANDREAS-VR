#ifndef CPPLuaBridge_H
#define CPPLuaBridge_H

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

int CPPLuaBridge(); // Function declaration

#endif // CPPLuaBridge_H
