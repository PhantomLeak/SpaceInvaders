// file: spaceInvaders.cpp
//by: Dylan Stocking
//Des: Main application file for space invaders game
//-----------------------------------------------------


#include "spaceInvaders.h"  // header file

#include <iostream>

#include "Block.h"   // Enemy blocks
#include "Bullet.h"  // Bullet
#include "Ship.h"    // Ship
#include "fgcugl.h"  // openGL library

// function prototypes (declaration)
// creation

// main game loop processing
Direction processInput();
void render(Bullet bullet, Ship ship, Block enemies[ENEMY_ROWS][ENEMY_COLUMNS],
            Walls walls, double lag);
int main() {
  fgcugl::openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

  // Border walls
  Walls walls;
  walls.top = Block(0, WINDOW_HEIGHT - WALL_SIZE, WINDOW_WIDTH, WALL_SIZE);
  walls.bottom = Block(0, 0, WINDOW_WIDTH, WALL_SIZE);
  walls.left = Block(0, 0, WALL_SIZE, WINDOW_HEIGHT);
  walls.right = Block(WINDOW_WIDTH - WALL_SIZE, 0, WALL_SIZE, WINDOW_HEIGHT);

  // Create ship
  int shipx = WINDOW_WIDTH / 2 - SHIP_WIDTH / 2;
  int shipy = walls.bottom.top() + 1 + SHIP_HEIGHT;
  Ship ship = Ship(shipx, shipy, SHIP_WIDTH, SHIP_HEIGHT, fgcugl::Green);

  // Create bullet
  float bulletX = WINDOW_WIDTH / 2.0;
  float bulletY = ship.top() + 3;
  Bullet bullet = Bullet(bulletX, bulletY, BULLET_SPEED_y, BULLET_SIZE, BULLET_COLOR);

  // Create enemies
  Block enemies[ENEMY_ROWS][ENEMY_COLUMNS];
  // createEnemies(enemies);                    Need to finish rendering the enemies

  // directions
  Direction currentDirection = DIR_NONE, nextDirection = DIR_NONE;

  // timing for game loop
  double startTime = fgcugl::getTime();
  double finishTime = 0.0, deltaTime = 0.0;

  bool gameover = false;

  while (!gameover) {
    finishTime = fgcugl::getTime();      // Frame timer
    deltaTime = finishTime - startTime;  // Add current lag
    startTime = finishTime;

    // Process input
    nextDirection = processInput();

    // render
    render(bullet, ship, enemies, walls, deltaTime);

    // Get keyboard events and windows move/close events
    fgcugl::getEvents();

    gameover = gameover || fgcugl::windowClosing();
  }  // end game loop

  return 0;
}  // end main

/**
Get user keyboard input
parameters:

Return:
Direction       next direction to move (default DIR_NONE)
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

void render(Bullet bullet, Ship ship, Block enemies[ENEMY_ROWS][ENEMY_COLUMNS],
            Walls walls, double lag) {
  // Draw player ship
  ship.draw(lag);

  // Draw bullet moving
  bullet.draw(lag);

  // Draw Enemies
  for (int row = 0; row < ENEMY_ROWS; row++) {
    for (int column = 0; column < ENEMY_COLUMNS; column++) {
      if (!enemies[row][column].isEmpty()) {
        enemies[row][column].drawWithBorder();
      }
    }  // column
  }    // row

  // draw walls
  walls.top.draw();
  walls.bottom.draw();
  walls.left.draw();
  walls.right.draw();

  // paint the screen
  fgcugl::windowPaint();
}
