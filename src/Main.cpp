#include <iostream>

#include "../include/StringOperations.h"
using namespace std;
int main() {
  char arr[20] = "welovelinux";
  cout << endl << toUpper(arr) << endl;

  char arr2[20] = {'W', 'e', 'L', 'O', 'V', 'E', 'L', 'I', 'N', 'U', 'X', '\0'};
  cout << endl << toLower(arr2) << endl;

  char source[] = "fc";
  char destination[100];

  Copy(destination, source);
  cout << endl << destination << endl;

  cout << endl << Compare(arr2, arr);
  return 0;
}