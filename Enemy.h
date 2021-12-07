// file: Block.h
// By: Dylan Stocking
// Des: Declaration of block class object

#ifndef ENEMY_H
#define ENEMY_H

#include "Block.h"
#include "fgcugl.h"

class Enemy: public Block{
 public:
  Enemy();
  Enemy(int x, int y, int width, int height,
        fgcugl::Color color = fgcugl::White);
  // accessors
  // getters
  int getXCoordinate();
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
  int health;
  float direction;
};

#endif  // ENEMY_H