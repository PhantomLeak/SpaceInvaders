#include "spaceInvaders.h"  // header file

#include <iostream>

#include "fgcugl.h"  // openGL library

int main() {
  fgcugl::openWindow(200, 200, "Hello GL!");

  while (!fgcugl::windowClosing()) {
    std::string displayText = "HELLO WORLD";

    fgcugl::drawText(24, 96, displayText);

    fgcugl::windowPaint();  // draw updates to screen

    fgcugl::getEvents();  // check for keyboard and window events
  }

  fgcugl::cleanup();

  return 0;
}
