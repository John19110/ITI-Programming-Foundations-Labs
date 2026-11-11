#ifndef Menu_H
#define Menu_H
#include <chrono>
#include <string>
#include <thread>

#include "Color.h"
using namespace std;
using namespace color;
namespace Menu {
void draw(int x, int y, const string& line1, const string& line2,
          const string& line3, Color selectedColor);

void draw(int x, int y, int number);
}  // namespace Menu

#endif