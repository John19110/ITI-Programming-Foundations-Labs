#include "Menu.h"

#include <iostream>

#ifdef _WIN32
#include <conio.h>
#elif defined(__linux__)
#include <termios.h>
#include <unistd.h>
#endif

using namespace std;
using namespace color;

namespace Menu {
//================DRAW=====================
// for menu
void draw(int x, int y, char Lines[10][20], int linesNumber,
          Color selectedColor) {
  if (x < 0 || y < 0) {
    cerr << "Error: x and y coordinates must be non-negative." << endl;
    return;
  }
  // if (line1.empty() || line2.empty() || line3.empty()) {
  //   cerr << "Error: Menu lines cannot be empty." << endl;
  //   return;
  // }
  if (!isValid(selectedColor)) {
    cerr << "Error: Invalid color selected." << endl;
    return;
  }

  for (int i = 0; i < linesNumber; i++) {
    cout << "\033[" << y + i << ";" << x << "H";
    cout << color::apply(Lines[i], selectedColor);
  }

  cout.flush();
}
void drawLine(int x, int y, char Line[20], Color selectedColor) {
  if (x < 0 || y < 0) {
    cerr << "Error: x and y coordinates must be non-negative." << endl;
    return;
  }
  // if (line1.empty() || line2.empty() || line3.empty()) {
  //   cerr << "Error: Menu lines cannot be empty." << endl;
  //   return;
  // }
  if (!isValid(selectedColor)) {
    cerr << "Error: Invalid color selected." << endl;
    return;
  }

  cout << "\033[" << y << ";" << x << "H";
  cout << color::apply(Line, selectedColor);

  cout.flush();
}
// for magic box
void drawMagic(int x, int y, int number) {
  if (x < 0 || y < 0) {
    cerr << "Error: x and y coordinates must be non-negative." << endl;
    return;
  }
  cout << "\033[" << y << ";" << x << "H";
  this_thread::sleep_for(chrono::milliseconds(300));
  cout << number << flush;
}

void update(char lines[10][20], int x, int y, int linescount) {
  char byte1 = 'q';
  char byte2 = 'q';
  char byte3 = 'q';

  int selectedIndex = 0;

  //   // Infinite loop that runs until the user chooses to quit
  do {
    // Read a key from the user
    byte1 = getch();
    // std::cout<<"Byte 1 :: "<<byte1<<std::endl;
    // If the key is the beginning of an arrow-key escape sequence
    if (byte1 == '\033') {
      // Skip the second character '['
      byte2 = getch();
      // std::cout<<"Byte 2 :: "<<byte2<<std::endl;
      byte3 = getch();
      // The third character determines the arrow direction
      // std::cout<<"Byte 3 :: "<<byte3<<std::endl;
      switch (byte3) {
        case 'A':
          selectedIndex = (selectedIndex - 1 + linescount) % linescount;

          break;

        case 'B':

          selectedIndex = (selectedIndex + 1) % linescount;

          break;
      }
    }

    draw(x, y, lines, linescount, color::WHITE);
    drawLine(x, y + selectedIndex, lines[selectedIndex], color::BLUE);

    // std::cout << "=================================" << std::endl;
  } while (byte1 != 'q' &&
           byte1 != 'Q');  // Exit the program if the user presses Q or q
}
//====================getch====================

#ifdef _WIN32

char getch() {
    return static_cast<char>(::_getch());
}

#elif defined(__linux__)

char getch() {
char buf = 0; // Variable to store the input character

    struct termios old = {0}; // Structure to save current terminal settings

    // Save the current terminal settings
    tcgetattr(0, &old);

    // Disable Canonical Mode (do not wait for Enter key)
    old.c_lflag &= ~ICANON;

    // Disable Echo so typed characters are not displayed
    old.c_lflag &= ~ECHO;

    // Require at least one character to be read
    old.c_cc[VMIN] = 1;

    // No timeout while waiting for input
    old.c_cc[VTIME] = 0;

    // Apply the modified settings immediately
    tcsetattr(0, TCSANOW, &old);

    // Read a single character immediately from the keyboard
    read(0, &buf, 1);

    // Re-enable Canonical Mode
    old.c_lflag |= ICANON;

    // Re-enable Echo
    old.c_lflag |= ECHO;

    // Restore the terminal to its original settings
    tcsetattr(0, TCSADRAIN, &old);

    // Return the character that was read
    return buf;
}

#endif

} // namespace Menu