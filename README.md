# Indium Engine  

Indium Engine is a game engine I am writing in C++ 20.
Currently, I plan on using Vulkan, although it may potentially be a better idea
to start with a OpenGL backend for the renderer.  
  
# Building  
  
Indium requires Vulkan SDK version 1.4, `vcpkg`, CMake version 4.3, Ninja, and a
compiler supporting the C++ 20 standard to be installed for compilation.
Currently, there are only presets (and a guide) for compiling Indium on Windows 
with either a x86 or x64 CPU.  
  
**Windows**  

Compiling Indium on Windows will require MSVC (Visual Studio 2022 or 2026).
MinGW support is possible but I have not
created presets supporting it, so anyone going that route
is on their own.

**Configuration**

First, run this script:  
```powershell
./scripts/msvc-env.ps1
```  
This will clean the build directory and provide the tools neccesary for our presets to use MSVC.  
  
Next, generate build files with the following command:
```powershell
cmake --preset [x86/x64]-windows-[Debug/Release]
```

> [!NOTE]
> Remember to replace [x86/x64] and [Debug/Release] with your actual architecture and build type.

Now, configuration is complete.

**Compliation**
  
To compile Indium, just run:  
```powershell
cmake --build build
```

Lastly, to run the executable, you can simply run:  
```powershell
build\IndiumEngine.exe
```