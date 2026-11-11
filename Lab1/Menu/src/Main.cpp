#include <iostream>

#include "../include/Menu.h"
using namespace Menu;
using namespace color;
int main() {
  Menu::draw(10, 10, "1. Start", "2. Settings", "3. Exit", GREEN);

  return 0;
}