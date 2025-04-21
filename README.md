# GTA SAN ANDREAS VR Mod 🌎

<p align="center">
  <img src="readme_assets/gta_logo.jpg" alt="GTA San Andreas Logo">
</p>

## Hi, amigo vato loco ;-) ! 🎮

Welcome to the world of Grand Theft Auto: San Andreas in VR !

The goal of this Github repository is to document the process of turning Grand Theft Auto: San Andreas Definitive Edition into a VR game, thanks to the fantastic UEVR Mod from Lord Praydog

https://github.com/praydog/UEVR

If the documentation scares you, don't worry ! This README describes in detail each step from zero to hero ;-)

### In Game Setup (Shadow Fix, Windowed Mode setup, etc...)

- Navigate to the folder containing your game files, and create a copy of your game folder, dedicated to VR.
Name this copied folder whatever you want, like `GTA San Andreas - DE - VR`
That way, you can distinguish between your vanilla GTA San Andreas and the VR version. 
Also create a Desktop shortcut of the `PlayGTASanAndreas.exe` of this copied folder, 
and rename the Desktop Shortcut to something like `GTA San Andreas VR`

- Open `GTA San Andreas Definitive Edition` from the Desktop shortcut.

- Pause it, and go to the `GRAPHICS` menu.

- Set `World Shadow Quality` to `OFF` , to disable shadows, because the in-game shadows are buggy and cause crashes in UEVR
(the shadows are displayed in one eye only).

- Set `Cloud Quality` to `Material` ,  in order to avoid weird visual glitches

- Set `Display Mode` to `Windowed`

- Go to the `CONTROLS` menu, and click on `Adjust Control Layout`
(use a PC Gamepad to do so, because if you use the mouse and keyboard, 
the keyboard specific layout screen will show up, 
and we want the gamepad specific screen)

- Set `Control Scheme` to `Modern Alt`
(This is necessary, because the VR grip buttons used for the VR steering wheel plugin, 
are also used for shooting and handbraking, in the default `Modern` layout,
so choosing the `Modern Alt` layout allows us to grab the steering wheel using the left VR grip button, without shooting like a madman ;-)

### Install Cleo Redux 

We need to install Cleo Redux. Download and run the `cleo_redux_setup.exe` installer, located at

https://re.cleo.li/

#### IMPORTANT: During the Cleo Redux installation, you must select the copied folder you created for your game as the installation folder !!!!

### UEVR Setup

- Download and install the `.Net Runtime` and the `.Net Desktop Runtime` at

https://dotnet.microsoft.com/en-us/download/dotnet/6.0

- Before downloading UEVR, Add your Downloads folder to the exclusion list of your Firewall shizzle

see https://superuser.com/a/1565786 for the how-to.

Also disable the download protection mechanism in your web browser if it is causing issues.

- Download the latest UEVR.zip file at 

https://github.com/praydog/UEVR/releases

- Extract the zip file into the downloads folder you just whitelisted !!!.

- Create a shortcut for `UEVRInjector.exe` in your Desktop, for convenience.

- Open the `UEVRInjector.exe` file from the Desktop shortcut.
(OPEN IT AS ADMINISTRATOR, by right clicking the shortcut and selecting the appropriate entry) 

- Open `GTA San Andreas Definitive Edition` from the Desktop shortcut.

- Press `Windows Key` to make the UEVR menu appear in game, while the game is running.

- Click the little arrow on the top right corner of UEVR,
and select the process corresponding to GTA SA.
It should normally be called `SanAndreas (pid: xxxx) (Grand Theft Auto: San Andreas - The Definitive Edition)`

- Make sure your VR headset is connected and ready, via `Virtual Desktop` or `Link/AirLink` or whatever your shizzle is ;-)

- Click on `Inject`

- Now, the game is projected into your headset. To toggle the UEVR Menu ON/OFF, Press `Inser` on your keyboard, or `L3 + R3` on your gamepad.

(Please note that the UEVR menu toggle works only with a PC gamepad, not with the VR controller, at least in my case, using a Oculus Quest 2. Yours may vary.)

### Install the 6DOF First Person UEVR mod

See https://www.nexusmods.com/grandtheftautothetrilogy/mods/922

#### UEVR Camera positioning

- When the UEVR menu is visible, you can press your RT (Right Trigger) of your PC controller, 
and use your left and right stick to adjust the camera. 
Put in inside CJ's head, like at his brain position, or above, you decide how low or high you want it

`RT + Left Stick`: Move the camera left/right/forward/back
`RT + Right Stick`: Move the camera up/down
`RT + B`: Reset camera offset
`RT + Y`: Recenter view
`RT + X`: Reset standing origin

- Once the camera is positionned in a satisfying way, Press `Inser` on your keyboard, or `L3 + R3` on your gamepad,
to make the UEVR menu disappear.

