/** @file Block.cpp

 *  @brief Implementation of Block class object

 *  Implementing block class object for use of user ship, enemies, and astroids

 *  @author Dylan Stocking

 *  @bug No known bugs.

 */

#include "block.h"

/**
 * defaut constructor - initialize empty block
 */
Block::Block() {
  xpos = 0;
  ypos = 0;
  width = 0;
  height = 0;
  color = fgcugl::White;
}

/**
 * @brief Properties constructor - initialize to parameter values
 */
Block::Block(int x, int y, int width, int height, fgcugl::Color color) {
  xpos = x;
  ypos = y;
  this->width = width;
  this->height = height;
  this->color = color;
}

// accessors
// getters
/**
* @brief Get Block X Coordinate
* @return int
*/
int Block::getXCoordinate() { return xpos; }

/**
 * @brief Get Block Y Coordinate
 * @return int 
*/
int Block::getYCoordinate() { return ypos; }

/**
 * @brief Get Block Width
 * @return int
*/
int Block::getWidth() { return width; }

/**
 * @brief Get Block Height
 * @return int
*/
int Block::getHeight() { return height; }
/**
 * @brief Get Block Color
 * @return FGCUGL::Color
*/
fgcugl::Color Block::getColor() { return color; }

// setters
/**
* @brief Set Block X Coordiante
* @param value
*/
void Block::setXCoordinate(int value) { xpos = value; }

/**
 * @brief Set Block Y Coordinate
 * @param value 
*/
void Block::setYCoordinate(int value) { ypos = value; }

/**
 * @brief Set Block Width
 * @param value 
*/
void Block::setWidth(int value) { width = value; }

/**
 * @brief Set Block Height
 * @param value 
*/
void Block::setHeight(int value) { height = value; }

/**
 * @brief Set Block Color
 * @param value 
*/
void Block::setColor(fgcugl::Color value) { color = value; }

//-----------------------------------------------------
// member methods

/**
 * @brief Set Block top
 * @return int
*/
int Block::top() { return ypos + height; }

/**
 * @brief Set Block Bottom
 * @return int
*/
int Block::bottom() { return ypos; }

/**
 * @brief Set Block Left Side
 * @return int 
*/
int Block::left() { return xpos; }

/**
 * @brief Set Block Right Side 
 * @return int
*/
int Block::right() { return xpos + width; }

/**
 * @brief returns true if block is empty (width + height is zero)
 * @return bool
 */
bool Block::isEmpty() { return width + height == 0; }

/**
 * @brief Draw a block object on the OpenGL window
 */
void Block::draw() { fgcugl::drawQuad(xpos, ypos, width, height, color); }

/**
 * @brief Draw a block with a border by drawing the block passed in on top of a
 * background block
 * 
 * @param borderColor
 * @param borderSize
 */
void Block::drawWithBorder(fgcugl::Color borderColor, int borderSize) {
  // draw background block
  Block background = Block(xpos, ypos, width, height, borderColor);
  background.draw();
  Block foreground = Block(xpos, ypos + borderSize, width - 2 * borderSize,
                           height - 2 * borderSize, color);
  foreground.draw();
}
