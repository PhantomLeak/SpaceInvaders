/** @file Entity.h

 *  @brief Declaration of the Entity Class Object

 *  Entity class for all objects that have health and or move

 *  @author Dylan Stocking

 *  @bug No known bugs.

 */

#ifndef ENTITY_H
#define ENTITY_H

#include "fgcugl.h"

class Entity {
 public:
  Entity(int health, float movementSpeed);
  Entity(float x, float y);
  Entity();
  virtual ~Entity();

  //Getters
  int getHealth();
  int getMovementSpeed();

  //Setters
  void setHealth(int value);

  //Methods
  void movement(float lag, short int direction);
  void hpDown();
  bool isDead();

 protected:
  float _movementSpeed;
  int _health;
};

#endif  // ENTITY_H
