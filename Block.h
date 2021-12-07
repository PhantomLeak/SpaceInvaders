/** @file Block.h

 *  @brief Declaration of block class object

 *  Block class object used for enemies, user blocks, and player ship

 *  @author Dylan Stocking

 *  @bug No known bugs.

 */

#ifndef BLOCK_H
#define BLOCK_H

#include "fgcugl.h"

class Block {
 public:
  // constructors
  Block();
  Block(int x, int y, int width, int height,
        fgcugl::Color color = fgcugl::White);

  // accessors
  // getters
  virtual int getXCoordinate();
  int getYCoordinate();
  int getWidth();
  int getHeight();
  fgcugl::Color getColor();
  // setters
  void setXCoordinate(int value);
  void setYCoordinate(int value);
  void setWidth(int value);
  void setHeight(int value);
  void setColor(fgcugl::Color value);

  // member methods
  int top();
  int bottom();
  int left();
  int right();

  bool isEmpty();

  void draw();
  void drawWithBorder(fgcugl::Color borderColor = fgcugl::Black,
                      int borderSize = 1);

 private:
  int xpos;
  int ypos;
  int width;
  int height;
  fgcugl::Color color;
};

#endif  // BLOCK_H
