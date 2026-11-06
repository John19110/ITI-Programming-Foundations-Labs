#include "Color.h"

namespace color {

std::string apply(const std::string& text, Color selectedColor) {
  std::string code;

  switch (selectedColor) {
    case Color::RED:
      code = "\033[31m";
      break;

    case Color::GREEN:
      code = "\033[32m";
      break;

    case Color::BLUE:
      code = "\033[34m";
      break;

    case Color::YELLOW:
      code = "\033[33m";
      break;

    case Color::WHITE:
      code = "\033[37m";
      break;

    case Color::RESET:
      code = "\033[0m";
      break;
  }

  return code + text + "\033[0m";
}

bool isValid(Color selectedColor) {
  switch (selectedColor) {
    case Color::RED:
    case Color::GREEN:
    case Color::BLUE:
    case Color::YELLOW:
    case Color::WHITE:
    case Color::RESET:
      return true;

    default:
      return false;
  }
}

}  // namespace color
