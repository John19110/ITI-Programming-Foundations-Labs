#include <iostream>

#include "Menu.h"
using namespace Menu;

int main() {
  Menu::draw(0, 0, "1. Start", "2. Settings", "3. Exit", color::Color::GREEN);

  return 0;
}