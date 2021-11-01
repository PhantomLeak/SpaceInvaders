// file: Bullet.h
// by: Dylan Stocking
// Des: Declaration of Bullet class object
//--------------------------------------------------------------------

#ifndef PLAYER_H
#define PLAYER_H

#include "fgcugl.h"

class Bullet {
 public:
  Bullet(float x, float y, float velocityY, int size,
         fgcugl::Color color = fgcugl::Blue);

  // getters
  float getYCoordinate();
  float getXCoordinate();
  float getYVelocity();
  int getSize();
  fgcugl::Color getColor();

  // setters
  void setYCoordinate(float value);
  void setXCoordinate(float value);
  void setYVelocity(float value);
  void setSize(int);
  void setColor(fgcugl::Color value);

  // member methods
  int top();
  int bottom();
  int right();
  int left();

  void update(float lag);
  void draw(float lag);

 private:
  float xpos;
  float ypos;
  float velocityY;
  int radius;
  fgcugl::Color color;
};

#endif  // PLAYER_H