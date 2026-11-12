#include <iostream>

#include "../../Menu/include/Menu.h"
using namespace Menu;
using namespace std;
int main() {
  int size = 0;

  do {
    cout << "Enter size : " << endl;
    cin >> size;
    if (size < 0 || size % 2 == 0 && size != 0) {
      cout << "Size not valid ! reenter new size to try again or press 0 to "
              "quit the program "
           << endl;
    };

  } while ((size % 2 == 0 || size < 0) && size != 0);

  int space = 5;
  int col = size / 2, row = 0, counter = 1;
  cout << "\033[2J";
  cout << "\033[H";
  while (counter <= size * size) {
    drawMagic(space * col, space * row, counter);
    if (counter % size == 0 && counter != size * size) {
      row = (row + 1) % size;
    } else {
      col = (col + 1) % size;
      row = (row - 1 + size) % size;
    }

    counter++;
  }

  return 0;
}
