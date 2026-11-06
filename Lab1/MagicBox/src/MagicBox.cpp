#include "../include/MagicBox.h"

#include <cctype>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <random>
#include <thread>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif

namespace {

const int kMaxBoxSize = 9;

// The box is never stored. The Siamese method always puts 1 in the middle
// of the top row, then walks up and to the right, wrapping at the edges.
// When the next cell is already taken, the next number drops straight down.
// This formula is that walk solved backwards: given a cell, it returns
// the number that belongs there.
int magicValue(int row, int col, int size) {
  int half = size / 2;
  int groupsBefore = (row + col - half + size) % size;
  int indexInGroup = (groupsBefore + col - half + size) % size;
  return groupsBefore * size + indexInGroup + 1;
}

int magicSum(int size) { return size * (size * size + 1) / 2; }

int numberWidth(int size) {
  int width = 1;
  int value = size * size;
  while (value >= 10) {
    value /= 10;
    ++width;
  }
  if (width < 2) {
    width = 2;
  }
  return width;
}

int delayMilliseconds(int size) {
  if (size <= 1) {
    return 400;
  }
  if (size <= 3) {
    return 280;
  }
  if (size <= 5) {
    return 150;
  }
  return 80;
}

// Windows needs this switch before it will honor the same cursor codes
// Linux terminals already understand. Both platforms then share one path.
void enableAnsi() {
#ifdef _WIN32
  HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
  if (output == INVALID_HANDLE_VALUE) {
    return;
  }
  DWORD mode = 0;
  if (!GetConsoleMode(output, &mode)) {
    return;
  }
  SetConsoleMode(output, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
}

void clearScreen() {
  enableAnsi();
  std::cout << "\033[2J\033[H" << std::flush;
}

void moveCursor(int row, int column) {
  std::cout << "\033[" << row << ";" << column << "H";
}

void printBorder(int size, int width) {
  for (int col = 0; col < size; ++col) {
    std::cout << '+';
    for (int dash = 0; dash < width + 2; ++dash) {
      std::cout << '-';
    }
  }
  std::cout << "+\n";
}

void printGrid(int size, int width, bool filled) {
  printBorder(size, width);
  for (int row = 0; row < size; ++row) {
    for (int col = 0; col < size; ++col) {
      std::cout << "| ";
      if (filled) {
        std::cout << std::setw(width) << magicValue(row, col, size);
      } else {
        for (int space = 0; space < width; ++space) {
          std::cout << ' ';
        }
      }
      std::cout << ' ';
    }
    std::cout << "|\n";
    printBorder(size, width);
  }
}

// Column where the number inside this cell begins (1-based).
// Each cell is "| " + number + " ".
int numberColumn(int col, int width) { return 3 + col * (width + 3); }

// Row where this box row is drawn. The grid starts at gridTop with a border,
// then a number row, then a border, and so on.
int numberRow(int gridTop, int row) { return gridTop + 1 + (2 * row); }

bool hasTrailingJunk() {
  char ch = 0;
  while (std::cin.get(ch)) {
    if (ch == '\n') {
      return false;
    }
    if (!std::isspace(static_cast<unsigned char>(ch))) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return true;
    }
  }
  return false;
}

// Pick a scrambled order that still visits every cell once.
// Adding `step` (mod cell count) hits each cell exactly once when step and
// the cell count share no common factor. The start cell is random too.
// Only two numbers are remembered, not the box.
void chooseVisit(std::mt19937& rng, int total, int& start, int& step) {
  start = 0;
  step = 1;
  if (total == 1) {
    return;
  }

  std::uniform_int_distribution<int> startDist(0, total - 1);
  std::uniform_int_distribution<int> stepDist(1, total - 1);
  start = startDist(rng);
  do {
    step = stepDist(rng);
  } while (std::gcd(step, total) != 1);
}

void showStatus(int row, int column, int number, int placed, int total,
                int width) {
  moveCursor(2, 1);
  std::cout << "Placing " << std::setw(width) << number << " at row " << row
            << ", column " << column << "   (" << placed << " of " << total
            << ")\033[K";
}

}  // namespace

int readBoxSize() {
  while (true) {
    std::cout << "Enter an odd box size from 1 to " << kMaxBoxSize << ": ";

    int size = 0;
    if (!(std::cin >> size)) {
      if (std::cin.eof()) {
        std::cout << '\n';
        return -1;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a whole number.\n";
      continue;
    }

    if (hasTrailingJunk()) {
      std::cout << "Invalid input. Please enter a whole number.\n";
      continue;
    }
    if (size <= 0) {
      std::cout << "The size must be a positive number.\n";
      continue;
    }
    if (size % 2 == 0) {
      std::cout << "The size must be odd. Even sizes cannot use this method.\n";
      continue;
    }
    if (size > kMaxBoxSize) {
      std::cout << "Please choose an odd size from 1 to " << kMaxBoxSize
                << " so the box fits on the screen.\n";
      continue;
    }
    return size;
  }
}

void showMagicBox(int size) {
  if (size < 1 || (size % 2) == 0 || size > kMaxBoxSize) {
    std::cout << "The box size must be an odd number from 1 to " << kMaxBoxSize
              << ".\n";
    return;
  }

  const int width = numberWidth(size);
  const int total = size * size;
  const int sum = magicSum(size);
  const int delay = delayMilliseconds(size);
  // Line 1 is the title, line 2 is the status, line 3 is blank.
  const int gridTop = 4;

  std::mt19937 rng{std::random_device{}()};
  int start = 0;
  int step = 1;
  chooseVisit(rng, total, start, step);

  clearScreen();
  std::cout << "Magic Box (" << size << " x " << size << ")   magic sum " << sum
            << "\n";
  std::cout << "Watch the numbers appear.\033[K\n";
  std::cout << '\n';
  printGrid(size, width, false);
  std::cout << std::flush;
  std::this_thread::sleep_for(std::chrono::milliseconds(delay));

  for (int placed = 0; placed < total; ++placed) {
    // Jump `step` cells ahead from the random start, wrapping at the end.
    int index = static_cast<int>(
        (start + static_cast<long long>(step) * placed) % total);
    int row = index / size;
    int col = index % size;
    int number = magicValue(row, col, size);

    showStatus(row + 1, col + 1, number, placed + 1, total, width);
    moveCursor(numberRow(gridTop, row), numberColumn(col, width));
    std::cout << std::setw(width) << number << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
  }

  moveCursor(2, 1);
  std::cout << "Complete. Every row, column, and both diagonals sum to " << sum
            << ".\033[K" << std::flush;
  std::this_thread::sleep_for(std::chrono::milliseconds(700));

  clearScreen();
  std::cout << "Completed Magic Box (" << size << " x " << size << ")\n";
  std::cout << "Each row, column, and both diagonals sum to " << sum << ".\n\n";
  printGrid(size, width, true);
  std::cout << std::flush;
}
