#ifndef Color_H
#define Color_H

using namespace std;
#include <string>
namespace color {
enum Color { RED, BLUE, GREEN, YELLOW, WHITE, RESET };
bool isValid(Color selectedColor);

string apply(const string& text, Color SelectedColor);
}  // namespace color

#endif