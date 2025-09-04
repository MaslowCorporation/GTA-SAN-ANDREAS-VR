import subprocess
import sys
import os

def install_requirements():
    """Install required packages"""
    print("Installing requirements...")
    subprocess.check_call([sys.executable, "-m", "pip", "install", "-r", "requirements.txt"])

def build_executable():
    """Build the executable"""
    print("Building executable...")
    
    # PyInstaller command
    cmd = [
        "pyinstaller",
        "--onefile",
        "--name=GTA_VR_Wheel_Controller",
        "--distpath=./dist",
        "--workpath=./build",
        "--specpath=./",
        "--hidden-import=openvr",
        "--hidden-import=keyboard", 
        "--hidden-import=inputs",
        "--hidden-import=threading",
        "--hidden-import=json",
        "--hidden-import=os",
        "--hidden-import=time",
        "--clean",
        "--noconfirm",
        "main.py"
    ]
    
    subprocess.check_call(cmd)
    print("Build completed successfully!")

def main():
    try:
        install_requirements()
        build_executable()
        
        exe_path = os.path.join("dist", "GTA_VR_Wheel_Controller.exe")
        if os.path.exists(exe_path):
            print(f"\n✅ Executable created: {exe_path}")
            print("You can now run the executable directly!")
        else:
            print("❌ Executable not found. Check for errors above.")
            
    except Exception as e:
        print(f"❌ Build failed: {e}")

if __name__ == "__main__":
    main()
