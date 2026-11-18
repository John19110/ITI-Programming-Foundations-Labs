
#include <iostream>

#include "Complex.h"

using namespace std;

int main() {
  Complex c1(10, 6);
  Complex c2(3, 2);
  Complex c3;

  c3.setComplex(7, 4);

  c3.getComplex();

  cout << "c1 + c2 = " << c1 + c2 << endl;
  cout << "c1 - c2 = " << c1 - c2 << endl;
  cout << "c1 * c2 = " << c1 * c2 << endl;
  cout << "c1 / c2 = " << c1 / c2 << endl;

  cout << "c1 + 2 = " << c1 + 2 << endl;
  cout << "c1 - 2 = " << c1 - 2 << endl;
  cout << "c1 * 2 = " << c1 * 2 << endl;
  cout << "c1 / 2 = " << c1 / 2 << endl;
  cout << "c1 % 4 = " << c1 % 4 << endl;

  cout << "2 + c1 = " << 2 + c1 << endl;
  cout << "2 - c1 = " << 2 - c1 << endl;
  cout << "2 * c1 = " << 2 * c1 << endl;
  cout << "20 / c1 = " << 20 / c1 << endl;

  Complex c4(2, 3);

  cout << c4 << endl;
  cout << ++c4 << endl;
  cout << c4 << endl;

  cout << "c4++ = " << c4++ << endl;
  cout << c4 << endl;

  Complex c5(1, 2);

  cout << c5 << endl;

  c5 += c2;

  cout << "After c5 += c2: " << c5 << endl;

  Complex c6(5, 3);
  Complex c7(5, 3);
  Complex c8(2, 4);

  cout << "c6 == c7: " << (c6 == c7) << endl;
  cout << "c6 != c7: " << (c6 != c7) << endl;
  cout << "c6 == c8: " << (c6 == c8) << endl;
  cout << "c6 != c8: " << (c6 != c8) << endl;

  cout << "c1[0] (real) = " << c1[0] << endl;
  cout << "c1[1] (imaginary) = " << c1[1] << endl;

  Complex nonZero(5, 3);
  Complex zero(0, 0);
  Complex anotherNonZero(0, 4);

  cout << "nonZero && zero = " << (nonZero && zero) << endl;

  cout << "nonZero && anotherNonZero = " << (nonZero && anotherNonZero) << endl;

  cout << "nonZero || zero = " << (nonZero || zero) << endl;

  cout << "zero || zero = " << (zero || zero) << endl;

  cout << "!nonZero = " << !nonZero << endl;
  cout << "!zero = " << !zero << endl;

  Complex userInput;

  cout << "Enter real and imaginary parts: ";

  cin >> userInput;

  cout << "You entered: " << userInput << endl;

  cout << "c1 = " << c1 << ", c2 = " << c2 << ", c3 = " << c3 << endl;

  return 0;
}
