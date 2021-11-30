#include "Entity.h"

Entity::Entity() {
  _health = 1;
  _movement_speed = 0.2;
}

int Entity::getHealth()
{
    return _health;
}

float Entity::getMovementSpeed()
{
    return _movement_speed;
}

void Entity::setHealth(int value)
{
    _health = value;
}

void Entity::hpDown()
{
    _health = _health - 1;
    std::cout << "HP DOWN = " << _health << std::endl;
}

bool Entity::isDead()
{
    if(_health <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
