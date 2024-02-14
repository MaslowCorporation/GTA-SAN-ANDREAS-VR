# GTA SAN ANDREAS VR Mod 🌎

<p align="center">
  <img src="pics/gta_logo.jpg" alt="GTA San Andreas Logo">
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

We can create plugins in C++ or Blueprint, or LUA. Let's create a C++ plugin. It's the simplest way. Lua would be better, but the UE4SS setup can be tedious ;-).

Let's setup our computer for C++ compilation. I assume you're using a Windows computer, so if you don't, Google for C++ setup for your OS.

- Download Visual Studio at

https://visualstudio.microsoft.com/fr/downloads/

During the installation, install everything related to C++ Desktop Console. Install Node.js Desktop stuff too.

Create a folder named `CJHandsVR` somewhere in your computer, then create a `C++ Dynamic-Link Library (DLL)` Visual Studio project inside this folder, named `CJHandsVR`. Choose the folder you just created as the `Location` of the newly created project.

Open your `CJHandsVR/CJHandsVR/dllmain.cpp` file, and replace it's code with this code, coming from 

https://praydog.github.io/uevr-docs/plugins/getting_started.html

```

// dllmain.cpp : Defines the entry point for the DLL application.

#include <memory>

#include "Dependencies/uevr/Plugin.hpp"

using namespace uevr;

#define PLUGIN_LOG_ONCE(...)                   \
    {                                          \
        static bool _logged_ = false;          \
        if (!_logged_)                         \
        {                                      \
            _logged_ = true;                   \
            API::get()->log_info(__VA_ARGS__); \
        }                                      \
    }

class CJHandsVR : public uevr::Plugin
{
public:
    CJHandsVR() = default;

    void on_dllmain() override {}

    void on_initialize() override
    {
        // Logs to the appdata UnrealVRMod log.txt file
        API::get()->log_info("%s %s", "Hello, my fellow traveler, this is the CJHandsVR plugin ;-)", "info");
    }

    void on_pre_engine_tick(UEVR_UGameEngineHandle engine, float delta) override
    {
        PLUGIN_LOG_ONCE("Pre Engine Tick: %f", delta);
    }

    void on_xinput_get_state(uint32_t *retval, uint32_t user_index, XINPUT_STATE *state)
    {
        // this tells you if controllers are used or not
        const auto controllers_used = API::get()->param()->vr->is_using_controllers();

        // Using %d for number representation
        // PLUGIN_LOG_ONCE("Controllers used (in tick callback): %d", static_cast<int>(controllers_used));

        PLUGIN_LOG_ONCE("Hello !!")
    }

    void on_post_engine_tick(UEVR_UGameEngineHandle engine, float delta) override
    {
        PLUGIN_LOG_ONCE("Post Slate Draw Window");

        // this tells you if controllers are used or not
        const auto controllers_used = API::get()->param()->vr->is_using_controllers();

        // Using %d for number representation
        PLUGIN_LOG_ONCE("Controllers used: %d", static_cast<int>(controllers_used));
    }

    void on_pre_slate_draw_window(UEVR_FSlateRHIRendererHandle renderer, UEVR_FViewportInfoHandle viewport_info) override
    {
        PLUGIN_LOG_ONCE("Pre Slate Draw Window");
    }

    void on_post_slate_draw_window(UEVR_FSlateRHIRendererHandle renderer, UEVR_FViewportInfoHandle viewport_info) override
    {
        PLUGIN_LOG_ONCE("Post Slate Draw Window");
    }
};

// Actually creates the plugin. Very important that this global is created.
// The fact that it's using std::unique_ptr is not important, as long as the constructor is called in some way.
std::unique_ptr<CJHandsVR> g_plugin{new CJHandsVR()};

```

Download the latest `Source code (zip)` file at 

https://github.com/praydog/UEVR/releases

Unzip the file, and locate the folder named `include/uevr` .

Create a folder `CJHandsVR/CJHandsVR/Dependencies` , then Copy/paste this `uevr` folder, to your `CJHandsVR/CJHandsVR/Dependencies` folder, such that there should now be a `CJHandsVR/CJHandsVR/Dependencies/uevr` folder in your project, containing `API.h` , `API.hpp` , and `Plugin.hpp` files.

