#ifndef Color_H
#define Color_H

#include <string>
namespace color {
enum Color { RED, BLUE, GREEN, YELLOW, WHITE, RESET };
bool isValid(Color selectedColor);

std ::string apply(char text[], Color SelectedColor);
}  // namespace color

#endif