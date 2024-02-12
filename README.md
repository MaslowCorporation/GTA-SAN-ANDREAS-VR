# GTA SAN ANDREAS VR Mod 🌎

<p align="center">
  <img src="gta_github_logo.jpg" alt="GTA San Andreas Logo">
</p>

## Hi, amigo vato loco ;-) ! 🎮

Welcome to the world of Grand Theft Auto: San Andreas in VR !

The goal of this Github repository is to document the process of turning Grand Theft Auto: San Andreas Definitive Edition into a VR game, thanks to the fantastic UEVR Mod from Lord Praydog

https://github.com/praydog/UEVR

If the documentation scares you, don't worry ! This README describes in detail each step from zero to hero ;-)

## Step By Step Process

- Download and install the `.Net Runtime` and the `.Net Desktop Runtime` at

https://dotnet.microsoft.com/en-us/download/dotnet/6.0

- Before downloading UEVR, Add your Downloads folder to the exclusion list of your Firewall shizzle

see https://superuser.com/a/1565786 for the how-to

- Download the latest UEVR.zip file at 

https://github.com/praydog/UEVR/releases

- Extract the zip file into the downloads folder you just whitelisted !!!.

- Create shortcut for `UEVRInjector.exe` in your Desktop, for convenience.

- Open the `UEVRInjector.exe` file 
(AS ADMINISTRATOR !!!!!) 
inside the extracted folder.

- Open `GTA San Andreas Definitive Edition`

- Press `Alt + Tab` or `Win Key` or whatever yours is, to make the UEVR menu appear in game, while the game is running.

- Click the little arrow on the top right corner of UEVR,
and select the process corresponding to GTA SA.
It should normally be called `SanAndreas (pid: xxxx) (Grand Theft Auto: San Andreas - The Definitive Edition)`

- Make sure your VR headset is connected and ready, via `Virtual Desktop` or `Link/AirLink` or whatever your shizzle is ;-)

- Click on `Inject`

- Now, the game is projected into your headset. To toggle the UEVR Menu ON/OFF, Press `Inser` on your keyboard, or `L3 + R3` on your gamepad.

(Please note that the UEVR menu toggle works only with a PC gamepad, not with the VR controller, at least in my case, using a Oculus Quest 2. Yours may vary.)

### To be in first person mode

This setup comes from this video, starting at 6:32

https://youtube.com/clip/Ugkx1A9DVj7hwPEf6L0UNmo9HKyKJQQSzK7Z?si=prmGO1gk3vdw7K2a

- Pause the game, and go to the `GRAPHICS` menu.

- Turn ``World Shadow Quality` to `OFF` , to disable shadows, because the in-game shadows are buggy and cause crashes in UEVR (the shadows are displayed in one eye only).

- Toggle `Show advanced settings` on, in the UEVR menu, so the `UObjectHook` menu appears.

- Click on `UObjectHook/main` ,  then click on `Spawn Overlapper`

- Click on `Objects by class` and type (in capital letters !)

```
GTASK
```

to find the specific setting we need. It will narrow down the list of game objects.

- Click on `BlueprintGeneratedClass/Game/SanAndreas/Characters/Player/BP_Player......`

- Click on `BP_Player_Character_C/Game/SanAndreas/Maps/SAWorld/SAWorld......`

- Click on `Attach Camera to (Relative)` 

- Press your RT (Right Trigger) of your PC controller, and use your left and right stick to adjust the camera. Put in inside CJ's head, like at his brain position, or above, you decide how low or high you want it

RT + Left Stick: Move the camera left/right/forward/back
RT + Right Stick: Move the camera up/down
RT + B: Reset camera offset
RT + Y: Recenter view
RT + X: Reset standing origin

- click on `Components` , then click on `GTAPoseableComponent head`

- Toggle `Visible` OFF, then click on `Save Visibility State`

- Click on `Config` , and toggle `Enabled At Startup` ON

- Get out of the `UObjectHook` menu, and go to the `VR` menu, then click on `Camera`

- Toggle `Decoupled Pitch` ON

That's it ! This first person setup is not perfect, but it is 100% playable and fun as it is ;-)

### Let's create a motion controls plugin for driving cars with our VR hands ;-)

Among all the motion controls, the driving motion controls are the most important ones, especially in a game like GTA where driving is a major part of the experience, so, let's roll our sleeves up and let's figure out how to do this.

We will need to create a UEVR plugin to handle this. 

We can create plugins in C++ or Blueprint, or LUA. Let's create a C++ plugin mixed with LUA code ;-).

Let's setup our computer for C++ compilation. I assume you're using a Windows computer, so if you don't, Google for C++ setup for your OS.

- Download Visual Studio at

https://visualstudio.microsoft.com/fr/downloads/

During the installation, install everything related to C++

- Download the latest LUA binary at

https://luabinaries.sourceforge.net/

Download the .zip file at 

`Windows Libraries/Dynamic/lua-x.x.x_Win32_dllw6_lib.zip` 

or 

`Windows Libraries/Dynamic/lua-x.x.x_Win64_dllw6_lib.zip`

depending on your hardware.

- Open Visual Studio, and create a C++ `Console Application` , not a static application. Name this application `CJHandsVR`.
Create a new folder, and choose this new folder as the place where you want to create your Console Application.

- inside the `CJHandsVR/CJHandsVR` folder, create a folder named `Dependencies` . Inside this Dependencies folder create a `Lua` folder.

- Unzip the `lua-x.x.x_WinXX_dllw6_lib.zip` file you downloaded , and copy/paste it's contents inside `CJHandsVR/CJHandsVR/Dependencies/Lua`

- Copy/paste the `CJHandsVR/CJHandsVR/Dependencies/Lua/luaxx.dll` to `CJHandsVR/CJHandsVR/luaxx.dll`.

So now there should be 2 `luaxx.dll` files in your project.

(NOTE: the xx is a number, that evolves over time depending on the latest release)

- Create a folder `CJHandsVR/CJHandsVR/Dependencies/CheckLua` .
Create a file `CheckLua.cpp` and `CheckLua.h` .

`CheckLua.cpp` contains

```
#include "CheckLua.h"
#include <iostream>

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

