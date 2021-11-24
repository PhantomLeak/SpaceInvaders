// file: Enemy.cpp
// by: Dylan Stocking
// Des: implementation of Enemy class object
//-----------------------------------------------------
#include "Enemy.h"
// constructors
//-----------------------------------------------------
/**
 * defaut constructor - initialize empty Enemy
 */
Enemy::Enemy() {
  xpos = 0;
  ypos = 0;
  width = 0;
  height = 0;
  color = fgcugl::White;
}

/**
* Properties constructor - Initialize to paramater values
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
int Enemy::getXCoordinate() { return xpos; }
int Enemy::getYCoordinate() { return ypos; }
int Enemy::getWidth() { return width; }
int Enemy::getHeight() { return height; }
fgcugl::Color Enemy::getColor() { return color; }
// setters
void Enemy::setXCoordinate(int value) { xpos = value; }
void Enemy::setYCoordinate(int value) { ypos = value; }
void Enemy::setWidth(int value) { width = value; }
void Enemy::setHeight(int value) { height = value; }
void Enemy::setColor(fgcugl::Color value) { color = value; }

//-----------------------------------------------------
// member methods
int Enemy::top() { return ypos + height; }
int Enemy::bottom() { return ypos; }
int Enemy::left() { return xpos; }
int Enemy::right() { return xpos + width; }

/**
* return true if Enemy is empty (width + height is zero)
*/
bool Enemy::isEmpty() { return width + height == 0; }

/**
draw a Enemy object on the OpenGL window
*/
void Enemy::draw()
{
	fgcugl::drawQuad(xpos, ypos, width, height, color);
}

/**
* draw a Enemy with a border by drawing the Enemy passed in on top
* of a background Enemy
*
* Paramaters:
* borderColor	color of the border Enemy
* borderSize	size of the border in pixels
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


