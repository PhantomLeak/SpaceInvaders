// file: Bullet.h
// By: Dylan Stocking
// Des: Declaration of Bullet class object

#ifndef BULLET_H
#define BULLET_H
#include "Block.h"
#include "fgcugl.h"

class Bullet {
 public:
  // Gloabal defines
  enum CollisionType { None, Vertical };
  // Constructor
  Bullet(float x, float y, short int direction, int size, fgcugl::Color color,
         float movementSpeed);

  // Getters
  float getXCoordinate();
  float getYCoordinate();
  int getSize();
  fgcugl::Color getColor();
  // Setters
  void setXCoordinate(float value);
  void setYCoordinate(float value);
  void setSize(int);
  void setColor(fgcugl::Color value);
  // Member methods
  int top();

  void update(float lag);
  void draw(float lag);
  CollisionType collisionCheck(Block block);
  void doCollision(int collision);

 private:
  float xpos;
  float ypos;
  short int _direction;
  float _movementSpeed;
  int radius;
  fgcugl::Color _color;
};

#endif  // BULLET_H
