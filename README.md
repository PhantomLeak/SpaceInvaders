# SPACE INVADERS

 This program is for an individual term project for COP 3003. 
 It is a clone of the classis arace game Space Invaders using Object Oriented Programming written entirely in C++
 >**You Can view the documentation here:** https://phantomleak.github.io/SpaceInvaders/html/

## Getting Started
### Needed files:
  - Download OpenGL libraries and OpenGL Wrangler Libraries linked in the software section
  - Pull the FGCU OpenGL wrapper API code files linked in the Software & Acknowledgements sections
 ### Setting up the project:
  - Open the properties section for your project (In Visual Studio, right click on the directory in solution explorer and select properties)
    1. Select C/C++
       - General 
         > Additional Include Directories
         >> Add lib folders for GLEW & GLFW (glew02.1.0\include) (glfw-3.3.4.bin.WIN32\include)
    2. Select Linker
        - General
          >  Aditional Library Directories
          >>  Add lib folders for GLEW & GLFW (glew02.1.0\include) (glfw-3.3.4.bin.WIN32\include)
        - Input 
          > Additional Dependencies (DO NOT DELETE ANY DEPENDENCEIS ALREADY THERE)
          >> Add dependencies -> openg132.lib;glew32.lib;glfw3.lib;
     
  3. Apply changes and close out of the properties section.
      
  4. Add the FGCUGL API files (fgcugl.h, fgcugl.cpp) to your directory containing the .cpp files.
  5. Test building the project to make sure linking was successful.

  
## Software:
  - GLEW 2.1.0 (https://www.opengl.org/sdk/libs/GLEW/)
  - GLFW 3.3.4 (https://www.glfw.org/)
  - FGCU OpenGL wrapper API code: https://github.com/pallenfgcu/fgcugl
  - Microsoft Visual Studio
  - Git
  - WSL Ubuntu

## License
This project is licensed under the MIT License.

## Acknowledgments
  - FGCU OpenGL wrapper API code: https://github.com/pallenfgcu/fgcugl
   
