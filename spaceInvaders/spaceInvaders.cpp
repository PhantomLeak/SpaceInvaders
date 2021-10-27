#include "spaceInvaders.h"  // header file

#include <iostream>

#include "fgcugl.h"  // openGL library

int main() {
  fgcugl::openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

  while (!fgcugl::windowClosing()) {
    std::string displayText = "HELLO WORLD";

    fgcugl::drawText(300, 300, displayText);

    fgcugl::windowPaint();  // draw updates to screen

    fgcugl::getEvents();  // check for keyboard and window events
  }

  fgcugl::cleanup();

  return 0;
}
