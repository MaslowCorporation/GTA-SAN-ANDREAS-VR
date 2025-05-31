# GTA SAN ANDREAS VR Mod 🌎

<p align="center">
  <img src="readme_assets/gta_logo.jpg" alt="GTA San Andreas Logo">
</p>

Welcome to the world of Grand Theft Auto: San Andreas in VR !

The goal of this Github repository is to document the process of turning Grand Theft Auto: San Andreas into a VR game, thanks to Vorpx.

### Setup

* Downgrade GTA San Andreas to v1.0

See https://www.youtube.com/watch?v=mZVuYZrtHWo

* Install First Person mod by BoPoh

See https://libertycity.net/files/gta-san-andreas/77200-first-person-view-v3.0-by-bopoh.html

* Fix the problem related to the right stick not working in first person.

Follow https://www.youtube.com/watch?v=KtUgfVaypsE

* Start GTA San Andreas and go to `Settings => Mouse Settings` and turn all to `OFF` .

Also turn `Mouse Sensitivity` all the way up.

* Go to the `Graphics` settings, and turn  `Wide Screen` off.

Turn `Frame Limiter` off. 

Turn `Anti Aliasing` to max.

Set resolution to `2880 x 2160 x 32`.

* Go to game and go to first person.

* Press `Alt + B` to open the First Person mod menu.

* Set `Field of View` to `115`

* Set `Near Clip` to `0.06`

* Turn `Rotate player with camera` on

* Download and start Vorpx

* Create a copy of the local gta san andreas profile

* start san andreas with vorpx

* set `Scale` to a value between `3.5` and `4.0` (toy with it to find goldilocks. `3.5` is a great starting point.)

* Go to `Head Tracking Settings` , and set `HT Position Unlock` on.

* Save the Vorpx settings by clicking `OK & SAVE`

* set mode to `Full VR`

* Enjoy !

### To Start GTA San Andreas in VR

* Start your headset and connect it to STEAMVR

* Start Vorpx

* Start Joy2Key

* Start steam-uevr-wheel

* Start GTA San Andreas

* set resolution to `2880 x 2160 x 32` or `1920 x 1080 x 32` or something bigger

* set vorpx mode to `Full VR`

* Go to first person camera by pressing `option` on your gamepad

* there's a `recenter` button in the vorpxmenu.


### CONTROLS

Left Stick (Short Press): Toggle Vorpx menu

Left Stick (Long Press): Normal game controls

Right Stick (Short Press): Toggle EdgePeek (See the game HUD)

Right Stick (Long Press): Normal game controls

Adjust car seat position: press `Alt + B`, and use the `Car Offsets` sliders,
to move the seat. then press `Alt + B` again to close the menu.

Recenter Vorpx: press `L1` (after following setup instructions)

### The list of mods that improve the game experience

### TODO

- [ ] utilise joy2key ou similaire pour set in car:
L2 as brake/reverse
R2 as accelerate, 
L1 as handbrake

tip: In <root>/GInputSA.ini change ControlsSet=1 to ControlsSet=2.


in the game settings

- [ ] utilise joy2key ou similaire pour set on foot:

set L2 as aim 
set R2 as shoot, 

in the game settings

- [ ] Install vjoy

- [ ] Test steam-uevr-wheel inside GTA San Andreas vorpx

- [ ] Import all socket related code from

C:\Users\MaslowPatrick\Desktop\MaslowWorld\VRHands\VRHands\dllmain.cpp

to

C:\plugin-sdk\tools\myplugin-gen\generated\gta_wheel\source\Main.cpp
or rather
C:\plugin-sdk\tools\myplugin-gen\generated\gta_wheel\source\gta_wheel.sln

- [ ] fix errors and make successful build

- [ ] on plugin initialization, turn the socket server on and print the value of the steering wheel angle to the game and log it to the console or in game.
WinDBG may help.

- [ ] on plugin death, turn the socket server off.

- [ ] First dummy algorithm for the steering wheel:

Apply the angle value from the socket server as is, to the in game steering angle.

- [ ] Second better algorithm for the steering wheel:

apply a steering ratio to the steering wheel angle.

(A steering ratio of x:y means that a turn of the steering wheel x degree(s) causes the wheel(s) to turn y degree(s). In most passenger cars, the ratio is between 12:1 and 20:1.)

See https://chatgpt.com/c/6806a763-0f34-8012-9073-764a45ede404

- [ ] another better algorithm for the steering wheel (smoothing):

See https://chatgpt.com/c/68069bdd-87e4-8012-a86c-dd9caf483748 
for inspiration.

- [ ] implemente keyboard press handler

- [ ] implemente gamepad press handler

- [ ] when R1 is pressed, and you're sitting in a car, toggle the steam-uevr-wheel
between invisible, setup mode, and game mode. (edit config.json)

- [] Set L2 to brake/reverse and R2 to accelerate, in the game settings

- [ ] Make CJ invisible when sitting in a car. either via plugin-sdk or cleo / sannybuilder

- [] reposition the HUD elements  to the center of the screen , using

https://gamemodding.com/en/gta-san-andreas/tools/18704-inteface-editor-visual.html

- [] Try to use the SendInput c++ function, or plugin-sdk, or etc...to send input to press the V key twice, to toggle the first person view, when the game starts, and CJ is playable. If it doesn't work, simply move on. Do not spend time on this.

- [ ] set edgepeek distance from screen up

- [ ] try to fix the resolution issue of the game.
(2880 x 2160 x 32 should be the native resolution of the game)

- [] Add mods to the game

See https://www.youtube.com/watch?v=Q-RyJwGue9A

and

https://www.youtube.com/watch?v=Ajzk0Z_M6ag

Work in progress. More soon ...