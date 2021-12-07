/** @file spaceInvaders.cpp

 *  @brief Main application file for space invaders game

 *  Main application file to display and render movement, refresh rate, and
 functions of application

 *  @author Dylan Stocking

 *  @bug No known bugs.

 */

#include "spaceInvaders.h"  // header file

#include <iostream>

#include "Enemy.h"   //Enemies
#include "Ship.h"    // Ship
#include "fgcugl.h"  // openGL library

// function prototypes (declaration)
// creation
void createBricks(Block bricks[BRICKS_ROWS][BRICKS_COLUMNS]);
void createEnemies(Enemy enemies[ENEMIES_ROWS][ENEMIES_COLUMNS]);
Direction processInput();
bool update(Ship& ship, Walls walls, double lag, Direction next);
void render(Ship ship, Block bricks[BRICKS_ROWS][BRICKS_COLUMNS],
            Enemy enemy[ENEMIES_ROWS][ENEMIES_COLUMNS], Walls walls,
            double lag);

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

  // Create the bricks
  Block bricks[BRICKS_ROWS][BRICKS_COLUMNS];
  createBricks(bricks);

  // Create the enemies
  Enemy enemy[ENEMIES_ROWS][ENEMIES_COLUMNS];
  createEnemies(enemy);

  // timing for game loop
  double startTime = fgcugl::getTime();
  double finishTime = 0.0, deltaTime = 0.0;

  bool gameover = false;
  while (!gameover) {
    std::string displayTitle = "SPACE INVADERS";
    fgcugl::drawText(360, 550, displayTitle, 2.5);
    finishTime = fgcugl::getTime();       // sright the frame timer
    deltaTime += finishTime - startTime;  // add current lag
    startTime = finishTime;

    // Process input
    nextDirection = processInput();

    // update
    while (deltaTime >= FRAME_RATE) {
      gameover = update(ship, walls, deltaTime, nextDirection);
      deltaTime -= FRAME_RATE;
    }

    // render
    render(ship, bricks, enemy, walls, deltaTime);

    // get keyboard and windos move/close events
    fgcugl::getEvents();

    // end game if window closes
    gameover = gameover || fgcugl::windowClosing();
  }  // end game loop

  return 0;  // Return success
}

/**
 * @brief Create rows of enemies
 *
 * @param enemies
 * @param array of blocks
 *
 * @return void
 */
void createEnemies(Enemy enemies[ENEMIES_ROWS][ENEMIES_COLUMNS]) {
  int y = ENEMIES_START_Y;

  for (int row = 0; row < ENEMIES_ROWS; row++) {
    int x = ENEMIES_START_X;
    for (int column = 0; column < ENEMIES_COLUMNS; column++) {
      fgcugl::Color enemyColor;

      // assign color by row number
      switch (row) {
        case 0:
        case 1:
          enemyColor = fgcugl::Yellow;
          break;
        case 2:
        case 3:
          enemyColor = fgcugl::Green;
          break;
        case 4:
        case 5:
          enemyColor = fgcugl::Orange;
          break;
        case 6:
        case 7:
          enemyColor = fgcugl::Red;
      }  // color

      enemies[row][column] = Enemy(x, y, ENEMY_WIDTH, ENEMY_HEIGHT, enemyColor);

      x += ENEMY_WIDTH;
    }  // Column
    y += ENEMY_HEIGHT;
  }  // rows
}  // create enemies

/**
 * @brief Create bricks for user
 *
 * @param bricks
 * @param array of blocks
 *
 * @return void
 */
void createBricks(Block bricks[BRICKS_ROWS][BRICKS_COLUMNS]) {
  int y = BRICKS_START_Y;

  for (int row = 0; row < BRICKS_ROWS; row++) {
    int x = BRICKS_START_X;

    for (int column = 0; column < BRICKS_COLUMNS; column++) {
      fgcugl::Color blockColor;

      // assign color by row number
      switch (row) {
        case 0:
        case 1:
          blockColor = fgcugl::Yellow;
          break;
        case 2:
        case 3:
          blockColor = fgcugl::Green;
          break;
        case 4:
        case 5:
          blockColor = fgcugl::Orange;
          break;
        case 6:
        case 7:
          blockColor = fgcugl::Red;
      }  // color

      bricks[row][column] = Block(x, y, BRICK_WIDTH, BRICK_HEIGHT, blockColor);

      x += BRICK_WIDTH;

    }  // columns

    y += BRICK_HEIGHT;

  }  // rows

}  // createBricks

/**
 * @brief Get user direction
 * 
 * @return Direction newdirection
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

/**
 * @brief Update objectes on OpenGL window
 *
 * @param ship
 * @param walls
 * @param lag
 * @param next
 *
 * @return bool
 */

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
 * @brief draw game objects on OpenGL window
 *
 * @param ship
 * @param bricks
 * @param enemy
 * @param walls
 * @param lag
 *
 * return void
 */
void render(Ship ship, Block bricks[BRICKS_ROWS][BRICKS_COLUMNS],
            Enemy enemy[ENEMIES_ROWS][ENEMIES_COLUMNS], Walls walls,
            double lag) {
  ship.draw(lag);

  // draw bricks
  for (int row = 0; row < BRICKS_ROWS; row++) {
    for (int column = 0; column < BRICKS_COLUMNS; column++) {
      // if current block not broken (has y-coordinate)
      if (!bricks[row][column].isEmpty()) {
        bricks[row][column].drawWithBorder();
      }
    }  // column
  }    // row

  // draw Enemies
  for (int row = 0; row < ENEMIES_ROWS; row++) {
    for (int column = 0; column < ENEMIES_COLUMNS; column++) {
      // if current block not broken (has y-coordinate)
      if (!enemy[row][column].isEmpty()) {
        enemy[row][column].drawWithBorder();
      }
    }  // column
  }    // row

  // draw walls
  walls.top.draw();
  walls.bottom.draw();
  walls.left.draw();
  walls.right.draw();

  // paint new scene
  fgcugl::windowPaint();
}