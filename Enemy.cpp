/** @file Enemy.cpp

 *  @brief Implementation of Enemy class object

 *  Implementation of Enemy class to get and set variables 

 *  @author Dylan Stocking

 *  @bug No known bugs.

 */
#include "Enemy.h"
// constructors

/**
* @brief initialize empty enemy
*/
Enemy::Enemy() {
  xpos = 0;
  ypos = 0;
  width = 0;
  height = 0;
  color = fgcugl::White;
}

/**
* @brief Initialize to paramater values
*/
Enemy::Enemy(int x, int y, int width, int height, fgcugl::Color color) {
  xpos = x;
  ypos = y;
  this->width = width;
  this->height = height;
  this->color = color;
}

// accessors
// getters

/**
 * @brief Get Enemy X Coordinate
 * @return int
*/
int Enemy::getXCoordinate() { return xpos; }

/**
 * @brief Get Enemy Y Coordinate
 * @return int
*/
int Enemy::getYCoordinate() { return ypos; }

/**
 * @brief Get Enemy Width
 * @return int 
*/
int Enemy::getWidth() { return width; }

/**
 * @brief Get Enemy Height
 * @return int 
*/
int Enemy::getHeight() { return height; }

/**
 * @brief Get Enemy Color
 * @return FGCUGL::Color
*/
fgcugl::Color Enemy::getColor() { return color; }

// setters

/**
 * @brief Set Enemy X Coordinate
 * @param value 
*/
void Enemy::setXCoordinate(int value) { xpos = value; }

/**
 * @brief Set Enemy Y Coordinate
 * @param value 
*/
void Enemy::setYCoordinate(int value) { ypos = value; }

/**
 * @brief Set Enemy Width
 * @param value 
*/
void Enemy::setWidth(int value) { width = value; }

/**
 * @brief Set Enemy Height
 * @param value 
*/
void Enemy::setHeight(int value) { height = value; }

/**
 * @brief Set Enemy Color
 * @param value 
*/
void Enemy::setColor(fgcugl::Color value) { color = value; }

//-----------------------------------------------------
// member methods

/**
 * @brief Set Enemy Top
 * @return int 
*/
int Enemy::top() { return ypos + height; }

/**
 * @brief Set Enemy Bottom
 * @return int 
*/
int Enemy::bottom() { return ypos; }

/**
 * @brief Set Enemy Left
 * @return int 
*/
int Enemy::left() { return xpos; }

/**
 * @brief Set Enemy Right
 * @return int 
*/
int Enemy::right() { return xpos + width; }

/**
* @brief checks to enemy object is empty
* @return bool
*/
bool Enemy::isEmpty() { return width + height == 0; }

/**
 * @brief draw a Enemy object on the OpenGL window
*/
void Enemy::draw()
{
	fgcugl::drawQuad(xpos, ypos, width, height, color);
}

/**
* @brief Draw an Enemy with a broder by drawing the enemy pass in top 
* of a background Enemy
* 
* @param borderColor
* @param borderSize
* 
*/
void Enemy::drawWithBorder(fgcugl::Color borderColor, int borderSize)
{
	// draw background Enemy
	Enemy background = Enemy(xpos, ypos, width, height, borderColor);
	background.draw();
	Enemy foreground = Enemy(xpos, ypos + borderSize,width - 2 * borderSize,
		height - 2 * borderSize, color);
	foreground.draw();
}


