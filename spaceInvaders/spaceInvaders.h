// file: spaceInvader.h
// by: Dylan Stocking
// Des: Main configuration for the game
//--------------------------------------------------------------------

#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include <string>  //for window title

#include "Block.h"   // Block Object
#include "fgcugl.h"  // openGL library

// flag values
enum Direction {
  DIR_EXIT = -1,
  DIR_NONE,
  DIR_UP,
  DIR_DOWN,
  DIR_LEFT,
  DIR_RIGHT
};

// Global Constants

// Main game window properties
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SPACE INVADERS";

// Game Settings
const double FRAME_RATE = 1.0 / 60.0;  // Update game every 1/60th of a second

// Player Ship Width/Height
int SHIP_WIDTH = 20;
int SHIP_HEIGHT = 20;

// Bullet Properties
const int BULLET_SIZE = 4;  // radius of the bullet in pixels
const fgcugl::Color BULLET_COLOR = fgcugl::Blue;
const float BULLET_SPEED_y = 40.0;  // Speed of bullet

// border walls
const int WALL_SIZE = 2;

//enemies
const int ENEMY_WIDTH = 32;
const int ENEMY_HEIGHT = 10;
const int ENEMY_COLUMNS = 14;	// Number of enemies across
const int ENEMY_ROWS = 8;		// Number of enemy rows
const int ENEMY_START_X = WALL_SIZE;
const int ENEMY_START_Y = (WINDOW_HEIGHT - 2 * WALL_SIZE) / 2;

//---------------------------------------------------------//
// Structures

// border walls
struct Walls {
  Block top;
  Block bottom;
  Block left;
  Block right;
};


#endif  // SPACEINVADERS_H
