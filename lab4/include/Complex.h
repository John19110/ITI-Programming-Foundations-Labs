
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iosfwd>

class Complex {
 private:
  int real;
  int img;

 public:
  Complex(int real = 0, int img = 0);

  void setComplex(int real, int img);
  int getReal() const;
  int getImg() const;
  void getComplex() const;

  Complex operator+(const Complex& C) const;
  Complex operator-(const Complex& C) const;
  Complex operator*(const Complex& C) const;
  Complex operator/(const Complex& C) const;

  Complex operator+(const int x) const;
  Complex operator-(const int x) const;
  Complex operator*(const int x) const;
  Complex operator/(const int x) const;

  Complex& operator++();    // Prefix
  Complex operator++(int);  // Postfix

  Complex& operator+=(const Complex& C);

  bool operator==(const Complex& C) const;
  bool operator!=(const Complex& C) const;

  int operator[](int index) const;

  Complex operator%(const int x) const;

  bool operator&&(const Complex& C) const;
  bool operator||(const Complex& C) const;
  bool operator!() const;

  bool Complex::operator<(Complex C);

  bool Complex::operator>(Complex C);

  bool Complex::operator<=(Complex C);

  bool Complex::operator>=(Complex C);
};

Complex operator+(const int x, const Complex& C);
Complex operator-(const int x, const Complex& C);
Complex operator*(const int x, const Complex& C);
Complex operator/(const int x, const Complex& C);

std::istream& operator>>(std::istream& in, Complex& C);

std::ostream& operator<<(std::ostream& out, const Complex& C);

#endif
