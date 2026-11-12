#include <iostream>
#define X 10
#define Y 10
#define linesCount 3

#include "../include/Menu.h"
using namespace Menu;
using namespace color;
int main() {
  char menu[3][30] = {{"1- New"}, {"2- Display"}, {"3- Exit"}};
  draw(X, Y, menu, 3, GREEN);
  drawLine(X, Y, menu[0], BLUE);

  update(menu, X, Y, linesCount,BLUE);

  return 0;
}
