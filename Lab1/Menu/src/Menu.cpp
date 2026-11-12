#include "Menu.h"
#include "Employee.h"
#include <iostream>
#include <limits>

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
void draw(int x, int y, char Lines[10][30], int linesNumber,
          Color selectedColor) {
  if (x < 0 || y < 0) {
    cerr << "Error: x and y coordinates must be non-negative." << endl;
    return;
  }
  
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
void drawLine(int x, int y, char Line[30], Color selectedColor) {
  if (x < 0 || y < 0) {
    cerr << "Error: x and y coordinates must be non-negative." << endl;
    return;
  }

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

void update(char lines[10][30], int x, int y, int linescount,Color selectedColor) 
{
#ifdef _WIN32
//windows logic
updateWindows(x,  y,  lines, linescount, selectedColor);
#elif defined(__linux__)
//linux logic
updateLinux(x,  y,  lines, linescount, selectedColor);
#endif

}
//====================getch====================

#ifdef _WIN32

void updateWindows(int x, int y, char lines[10][30],
                   int linescount, Color selectedColor) 
                   {

    int byte1 = 0;
    int byte2 = 0;
    int selectedIndex = 0;

    while (true) 
    {


        byte1 = _getch();

        if (byte1 == 0 || byte1 == 224) 
        {

            byte2 = _getch();

            switch (byte2) {
                case 72:
                    selectedIndex =
                        (selectedIndex - 1 + linescount) % linescount;
                    break;

                case 80:
                    selectedIndex =
                        (selectedIndex + 1) % linescount;
                    break;
            }

        }
        else if (byte1 == 13)
        {
          if (selectedIndex == 0)
          {
              system("cls");

              int mode = 0;
              cout << "1. Add fixed number of employees\n";
              cout << "2. Keep adding until finished\n";
              cout << "Choice: ";
              cin >> mode;

              if (mode == 1) {
                  Employee::addFixedNumber();
              } else if (mode == 2) {
                  Employee::addUntilFinished();
              }


              selectedIndex = 0;
          }
          else if (selectedIndex == 2) 
          {
              return;
          }
        }

        draw(x, y, lines, linescount, GREEN);
        drawLine(x, y + selectedIndex, lines[selectedIndex], BLUE);
    }
}
     
    


#elif defined(__linux__)

void updateLinux(int x, int y, char lines[10][30], int linescount, Color selectedColor)
{
  
  char byte1 = 'q';
  char byte2 = 'q';
  char byte3 = 'q';

  int selectedIndex = 0;

  do {

    byte1 = getch();
    
    if (byte1 == '\033') {
      byte2 = getch();
      byte3 = getch();

      switch (byte3) {
        case 'A':
          selectedIndex = (selectedIndex - 1 + linescount) % linescount;
          break;
        case 'B':
          selectedIndex = (selectedIndex + 1) % linescount;
          break;
      }
    }
    else if (byte1 == '\n' || byte1 == '\r')
    {
      if (selectedIndex == 0)
      {
        system("clear");

        int mode = 0;
        cout << "1. Add fixed number of employees\n";
        cout << "2. Keep adding until finished\n";
        cout << "Choice: ";
        cin >> mode;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (mode == 1) {
          Employee::addFixedNumber();
        } else if (mode == 2) {
          Employee::addUntilFinished();
        }

        cout << "\nPress Enter to return to the menu...";
        cin.get();

        system("clear");
        selectedIndex = 0;
      }
      else if (selectedIndex == 2) {
        return;
      }
    }

    draw(x, y, lines, linescount, color::WHITE);
    drawLine(x, y + selectedIndex, lines[selectedIndex], color::BLUE);

  } while (byte1 != 'q' && byte1 != 'Q');
}


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
}

 // namespace Menu