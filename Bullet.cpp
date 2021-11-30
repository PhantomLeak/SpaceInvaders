// file: Ship.cpp
// by: Dylan Stocking
// Des: implementation of bullet class object
//-----------------------------------------------------

#define _USE_MATH_DEFINES  // enable M_PI
#include "Bullet.h"

#include <math.h>

#include "Block.h"

Bullet::Bullet(float x, float y, short int direction, int size,
               fgcugl::Color color, float movementSpeed) {
  xpos = x;
  ypos = y;
  _direction = direction;
  radius = size;
  this->_color = color;
  _movementSpeed = movementSpeed;
}


//Getters
float Bullet::getXCoordinate() { return xpos; }
float Bullet::getYCoordinate() { return ypos; }
int Bullet::getSize() { return radius; }
fgcugl::Color Bullet::getColor() { return _color; }


//Setters
void Bullet::setXCoordinate(float value) { xpos = value; }
void Bullet::setYCoordinate(float value) { ypos = value; }
void Bullet::setSize(int value) { radius = value; }
void Bullet::setColor(fgcugl::Color value) { _color = value; }