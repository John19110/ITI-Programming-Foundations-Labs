#pragma once

using namespace std;
#include <string>
namespace color {
enum class Color { RED, BLUE, GREEN, YELLOW, WHITE, RESET };
bool isValid(Color selectedColor);

string apply(const string& text, Color SelectedColor);
}  // namespace color
