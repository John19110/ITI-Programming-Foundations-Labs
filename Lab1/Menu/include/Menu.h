#ifndef Menu_H
#define Menu_H
#include <chrono>
#include <string>
#include <thread>

#include "Color.h"
namespace Menu {
void draw(int x, int y, char lines[10][20], int linsNumber,
          color::Color selectedColor);

void drawMagic(int x, int y, int number);
void drawLine(int x, int y, char Line[20], color::Color selectedColor);

char getch();
void update(char lines[10][20], int initialY, int initialX, int linescount);
// void clearscreen();
}  // namespace Menu
#endif