If you want to reset all the UEVR settings to default settings, 
in case of some weird camera glitches, or other issues, 
simply click the `Reset to Default Settings` button in the UEVR menu !

<p align="center">
  <img src="https://praydog.github.io/uevr-docs/usage/images/in-game-menu-1.png" alt="GTA San Andreas Logo">
</p>

### Add a VR steering wheel and hands that you can position as you wish (thanks to steam-vr-wheel and vjoy)

First, on the main UEVR menu (not the in-game UEVR menu, the first menu you use to inject to the game) ,
scroll down through the `Game Settings` list , and find the `VR_MotionControlsInactivityTimer` entry . 
The default value for this is something like `30.000000` , but you must set it to `1.000000` , 
in order to avoid the long timeouts when you switch from using the PC Gamepad to the VR controllers.

You also may need to calibrate your left and right VR controller joysticks, If you see weird in-game glitches when using the VR joysticks.

What I mean by 'weird in-game glitches' is , you may notice that when you use the VR joysticks and you stop using them, 
the character may still keep moving, or the menu pickers may randomly do movements. 

This is due to a well known issue called `Joystick drift`.

This is when the joysticks of a controller are not calibrated properly due to long term use. Thankfully, there's a way to help mitigate the issue 
(It can't be fixed completely, but it can be diminished. The only way to fix this issue is to get new controllers)

For more info about how to re-calibrate the VR joystick, on the Oculus Quest 2 headset,

see this video

https://www.youtube.com/watch?v=L-vOz2UhStY

and this page on the Meta website

https://www.meta.com/help/quest/articles/fix-a-problem/troubleshoot-headsets-and-accessories/touch-controller-drift/

Every headset has it's own similar mechanism, so look for your specific headset calibration settings ;-)

Ok, now that you've set `VR_MotionControlsInactivityTimer` to `1.000000` , we need to talk about how you'll play the game.
Simply put:

- You'll use the PC gamepad for anything other than car/truck/boat driving 
(for gunfights, fistfights, exploration, swimming, motorcycles, planes, etc...)

- You'll use the VR controllers to drive cars and trucks and boats, using a VR steering wheel , and 2 VR hands ;-)
(you can also use the PC gamepad for car/truck/boat driving, but the VR steering is a lot of fun ;-)
Typically, when you will use the VR controllers to drive, you'll use only the left and right grip buttons, and the left and right trigger buttons. 
The other buttons are not used by the VR driving plugin ;-)

Okay ! Now Follow the instructions from the [Releases page of steam-uevr-wheel](https://github.com/MaslowCorporation/steam-uevr-wheel/releases/latest) to install the steam-uevr-wheel UEVR plugin

### Fix the camera positioning issue with the first person view in vehicles

When you're in a car/boat/truck/plane/etc... in first person mode, sometimes, you may see that the camera is inside the character's body.

You can fix this by positioning the camera in a way so you can see things clearly ;-)

To position the camera, do these things:

- make the UEVR Menu appear in-game (Press `Inser` on your keyboard, or `L3 + R3` on your gamepad)

(Please note that the UEVR menu toggle works only with a PC gamepad, not with the VR controller, at least in my case, using a Oculus Quest 2. Yours may vary.)

- When the UEVR menu is visible, you can press your RT (Right Trigger) of your PC controller, 
and use your left and right stick to adjust the camera. 
Put in inside CJ's head, like at his brain position, or above, you decide how low or high you want it

`RT + Left Stick`: Move the camera left/right/forward/back
`RT + Right Stick`: Move the camera up/down
`RT + B`: Reset camera offset
`RT + Y`: Recenter view
`RT + X`: Reset standing origin

- Once the camera is positionned in a satisfying way, Press `Inser` on your keyboard, or `L3 + R3` on your gamepad,
to make the UEVR menu disappear.

Problem 'kinda' fixed ;-)

Hey, be happy that it's even possible to play this game in VR to begin with. Don't be too demanding, 
just enjoy that it's even possible, thanks to Praydog's UEVR tool ;-)

### Fix the missing crosshairs issue

When I first tried the game in VR, I noticed that the crosshairs were missing when aiming weapons.

I toyed with the UEVR settings then I managed to get the crosshairs visible. But then I had another issue....
The crosshairs were imprecise. I then found another fix to get the crosshairs precise.

To get things working properly, just follow one of those methods:

#### 1) Via Oculus Link/Airlink (for Meta headset users)

- Start SteamVR, on your computer. 
(IMPORTANT !!) Go to SteamVR (the Windows SteamVR menu, not the VR menu) -> Settings -> OpenXR and turn the setting `Set SteamVR as OpenXR Runtime` ON . When done, close SteamVR.

