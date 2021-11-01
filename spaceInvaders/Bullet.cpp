// file: Bullet.cpp
//by: Dylan Stocking
//Des: implementation of a player Bullet block class object
//-----------------------------------------------------

#define _USE_MATH_DEFINES  // enable M_PI

#include "Bullet.h"

#include <math.h>

// Constructors
Bullet::Bullet(float x, float y, float velocityY, int size,
               fgcugl::Color color) {
  ypos = y;
  this->velocityY = velocityY;
  radius = size;
  this->color = color;
}

// Accessors
//-----------------------------------------
// Getters
float Bullet::getYCoordinate() { return ypos; }
float Bullet::getXCoordinate() { return xpos; }
float Bullet::getYVelocity() { return velocityY; }
int Bullet::getSize() { return radius; }
fgcugl::Color Bullet::getColor() { return color; }

// setters
void Bullet::setYCoordinate(float value) { ypos = value; }
void Bullet::setXCoordinate(float value) { xpos = value; }
void Bullet::setYVelocity(float value) { velocityY = value; }
void Bullet::setSize(int value) { radius = value; }
void Bullet::setColor(fgcugl::Color value) { color = value; }

/**
Update location of the bullet each frame relative to the lag
Parameters:
lag						-Current frame lag
*/
void Bullet::update(float lag) { ypos += velocityY * lag; }

void Bullet::draw(float lag) { 
    float currY = ypos + velocityY * lag;
  fgcugl::drawCircle(0, currY, radius, color);
}