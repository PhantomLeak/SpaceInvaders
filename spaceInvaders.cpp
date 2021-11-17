// file: spaceInvaders.cpp
// by: Dylan Stocking
// Des: Main application file for space invaders game
//-----------------------------------------------------

#include "spaceInvaders.h"  // header file

#include <iostream>

#include "Ship.h"    // Ship
#include "Ship.h"    // player ship
#include "fgcugl.h"  // openGL library

// function prototypes (declaration)
// creation
Direction processInput();
bool update(Ship& ship, Walls walls, double lag, Direction next);
void render(Ship ship, Walls walls, double lag);

int main() {
  // main game window
  fgcugl::openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);

  // border walls
  Walls walls;
  walls.top = Block(0, WINDOW_HEIGHT - WALL_SIZE, WINDOW_WIDTH, WALL_SIZE);
  walls.bottom = Block(0, 0, WINDOW_WIDTH, WALL_SIZE);
  walls.left = Block(0, 0, WALL_SIZE, WINDOW_HEIGHT);
  walls.right = Block(WINDOW_WIDTH - WALL_SIZE, 0, WALL_SIZE, WINDOW_HEIGHT);

  // Create ship
  int shipX = WINDOW_WIDTH / 2 - SHIP_WIDTH / 2;
  int shipY = walls.bottom.top() + 1 + SHIP_HEIGHT;
  Ship ship = Ship(shipX, shipY, SHIP_WIDTH, SHIP_HEIGHT, fgcugl::Red);

  // Direction
  Direction currentDirection = DIR_NONE, nextDirection = DIR_NONE;

  // timing for game loop
  double startTime = fgcugl::getTime();
  double finishTime = 0.0, deltaTime = 0.0;

  bool gameover = false;
  	while (!gameover)
	{
		finishTime = fgcugl::getTime();        // sright the frame timer 
		deltaTime += finishTime - startTime;   // add current lag
		startTime = finishTime;

		// Process input
		nextDirection = processInput();

		// update
		while (deltaTime >= FRAME_RATE)
		{
			gameover = update(ship, walls, deltaTime, nextDirection);
			deltaTime -= FRAME_RATE;
		}

		// render
		render(ship, walls, deltaTime);

		//get keyboard and windos move/close events
		fgcugl::getEvents();

		// end game if window closes
		gameover = gameover || fgcugl::windowClosing();
	} // end game loop

  return 0;  // Return success
}

/**
 get user keyboard input
 parameters:
 Return:
 Direction	next direction to move (default DIR_NONE)
*/
Direction processInput() {
  Direction direction = DIR_NONE;

  // get keyboard input
  char key = fgcugl::getKey();

  switch (key) {
    case 'W':  // up
      direction = DIR_UP;
      break;
    case 'S':  // down
      direction = DIR_DOWN;
      break;
    case 'A':  // left
      direction = DIR_LEFT;
      break;
    case 'D':  // right
      direction = DIR_RIGHT;
      break;
    case 'X':  // exit key
      direction = DIR_EXIT;
  }

  return direction;
}  // end processInput

bool update(Ship& ship, Walls walls, double lag, Direction next) {
  bool quit = false;

  Ship::ShipDirection shipDir = Ship::None;

  if (next == DIR_LEFT) {
    shipDir = Ship::Left;
  } else if (next == DIR_RIGHT) {
    shipDir = Ship::Right;
  }
  ship.update(shipDir, walls.left, walls.right, lag);

  return quit;
}

/**
draw game objects on OpenGL window
Parameters:
        ball			   location and speed of the ball
        paddle			   loaction of player paddle
        walls              border walls for collision check
        lag                build up of lag between frames
returnts:
void
*/
void render(Ship ship, Walls walls, double lag) {
  ship.draw(lag);

  // draw walls
  walls.top.draw();
  walls.bottom.draw();
  walls.left.draw();
  walls.right.draw();

  // paint new scene
  fgcugl::windowPaint();
}