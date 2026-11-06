#pragma once

// Asks until the user enters an odd size from 1 to 9.
// Returns that size, or -1 if input ends.
int readBoxSize();

// Clears the screen, reveals each number one at a time, then prints
// the finished magic box.
void showMagicBox(int size);
