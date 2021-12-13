/** @file spaceInvaders.h

 *  @brief Main configuration for the game

 *  Main configureation of objects and variables to be used in the game

 *  @author Dylan Stocking

 *  @bug No known bugs.

 */

#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include <string>  //for window title

#include "Block.h"   // Block object
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

//----------------------------------------------------------//
// global constants

// main game window properties
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 604;
const std::string WINDOW_TITLE = "SPACE INVADERS";

// game settings
const double FRAME_RATE = 1.0 / 60.0;  // Updae game every 1/60th of a second

// game components

// Player ship properties
int SHIP_WIDTH = 30;
int SHIP_HEIGHT = 30;

// Bullet properties
const int BALL_SIZE = 8;  // radius of ball in pixels
const fgcugl::Color BALL_COLOR = fgcugl::Blue;
const float BALL_SPEED_X = 40.0;  // speed horizontally in pixels
const float BALL_SPEED_Y = 70.0;  // speed vertically in pixels

// border walls
const int WALL_SIZE = 2;

// Enemies
const int ENEMY_HEIGHT = 20;
const int ENEMY_WIDTH = 64;
const int ENEMIES_COLUMNS = 14;
const int ENEMIES_ROWS = 8;
const int ENEMIES_START_X = WALL_SIZE;
const int ENEMIES_START_Y = (WINDOW_HEIGHT / 2 * WALL_SIZE) / 2;

// bricks
const int BRICK_WIDTH = 100;
const int BRICK_HEIGHT = 80;
const int BRICKS_COLUMNS = 1;  // number of bricks across
const int BRICKS_ROWS = 1;     // number of brcks down
const int BRICKS_START_X = WALL_SIZE * +100;
const int BRICKS_START_Y = (WINDOW_HEIGHT / 2 - 30 * WALL_SIZE) / 2;

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
