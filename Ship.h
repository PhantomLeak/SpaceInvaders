/** @file Ship.h

 *  @brief Declaration of Ship class object

 *  Declaring ship class object that the user will control

 *  @author Dylan Stocking

 *  @bug No known bugs.

 */

#ifndef SHIP_H
#define SHIP_H

#include "Block.h"
#include "fgcugl.h"
#include "Entity.h"

class Ship{
 public:
  // Global Defines
  enum ShipDirection { None, Left, Right };
  // Constructors
  Ship();
  Ship(int x, int y, int width, int height,
       fgcugl::Color color = fgcugl::Green);
  // Getters
  Block getShip();
  float getXCoordinate();
  float getYCoordinate();
  int getWidth();
  int getHeight();
  float getVelocity();
  fgcugl::Color getColor();
  // setters
  void setXCoordinate(float value);
  void setYCoordinate(float value);
  void setWidth(int value);
  void setHeight(int value);
  void setVelocity(float value);
  void setColor(fgcugl::Color value);

  // member methods
  int top();
  int bottom();
  int left();
  int right();

  bool isEmpty();

  ShipDirection currentDirection();

  void update(ShipDirection next, Block leftWall, Block rightWall, float lag);
  void draw(float lag);
  void drawWithBorder(float lag, fgcugl::Color borderColor = fgcugl::Black,
                      int borderSize = 1);

 private:
  Block ship;
  float currentX;
  float currentY;
  float velocity;
};

#endif  // SHIP_H