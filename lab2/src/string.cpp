#include <iostream>

#include "../include/StringOperations.h"
using namespace std;
const int ARR_SIZE = 101;
char* toUpper(const char input[]) {
  static char upper[ARR_SIZE];
  int i = 0;
  for (i = 0; input[i] != '\0'; i++) {
    if (((input[i] >= 'A' && input[i] <= 'Z') ||
         (input[i] >= 'a' && input[i] <= 'z')) &&
        i <= ARR_SIZE - 1) {
      if (input[i] >= 'A' && input[i] <= 'Z') {
        upper[i] = input[i];

      } else {
        upper[i] = input[i] - 32;
      }
    } else {
      return nullptr;
    }
  }
  if (i <= ARR_SIZE - 1) upper[i++] = '\0';
  return upper;
}
char* toLower(const char input[]) {
  static char lower[ARR_SIZE];
  int i = 0;
  for (i = 0; input[i] != '\0'; i++) {
    if (((input[i] >= 'A' && input[i] <= 'Z') ||
         (input[i] >= 'a' && input[i] <= 'z')) &&
        i <= ARR_SIZE - 1) {
      if (input[i] >= 'a' && input[i] <= 'z') {
        lower[i] = input[i];

      } else {
        lower[i] = input[i] + 32;
      }
    } else {
      return nullptr;
    }
  }
  if (i <= ARR_SIZE - 1) lower[i++] = '\0';
  return lower;
}

void Copy(char destination[], const char source[]) {
  int i = 0;

  while (source[i] != '\0') {
    destination[i] = source[i];
    i++;
  }

  destination[i] = '\0';
}
bool Compare(const char input1[], const char input2[]) {
  int i = 0;
  while ((input1[i] != 0 || input2[i] != 0)) {
    if (input1[i] == input2[i]) {
      i++;
    } else {
      return false;
    }
  }
  return true;
}