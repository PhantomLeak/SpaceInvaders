/** @file Entity.cpp

 *  @brief Implementation of Entity class object

 *  Implementation of object Entity for player, enemies, and blocks.

 *  @author Dylan Stocking

 *  @bug No known bugs.

 */

#include "Entity.h"
#include <iostream>

/**
 * @brief Initialization of class
 * @param health
 * @param movementSpeed
 */
Entity::Entity(int health, float movementSpeed) {
  _health = health;
  _movementSpeed = movementSpeed;
}

/**
 * @brief Deconstructor of Entity
 */
Entity::~Entity() {}

/**
* @brief Gets health of entity object
* @return int
*/
int Entity::getHealth() { return _health; }

/**
* @brief Gets Entity movement speed
* @return float
*/
int Entity::getMovementSpeed() { return _movementSpeed; }

/**
 * @brief Reduces Entity's HP when hit
*/
void Entity::hpDown() { _health = _health - 1;
  std::cout << "HP DOWN = " << _health << std::endl;
}

/**
 * @brief Checks if Entity is Dead
 * @return bool
*/
bool Entity::isDead() {
  if (_health > 0) {
    return true;
  } else {
    return false;
  }
}