// file: Entity.h
// by: Dylan Stocking
// Des: Entity implementation
//--------------------------------------------------------------------

#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

#include "fgcugl.h"
#include "spaceInvaders.h"

class Entity {
 public:
  Entity(float x, float y, int health, float movementSpeed);
  Entity();
  virtual ~Entity();

  // Getters
  int getHealth();
  float getMovementSpeed();

  // Setters
  void setHealth(int value);

  // Functions
  void movement(double frameTime, short int direction);
  void hpDown();
  bool isDead();

 protected:
  float _movement_speed;
  int _health;
};
#endif  // ENTITY_H
