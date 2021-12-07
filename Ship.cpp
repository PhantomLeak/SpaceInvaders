/** @file Ship.cpp

 *  @brief Implementation of play ship block class object

 *  Implementation of object user controlls to fight against enemy

 *  @author Dylan Stocking

 *  @bug No known bugs.

 */

#include "Ship.h"

#include <math.h>  // velocity checking

const float ACCEL_SPEED = 6.0;
const float MAX_SPEED = 300.0;

/**
 * @brief initialize empty ship
 */
Ship::Ship() {
  ship = Block();
  currentX = 0.0;
  currentY = 0.0;
  velocity = 0.0;
}

/**
 * @brief Initalize parameter values
 */
Ship::Ship(int x, int y, int width, int height, fgcugl::Color color) {
  ship = Block(x, y, width, height, color);
  currentX = x;
  currentY = y;
  velocity = 0.0;
}

// Getters
Block Ship::getShip() { return ship; }
float Ship::getXCoordinate() { return currentX; }
float Ship::getYCoordinate() { return currentY; }
int Ship::getWidth() { return ship.getWidth(); }
int Ship::getHeight() { return ship.getHeight(); }
float Ship::getVelocity() { return velocity; }
fgcugl::Color Ship::getColor() { return ship.getColor(); }

// Setters
void Ship::setXCoordinate(float value) {
  currentX = value;
  ship.setXCoordinate(value);
}
void Ship::setYCoordinate(float value) {
  currentY = value;
  ship.setYCoordinate(value);
}
void Ship::setWidth(int value) { ship.setWidth(value); }
void Ship::setHeight(int value) { ship.setHeight(value); }
void Ship::setVelocity(float value) { velocity = value; }
void Ship::setColor(fgcugl::Color value) { ship.setColor(value); }

// Member methods
int Ship::top() { return ship.top(); }
int Ship::bottom() { return ship.bottom(); }
int Ship::left() { return ship.left(); }
int Ship::right() { return ship.right(); }

/**
 * @brief checks if ship object is empty
 * @return bool
 */
bool Ship::isEmpty() { return ship.isEmpty(); }

/**
 * @brief Get ships current direction
 *
 * @return bool
 */
Ship::ShipDirection Ship::currentDirection() {
  ShipDirection direction;
  if (fpclassify(velocity) == FP_ZERO) {
    direction = None;
  } else if (signbit(velocity)) {
    direction = Left;
  } else {
    direction = Right;
  }
  return direction;
}

/**
 * @brief Update location of ship each from relative to lag and perform
 * collision checking with left and right walls
 * @param next
 * @param leftWall
 * @param rightWall
 * @param lag
 */
void Ship::update(ShipDirection next, Block leftWall, Block rightWall,
                  float lag) {
  ShipDirection curDir = currentDirection();

  // player not holding a direction key
  if (next == None) {
    // if Ship is moving
    if (curDir != None) {
      // slow Ship to a stop
      if (curDir == Left) {
        velocity += ACCEL_SPEED;
      } else {
        velocity -= ACCEL_SPEED;
      }
    }  // Ship is moving
  }
  // player is holding a direciton key down.
  else {
    // accelerate Ship in user direction
    if (next == Left) {
      velocity -= ACCEL_SPEED;
    } else {
      velocity += ACCEL_SPEED;
    }  // accel

    // keep speed at or below max
    if (abs(velocity) > MAX_SPEED) {
      if (next == Left) {
        velocity = -MAX_SPEED;
      } else {
        velocity = MAX_SPEED;
      }
    }  // max speed

  }  // Holding direction key

  // adjust Ship position
  currentX += velocity * lag;
  ship.setXCoordinate(currentX);

  // Check for collision with walls
  if (left() < leftWall.right()) {
    velocity = 0.0;
    setXCoordinate(leftWall.right() + 1);
  } else if (right() > rightWall.left()) {
    velocity = 0.0;
    setXCoordinate(rightWall.left() - getWidth());
  }

}  // update

/**
 * @brief Draw ship object on the OpenGL Window Relative to current x/y with
 * lag
 * 
 * @param lag
 */
void Ship::draw(float lag) {
  float x = currentX + velocity * lag;
  Block currentPos(ship);
  currentPos.setXCoordinate(x);
  currentPos.draw();
}

/**
 * @brief Draw a ship with a border by drawing the block passed in on top of a background block
 *
 * @param lag 
 * @param borderColor 
 * @param borderSize 
 * 
 * @return void
*/
void Ship::drawWithBorder(float lag, fgcugl::Color borderColor,
                          int borderSize) {
  float x = currentX + velocity * lag;
  float y = currentY;
  int width = ship.getWidth();
  int height = ship.getHeight();
  fgcugl::Color color = ship.getColor();
  // draw background block
  Block background = Block(x, y, width, height, borderColor);
  background.draw();
  Block foreground =
      Block(x + borderSize, y + borderSize, width - 2 * borderSize,
            height - 2 * borderSize, color);
  foreground.draw();
}