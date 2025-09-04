# A simple script to toggle the wheel mode of steam-vr-wheel
#
# To install additional dependencies, run:

# venv\Scripts\activate on windows
# or
# source venv/bin/activate on linux
#
# then
#
# pip install openvr keyboard inputs

import json
import os
import threading
import time
import sys

import keyboard
from inputs import get_gamepad

# SteamVR support with better error handling
STEAMVR_AVAILABLE = False
vr_system = None



# === CONFIGURATION ===
# Make the path more flexible for executable
if getattr(sys, 'frozen', False):
    # Running as executable
    base_path = os.path.dirname(sys.executable)
else:
    # Running as script
    base_path = os.path.dirname(os.path.abspath(__file__))

JSON_CONFIG_FILE_PATH = os.path.join(
    os.path.expanduser("~"),
    "AppData", "Local", "steam-vr-wheel", "config.json"
)

KEYBOARD_KEY = "shift"
GAMEPAD_BUTTON = "BTN_THUMBL"
GAMEPAD_BUTTON_DESCRIPTION = "Left Stick Press"

# === STATE CONSTANTS ===
WHEEL_OFF = "WHEEL_OFF"
WHEEL_SETUP = "WHEEL_SETUP"
WHEEL_ACTIVE = "WHEEL_ACTIVE"

# === INITIAL STATE ===
wheel_state = WHEEL_OFF
lock = threading.Lock()  # Prevent race conditions

# SteamVR variables
last_left_stick_press = False
last_right_stick_press = False


def read_json_config():
    try:
        with open(JSON_CONFIG_FILE_PATH, "r") as f:
            return json.load(f)
    except Exception as e:
        print(f"Error reading JSON: {e}")
        return {}


def write_json_config(data):
    try:
        with open(JSON_CONFIG_FILE_PATH, "w") as f:
            json.dump(data, f, indent=4)
    except Exception as e:
        print(f"Error writing JSON: {e}")


def switch_wheel_mode():
    global wheel_state

    with lock:
        config = read_json_config()
        if not config:
            return

        if wheel_state == WHEEL_OFF:
            config["edit_mode"] = True
            config["wheel_show_wheel"] = True
            wheel_state = WHEEL_SETUP
            print("Switched to WHEEL_SETUP")

        elif wheel_state == WHEEL_SETUP:
            config["edit_mode"] = False
            config["wheel_show_wheel"] = True
            config["wheel_degrees"] = 900

            wheel_state = WHEEL_ACTIVE
            print("Switched to WHEEL_ACTIVE")

        elif wheel_state == WHEEL_ACTIVE:
            config["edit_mode"] = False
            config["wheel_show_wheel"] = False
            wheel_state = WHEEL_OFF
            print("Switched to WHEEL_OFF")

        write_json_config(config)





def keyboard_listener():
    keyboard.add_hotkey(KEYBOARD_KEY, switch_wheel_mode)
    keyboard.wait("esc")  # Block until user presses ESC


def gamepad_listener():
    print("Gamepad listener started.")
    while True:
        try:
            events = get_gamepad()
            for event in events:
                if event.ev_type == "Key" and event.state == 1:
                    if event.code == GAMEPAD_BUTTON:
                        switch_wheel_mode()
        except Exception as e:
            print(f"Gamepad error: {e}")
            time.sleep(1)  # Avoid tight error loop


def vr_controller_listener():
    """Listen for VR controller inputs"""
    print("VR Controller listener started.")
    while True:
        try:
            time.sleep(0.016)  # ~60 FPS polling rate
        except Exception as e:
            print(f"VR controller listener error: {e}")
            time.sleep(1)  # Avoid tight error loop


def main():
    if not os.path.exists(JSON_CONFIG_FILE_PATH):
        print(f"ERROR: JSON config file not found at: {JSON_CONFIG_FILE_PATH}")
        return

    print(f"Press {KEYBOARD_KEY} or Gamepad {GAMEPAD_BUTTON_DESCRIPTION} to toggle wheel mode.")
    
    print("Press ESC to exit.")

    # Start all listeners
    threads = []
    
    t1 = threading.Thread(target=keyboard_listener, daemon=True)
    t2 = threading.Thread(target=gamepad_listener, daemon=True)
    threads.extend([t1, t2])
    
    # Always start VR listener thread, it will handle errors gracefully
    t3 = threading.Thread(target=vr_controller_listener, daemon=True)
    threads.append(t3)

    for thread in threads:
        thread.start()

    try:
        t1.join()  # Wait for ESC key to exit
    except KeyboardInterrupt:
        print("Shutting down...")
    finally:
        print("Exiting...")


if __name__ == "__main__":
    main()
