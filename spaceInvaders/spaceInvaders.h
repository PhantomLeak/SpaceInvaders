// file: spaceInvader.h
// by: Dylan Stocking
// Des: Main configuration for the game
//--------------------------------------------------------------------

#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include <string>  //for window title

#include "fgcugl.h"  // openGL library

// flag values
enum Direction {
  DIR_EXIT = -1, DIR_NONE, DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT
};


// Global Constants

//Main game window properties
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 600; 
const std::string WINDOW_TITLE = "SPACE INVADERS";

// Game Settings
const double FRAME_RATE = 1.0 / 60.0; //Update game every 1/60th of a second

#endif  // SPACEINVADERS_H

