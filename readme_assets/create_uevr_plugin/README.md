
### Let's create a UEVR plugin ;-)

First, Let's setup our computer for C++ compilation. I assume you're using a Windows computer, so if you don't, Google for C++ setup for your OS.

- Download Visual Studio at

https://visualstudio.microsoft.com/fr/downloads/

During the installation, install everything related to C++ Desktop Console. Install Node.js Desktop stuff too.

Create a folder named `VRHands` somewhere in your computer, then create a `C++ Dynamic-Link Library (DLL)` Visual Studio project inside this folder, named `VRHands`. Choose the folder you just created as the `Location` of the newly created project.

Open your `VRHands/VRHands/dllmain.cpp` file, and replace it's code with this code.

A skeletal plugin template can be found here.

https://praydog.github.io/uevr-docs/plugins/getting_started.html

The code below is the full plugin code, ready for action ;-)

I added lots of comments so aspiring modders can understand what's going on, and hopefully, getting their hands dirty and improving it, or making something totally different, taking inspiration from it.... The sky is the limit !

[Link to the full plugin code](https://github.com/MaslowCorporation/steam-uevr-wheel/blob/main/dllmain.cpp)

Download the latest `Source code (zip)` file at 

https://github.com/praydog/UEVR/releases

Unzip the file, and locate the folder named `include/uevr` .

Create a folder `VRHands/VRHands/Dependencies` , then Copy/paste this `uevr` folder, to your `VRHands/VRHands/Dependencies` folder, such that there should now be a `VRHands/VRHands/Dependencies/uevr` folder in your project, containing `API.h` , `API.hpp` , and `Plugin.hpp` files.

Add this `VRHands/VRHands/Dependencies/uevr` folder to your Visual Studio project's files. To do so in Visual Studio,
Click on ``Project`` and then ``Show All Files`` in the Visual Studio top menu, all files should be displayed in the Solution Explorer that are physically in your project map, but not (yet) included in your project. If you right click on the file or folder you want to add in the Solution Explorer, and click on `Include In Project` you can include it ;-)

Create a folder named `nlohmann` inside the `Dependencies` folder, and create 2 files in it named:

[json.hpp (Click to get the source code to copy/paste in it)](https://github.com/MaslowCorporation/steam-uevr-wheel/blob/main/Dependencies/nlohmann/json.hpp)

and

[json_fwd.hpp (Click to get the source code to copy/paste in it)](https://github.com/MaslowCorporation/steam-uevr-wheel/blob/main/Dependencies/nlohmann/json_fwd.hpp)

Include those 2 header files to your C++ project.
There should now be a `VRHands/VRHands/Dependencies/nlohmann` folder containing `json.hpp` and `json_fwd.hpp` .

Now, we want to compile a .dll file instead of the default .exe file that Visual Studio produces.

To do so, Open your VRHands Visual Studio project, 

We need to disable precompiled headers in Visual Studio, follow these steps:

1. **Open Project Properties**: Right-click on your project in the Solution Explorer and select `Properties` from the context menu.

2. **Navigate to C/C++**: In the project properties window, expand the `Configuration Properties` node, and expand `C/C++`.

3. **Precompiled Headers**: In the `C/C++` panel, open the `Precompiled Headers` menu.

4. **Set Precompiled Header**: Change the `Precompiled Header` option to `Not Using Precompiled Headers`.

5. **Apply Changes**: Click `Apply` to save the changes. 
Once you've done this, Visual Studio will stop expecting a `pch.h` file 
and will compile your source files without using precompiled headers. 

6. **Navigate to Configuration Properties/General**: Once there, Locate the `Configuration Type` item and make sure it is set to `Dynamic Library (.dll)`.
Then, in the same menu, set the `C++ Language Standard` to `ISO C++20`.
Click `Apply` to save the changes.

Once you've done all this, press `CTRL + B` to build/compile your UEVR plugin into a .dll file. If everything is OK, your .dll file will be located in `VRHands\x64\Debug\VRHands.dll` !


Open your `UEVRInjector.exe` as admin, and click on `Open Global Dir` . It will open a File Explorer to the location where the UEVR game folders are. Locate the `SanAndreas` folder, and copy paste your `VRHands\x64\Debug\VRHands.dll` and your `VRHands\x64\Debug\libzmq-mt-gd-4_3_5.dll` files inside the `SanAndreas/plugins` folder.

Since we will most likely build this plugin many dozens of times during it's development, it will quickly be very annoying to have to constantly copy/paste this .dll between 2 folders....

But thanks to `Symlinks` , we don't have to do this tedious task every time. Now is the best time to set the Symlink that will make our life easier !


Open Windows's CMD (AS Admin !!!)
then run this command to create the desired symlink. 
Adjust the paths according to your own Link and Target described below ;-)

```
mklink "C:\Users\YourWindowsUsername\AppData\Roaming\UnrealVRMod\SanAndreas\plugins\VRHands.dll" "C:\Users\YourWindowsUsername\path\to\your\vr_plugin.dll"
```

Link (typically something like C:\Users\YourWindowsUsername\AppData\Roaming\UnrealVRMod\SanAndreas\plugins\VRHands.dll): This is the path of the symbolic link. 

Target (typically something like C:\Users\YourWindowsUsername\path\to\your\vr_plugin.dll): This is the original file. It’s the actual file that you want to point to with the symbolic link. The contents of this original VRHands.dll are what will be accessed via the symlink VRHands.dll.

Once you've created the symlink, now everytime you rebuild the VRHands.dll at the target location, the symlink will automatically point to the freshest version of your plugin.

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

- Add your breakpoints in your plugin's cpp file, by click on the vertical bar at the left of your editor code, before the line numbers. When you click at a specific line, a red dot appears. That's the breakpoint. Add breakpoints where needed, to inspect the shizzle.


- Go to `Debug/Attach To Process` , And locate the `Attach to` menu.
Type `SanAndreas` to locate the SanAndreas.exe process (AKA your game).

- Double Click on the process to select it.
(If you get some annoying error/exception about kernel32.dll/kernel32.pdb or something similar, check one of the checkboxes in this error message to fix the issue.
Sorry, I forgot about what the checkbox name is, but you will figure it out. Send me a screenshot of the error msg you got and I'll tell you which checkbox to tick ;-)

- Go back to your game window.

- Press both of your controller sticks, or the `Inser` key, to make the UEVR menu appear, and reload your plugin, using the `PluginLoader/PluginLoader` menu, so the breakpoint gets hit.

- Go back to your Visual Studio, and you will see that your breakpoint are hit ! Enjoy, and create beautiful things, armed with the power of your C++ debugger.

In order to see the variables in greater detail, in Visual Studio, during debugging, you do these things

Autos: you can enable 'Autos' which will show you values by every member on your class. Go to menu `Debug->Windows->Autos` to make it appear.

Locals: you can enable 'Locals' which will show you all variables in the current stack frame. Go to menu `Debug->Windows->Locals` to make it appear.

Watch: You also can use 'Watch' you can drag and drop any variable to this window or right click then add to watch. Go to menu `Debug->Windows->Watch` to make it appear. Note. You can enable more than one watch window :).

Finally you can go over the variable with the mouse and you will see the variable's value.