Add this `CJHandsVR/CJHandsVR/Dependencies/uevr` folder to your project's files. See https://stackoverflow.com/a/12490073 

Now, we want to compile a .dll file instead of a .exe file like we did previously.

To do so, Open your CJHandsVR Visual Studio project, 

We need to disable precompiled headers in Visual Studio, follow these steps:

1. **Open Project Properties**: Right-click on your project in the Solution Explorer and select "Properties" from the context menu.

2. **Navigate to C/C++**: In the project properties window, expand the "Configuration Properties" node, and then select "C/C++".

3. **Precompiled Headers**: In the C/C++ properties, select the "Precompiled Headers" option.

4. **Set Precompiled Header**: Change the "Precompiled Header" option to "Not Using Precompiled Headers".

5. **Apply Changes**: Click "Apply" or "OK" to save the changes and close the properties window.

Once you've done this, Visual Studio will stop expecting a `pch.h` file and will compile your source files without using precompiled headers. 

then Open `Project/properties` dialog and go to `Configuration Properties/General`. On the right side locate the `Configuration Type` item and make sure it is set to `Dynamic Library`.

Then go to `C++/language` and set the `C++ Language Standard` to `ISO C++17`

Once you've done all this, press `CTRL + B` to build your UEVR plugin into a .dll file. If everything is OK, your .dll file will be located in `CJHandsVR\x64\Debug\CJHandsVR.dll` !


Open your `UEVRInjector.exe` as admin, and click on `Open Global Dir` . It will open a File Explorer to the location where the UEVR game folders are. Locate the `SanAndreas` folder, and copy paste your `CJHandsVR\x64\Debug\CJHandsVR.dll` file inside the `SanAndreas` folder.

Launch your game, and inject UEVR in it. Then navigate to the `Plugins/PluginLoader` menu. Click on `Inject Plugins` to start all the custom game plugins, including the one you just added in your game folder. 

If everything is OK, your plugin will be loaded and you'll get a success message in your UEVR menu.

You can open the `Open Global Dir` in your UEVR main menu, and access the `SanAndreas/log.txt` file within it, to see the printed logs of your plugin, and other logging data, in case of an error. There's also the `SanAndreas/crash.dmp` file that contains other error logs.

Now, we need a debugger, in order to do any meaningful programming work ;-)

To set breakpoints in your plugin code, do the following:

- Open your game, all the way to the actual game.

- Go to the game menu, and go to `OPTIONS / GRAPHICS / DISPLAY MODE` and choose `Windowed`

- Open `UEVRInjector.exe` as admin.

- Inject to your game.

-  Press both of your controller sticks, or the `Inser` key, to make the UEVR menu appear, if not already on-screen, and Unload your plugin in the `PluginLoader/PluginLoader` menu.

- Open your Visual Studio C++ Plugin project, while your game, and UEVR, are running.

- Add your breakpoints in your plugin's cpp file, by click on the vertical var at the left of your editor code, before the line numbers. When you click at a specific line, a red dot appears. That's the breakpoint. Add breakpoints where needed, to inspect the shizzle.

- Go to `Debug/Attach To Process` , And locate the `Attach to` menu.
Type `SanAndreas` to locate the SanAndreas.exe process (AKA your game).

- Double Click on the process to select it.

- In your game, Get in-game, not in a menu.

- Press both of your controller sticks, or the `Inser` key, to make the UEVR menu appear while you're in-game, and reload your plugin, using the `PluginLoader/PluginLoader` menu, so the breakpoint gets hit.

- Go back to your Visual Studio, and you will see that your breakpoint are hit ! Enjoy, and create beautiful things, armed with the power of your C++ debugger.

In order to see the variables in greater detail, in Visual Studio, during debugging, you do these things

Autos While debugging: you can enable 'Autos' which will show you values by every member on your class. Go to menu `Debug->Windows->Autos` to make it appear.

Locals While debugging: you can enable 'Locals' which will show you all variables in the current stack frame. Go to menu `Debug->Windows->Locals` to make it appear.

Watch Although it is a little manually you also can use 'Watch' you can drag and drop any variable to this window or right click then add to watch. Go to menu `Debug->Windows->Watch` to make it appear. Note. You can enable more than one watch window :).

Mouse over Finally you can go over the variable with the mouse and you will see the variable's value.

More coming soon ;-)
