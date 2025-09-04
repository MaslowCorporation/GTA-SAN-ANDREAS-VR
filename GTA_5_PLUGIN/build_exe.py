import PyInstaller.__main__
import os

# Get the current directory
current_dir = os.path.dirname(os.path.abspath(__file__))

PyInstaller.__main__.run([
    'main.py',
    '--onefile',
    '--name=GTA_VR_Wheel_Controller',
    '--distpath=./dist',
    '--workpath=./build',
    '--specpath=./',
    '--hidden-import=openvr',
    '--hidden-import=keyboard',
    '--hidden-import=inputs',
    '--hidden-import=threading',
    '--hidden-import=json',
    '--hidden-import=os',
    '--hidden-import=time',
    '--clean',
    '--noconfirm'
])

print("Executable created successfully!")
print("Location: ./dist/GTA_VR_Wheel_Controller.exe")
