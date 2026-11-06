#include "Menu.h"

#include <iostream>

namespace Menu {

void draw(int x, int y, const std::string& line1, const std::string& line2,
          const std::string& line3, color::Color selectedColor) {
  if (x < 0 || y < 0) {
    std::cerr << "Error: x and y coordinates must be non-negative."
              << std::endl;
    return;
  }
  if (line1.empty() || line2.empty() || line3.empty()) {
    std::cerr << "Error: Menu lines cannot be empty." << std::endl;
    return;
  }
  if (!color::isValid(selectedColor)) {
    std::cerr << "Error: Invalid color selected." << std::endl;
    return;
  }
  std::cout << "\033[" << y << ";" << x << "H";
  std::cout << color::apply(line1, selectedColor);

  std::cout << "\033[" << y + 1 << ";" << x << "H";
  std::cout << color::apply(line2, selectedColor);

  std::cout << "\033[" << y + 2 << ";" << x << "H";
  std::cout << color::apply(line3, selectedColor);

  std::cout.flush();
}

}  // namespace Menu