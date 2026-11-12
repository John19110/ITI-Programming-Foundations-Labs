#include <iostream>

#include "../include/Menu.h"
using namespace Menu;
using namespace color;
int main() {
  char menu[3][20] = {{"1- New"}, {"2- Display"}, {"3- Exit"}};
  draw(5, 5, menu, 3, WHITE);
  update(menu, 5, 5, 3);

  // Exit the program successfully
  return 0;
}
