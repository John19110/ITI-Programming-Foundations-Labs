
#include "Complex.h"

#include <iostream>
#include <stdexcept>

using namespace std;

Complex::Complex(int real, int img) {
  this->real = real;
  this->img = img;
}

void Complex::setComplex(int real, int img) {
  this->real = real;
  this->img = img;
}

int Complex::getReal() const { return real; }

int Complex::getImg() const { return img; }

void Complex::getComplex() const { cout << *this << endl; }

Complex Complex::operator+(const Complex& C) const {
  return Complex(real + C.real, img + C.img);
}

Complex Complex::operator-(const Complex& C) const {
  return Complex(real - C.real, img - C.img);
}

Complex Complex::operator*(const Complex& C) const {
  return Complex(real * C.real - img * C.img, real * C.img + img * C.real);
}

Complex Complex::operator/(const Complex& C) const {
  int denominator = C.real * C.real + C.img * C.img;

  if (denominator == 0) throw domain_error("Division by zero");

  return Complex((real * C.real + img * C.img) / denominator,
                 (img * C.real - real * C.img) / denominator);
}

Complex Complex::operator+(const int x) const { return Complex(real + x, img); }

Complex Complex::operator-(const int x) const { return Complex(real - x, img); }

Complex Complex::operator*(const int x) const {
  return Complex(real * x, img * x);
}

Complex Complex::operator/(const int x) const {
  if (x == 0) throw domain_error("Division by zero");

  return Complex(real / x, img / x);
}

Complex& Complex::operator++() {
  ++real;
  ++img;

  return *this;
}

Complex Complex::operator++(int) {
  Complex old = *this;

  ++real;
  ++img;

  return old;
}

Complex& Complex::operator+=(const Complex& C) {
  real += C.real;
  img += C.img;

  return *this;
}

bool Complex::operator==(const Complex& C) const {
  return real == C.real && img == C.img;
}

bool Complex::operator!=(const Complex& C) const { return !(*this == C); }

int Complex::operator[](int index) const {
  if (index == 0) return real;

  if (index == 1) return img;

  throw out_of_range("Invalid Complex index");
}

Complex operator+(const int x, const Complex& C) {
  return Complex(x + C.getReal(), C.getImg());
}

Complex operator-(const int x, const Complex& C) {
  return Complex(x - C.getReal(), -C.getImg());
}

Complex operator*(const int x, const Complex& C) {
  return Complex(x * C.getReal(), x * C.getImg());
}

Complex operator/(const int x, const Complex& C) {
  int denominator = C.getReal() * C.getReal() + C.getImg() * C.getImg();

  if (denominator == 0) throw domain_error("Division by zero");

  return Complex((x * C.getReal()) / denominator,
                 (-x * C.getImg()) / denominator);
}

ostream& operator<<(ostream& out, const Complex& C) {
  if (C.getReal() == 0 && C.getImg() == 0) {
    out << "0";
    return out;
  }

  if (C.getReal() != 0) out << C.getReal();

  if (C.getImg() > 0) {
    if (C.getReal() != 0) out << "+";

    out << C.getImg() << "j";

  } else if (C.getImg() < 0) {
    out << C.getImg() << "j";
  }

  return out;
}

// Complex % int
Complex Complex::operator%(const int x) const {
  if (x == 0) throw domain_error("Modulo by zero");

  return Complex(real % x, img % x);
}

bool Complex::operator!() const { return real == 0 && img == 0; }
bool Complex::operator||(const Complex& C) const {
  return (real != 0 || img != 0) || (C.real != 0 || C.img != 0);
}
bool Complex::operator&&(const Complex& C) const {
  return (real != 0 || img != 0) && (C.real != 0 || C.img != 0);
}
std::istream& operator>>(std::istream& in, Complex& C) {
  int real, img;

  if (in >> real >> img) {
    C.setComplex(real, img);
  }

  return in;
}

bool Complex::operator<(Complex C) { return (img < C.img && real < C.real); }

bool Complex::operator>(Complex C) { return (img > C.img && real > C.real); }

bool Complex::operator<=(Complex C) { return (img <= C.img && real <= C.real); }

bool Complex::operator>=(Complex C) { return (img >= C.img && real >= C.real); }