```

`CheckLua.h` contains

```
#ifndef CheckLua_H
#define CheckLua_H

#include <string> // Include string header for std::string

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

```

The goal of the CheckLua function is to check if the Lua script successfully executed or not. It returns a boolean outcome.

- Open the file `CJHandsVR/CJHandsVR/CJHandsVR.cpp` and add this code in it

```
// CJHandsVR.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

// a checker function that checks if the Lua script executed without failure
#include "Dependencies/CheckLua/CheckLua.h"

// Lua is a C library, and we're in C++ land,
// so we need extern so things work well
extern "C"
{
#include "Dependencies/Lua/include/lua.h"
#include "Dependencies/Lua/include/lauxlib.h"
#include "Dependencies/Lua/include/lualib.h"
}

// this pragma is needed for linking the LUA C library to our C++ kingdom
// This practice seems to be frowned upon, but I follwed a tutorial and that's how it's done there,
// and I don't care about programming norms ,
// I just want to mod my VR Game thanks to UEVR ;-) .
// Also, _WIN32 means Windows, it has nothing to do with 32 or 64 bit stuff
#ifdef _WIN32
#pragma comment(lib, "Dependencies/Lua/liblua54.a")
#endif

int main()
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

    // Uncomment this if you're testing this.bridge outside of a UEVR plugin.
    system("pause");

    // close the LUA VM
    lua_close(L);

    // let's return some shizzle
    return 0;
}

```

What this code does is it executes the `CJHandsVR.lua` file.
The Lua code is some simple arithmetic, for example purposes, but you can do anything Lua allows you to do, and the C++ side grabs the last value in the memory stack of the LUA Virtual Machine. More info and explanation in this video. Don't panic, breathe ;-) thanks to this video, you'll figure out how to pass different data types back & forth between C++ and Lua easily.

https://www.youtube.com/watch?v=4l5HdmPoynw&t=510s

- Create a `CJHandsVR/CJHandsVR/CJHandsVR.lua` file, and add this inside it:

```
local x = 5
local y = 3

print("result on the Lua side is equal to " .. x + y)

local result = x + y
```

- In Visual Studio, execute the `CJHandsVR.cpp` file of your C++ project. you will encounter troubles, because the CheckLua folder is not added to your C++ Visual Studio Project, but don't worry, this StackOverflow post will help you fix this very simply:

https://stackoverflow.com/a/12490073

I add the comment here in case the other gets deleted

```
If you choose Project and then All Files in the menu, all files should be displayed in the Solution Explorer that are physically in your project map, but not (yet) included in your project. If you right click on the file/folder you want to add in the Solution Explorer, you can include it.
```

Once the missing shizzle is added, rerun your project, and a command line window will open. It works !

- Now, you have a working C++ project, that can interact with any Lua code known to mandkind ;-) Let's turn this C++ project into a UEVR C++ project !

Create a folder `CJHandsVR/CJHandsVR/Dependencies/CPPLuaBridge` , and create 2 files `CPPLuaBridge.cpp` and `CPPLuaBridge.h`

`CPPLuaBridge.cpp` contains:

```
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

    // Uncomment this if you're testing this.bridge outside of a UEVR plugin.
    //system("pause");

    // close the LUA VM
    lua_close(L);

    // let's return some shizzle
    return 0;
}
```

`CPPLuaBridge.h` contains:

```

#ifndef CPPLuaBridge_H
#define CPPLuaBridge_H


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

```

Open your `CJHandsVR.cpp` file, and replace it's code with this code, coming from 

https://praydog.github.io/uevr-docs/plugins/getting_started.html

```

```

Download the latest `Source code (zip)` file at 

https://github.com/praydog/UEVR/releases

Unzip the file, and locate the folder named `include/uevr` .

Copy/paste this `uevr` folder, to your `CJHandsVR/CJHandsVR/Dependencies` folder, such that there should now be a `CJHandsVR/CJHandsVR/Dependencies/uevr` folder in your project, containing `API.h` , `API.hpp` , and `Plugin.hpp` files.

Add this `CJHandsVR/CJHandsVR/Dependencies/uevr` folder to your project's files, you know the drill by now ;-) . See https://stackoverflow.com/a/12490073 for a quick reminder.

Now, we want to compile a .dll file instead of a .exe file like we did previously.

To do so, Open your CJHandsVR Visual Studio project, then Open `Project/properties` dialog and go to "Configuration Properties/General". On the right side locate the "Configuration Type" item and change it from "Application" to "Dynamic Library".

Then go to `C++/language` and set the `C++ Language Standard` to `ISO C++17`

Once you've done all this, press `CTRL + B` to build your UEVR plugin into a .dll file. If everything is OK, your .dll file will be located in `CJHandsVR\x64\Debug\CJHandsVR.dll` !



