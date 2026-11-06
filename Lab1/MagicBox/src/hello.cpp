#include <iostream>

#include "MagicBox.h"

int main() {
  std::cout << "Magic Box\n";
  std::cout << "Fill an odd box so every row, column, and both diagonals\n";
  std::cout << "add up to the same number.\n\n";

  int size = readBoxSize();
  if (size < 1) {
    return 0;
  }

  showMagicBox(size);
  return 0;
}
