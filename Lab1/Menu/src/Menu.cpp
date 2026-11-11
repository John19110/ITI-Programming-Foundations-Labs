#include "Menu.h"

#include <iostream>
using namespace std;
using namespace color;
namespace Menu {

void draw(int x, int y, const string& line1, const string& line2,
          const string& line3, Color selectedColor) {
  if (x < 0 || y < 0) {
    cerr << "Error: x and y coordinates must be non-negative." << endl;
    return;
  }
  if (line1.empty() || line2.empty() || line3.empty()) {
    cerr << "Error: Menu lines cannot be empty." << endl;
    return;
  }
  if (!isValid(selectedColor)) {
    cerr << "Error: Invalid color selected." << endl;
    return;
  }
  cout << "\033[" << y << ";" << x << "H";
  cout << apply(line1, selectedColor);

  cout << "\033[" << y + 1 << ";" << x << "H";
  cout << apply(line2, selectedColor);

  cout << "\033[" << y + 2 << ";" << x << "H";
  cout << apply(line3, selectedColor);

  cout.flush();
}

void draw(int x, int y, int number) {
  if (x < 0 || y < 0) {
    cerr << "Error: x and y coordinates must be non-negative." << endl;
    return;
  }
  cout << "\033[" << y << ";" << x << "H";
  this_thread::sleep_for(chrono::milliseconds(300));
  cout << number << flush;
}

}  // namespace Menu
