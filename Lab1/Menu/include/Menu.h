#ifndef Menu_H
#define Menu_H
#include <chrono>
#include <string>
#include <thread>

#include "Color.h"
namespace Menu {
void draw(int x, int y, char lines[10][30], int linsNumber,
          color::Color selectedColor);

void drawMagic(int x, int y, int number);
void drawLine(int x, int y, char Line[30], color::Color selectedColor);
void updateLinux(int x, int y, char lines[10][30], int linescount,
                 color::Color selectedColor);
void updateWindows(int x, int y, char lines[10][30], int linescount,
                   color::Color selectedColor);

char getch();
void update(char lines[10][30], int initialY, int initialX, int linescount,
            color::Color selectedColor);
// void clearscreen();
}  // namespace Menu
#endif