- Start Oculus Link or AirLink. Make sure that SteamVR is not running.
The reason you want SteamVR to be completely turned off prior to getting in Oculus Link/Airlink, 
is because sometimes, SteamVR bugs when you start Oculus Link/Airlink while SteamVR is already going on.

- Once you're in Oculus Link, start SteamVR. 
(Go to `LIBRARY` in Steam, then type `steamvr` in the search bar to find steamvr, then start it)
Make sure you start SteamVR from within Steam, in your computer 
because sometimes, if you start SteamVR from the SteamVR icon, the headset doesn't go to SteamVR,
whereas if you do start SteamVR from within Steam, then the headset switches to SteamVR without issue ;-)
You should notice the change of scenery from the Oculus Link environment to the SteamVR environment.
If you don't switch to SteamVR despite following these steps, don't worry ;-) Just restart your computer AND your headset, and retry the steps, and it will work !

- Once you're connected to Oculus Link/Airlink and SteamVR on your headset, start your game.

- Once your game has started, start UEVR as administrator.

- Once UEVR has started, MAKE SURE YOU SET `OpenXR` AS THE UEVR RUNTIME, then inject to your game.

- In your in-game UEVR menu, go to the `Camera` menu, then set the `Camera Offset` values to 0, 0, 0.
TIP: Press the `Load Camera 0` button to reset the camera offsets to 0, 0, 0 
(Assuming that you haven't saved some camera offsets previously there.
You can use `Load Camera 1` or `Load Camera 2` too. Use one that's blank, to set the camera offsets to 0, 0, 0)

- Press the `Set Standing Height` button, then press the `Set Standing Origin` button, then press the `Recenter View` button, then press the `Recenter Horizon` button.

- toggle `Show Advanced Options` ON, then go to the `Compatibility` tab of UEVR, then toggle `AHUD UI Compatibility` ON

- Now, your crosshairs should work properly, AND the steam-vr-wheel mechanism will work properly too ;-)

#### 2) Via Virtual Desktop (for all headset users ;-)

- Start SteamVR, on your computer. 
(IMPORTANT !!) Go to SteamVR (the Windows SteamVR menu, not the VR menu) -> Settings -> OpenXR and turn the setting `Set SteamVR as OpenXR Runtime` ON . When done, close SteamVR.

- Start Virtual Desktop.

- Once you're in Virtual Desktop, start SteamVR. 
Make sure you start SteamVR from within Virtual Desktop, rather than from your computer, 
because sometimes, if you start SteamVR from your computer, the headset doesn't go to SteamVR,
whereas if you do start SteamVR from within Virtual Desktop, then the headset switches to SteamVR without issue ;-)
You should notice the change of scenery from the Virtual Desktop environment to the SteamVR environment.
If you don't switch to SteamVR despite following these steps, don't worry ;-) Just restart your computer AND your headset, and retry the steps, and it will work !

- Once you're connected to Virtual Desktop and SteamVR on your headset, start your game.

- Once your game has started, start UEVR as administrator.

- Once UEVR has started, MAKE SURE YOU SET `OpenXR` AS THE UEVR RUNTIME, then inject to your game.

- In your in-game UEVR menu, go to the `Camera` menu, then set the `Camera Offset` values to 0, 0, 0.
TIP: Press the `Load Camera 0` button to reset the camera offsets to 0, 0, 0 
(Assuming that you haven't saved some camera offsets previously there.
You can use `Load Camera 1` or `Load Camera 2` too. Use one that's blank, to set the camera offsets to 0, 0, 0)

- Press the `Set Standing Height` button, then press the `Set Standing Origin` button, then press the `Recenter View` button, then press the `Recenter Horizon` button.

- In your in-game UEVR menu, toggle `Show Advanced Options` ON, then go to the `Compatibility` tab of UEVR, then toggle `AHUD UI Compatibility` ON

- Now, your crosshairs should work properly, AND the steam-vr-wheel mechanism will work properly too ;-)

NOTE: The crosshairs fix ONLY works with OpenXR chosen as the UEVR runtime.

### Here's a similar repository for Grand Theft Auto III: Definitive Edition ;-)

[Link to GTA 3 VR](https://github.com/MaslowCorporation/GTA-3-VR)

### Here's a similar repository for Grand Theft Auto Vice City: Definitive Edition ;-)

[Link to GTA Vice City VR](https://github.com/MaslowCorporation/GTA-VICE-CITY-VR)

### Other fixes and improvements will be added over time. If you can provide help, it will be greatly appreciated, because I'm all alone doing this ;-)

If you want to edit the source code of the UEVR driving plugin, follow [this README](https://github.com/MaslowCorporation/steam-uevr-wheel/blob/main/readme_assets/create_uevr_plugin/README.md)

### Thank you for existing ;-)
