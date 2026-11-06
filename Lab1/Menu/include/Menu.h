#pragma once
#include <string>

#include "Color.h"
using namespace std;
namespace Menu {
void draw(int x, int y, const string& line1, const string& line2,
          const string& line3, color::Color selectedColor);

}  