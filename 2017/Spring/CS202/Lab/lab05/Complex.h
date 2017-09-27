//Jim Samson
//Complex.h
//This is the Complex Class, it solves complex functions. It can train hamsters to rule the world.
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::ostream;
using std::ostringstream;
using std::string;

class Complex
{
  friend ostream & operator<<(ostream &, const Complex &);
  friend Complex operator+(Complex, const Complex &);
  friend Complex operator-(Complex, const Complex &);
  friend Complex operator*(Complex, const Complex &);
public:
  //Default constructor, and constructors
  Complex()
  {
    real_ = 0;
    imaginary_=0;
  }
  Complex(int real)
  {
    real_ = real;
  }
  Complex(int a, int b)
  {
    real_ = a;
    imaginary_ = b;
  }

  //Getting real and imaginary numbers
  int getReal();
  int getImaginary();
  void setReal(int);
  void setImaginary(int);

  Complex & operator+=(const Complex &);
  Complex & operator-=(const Complex &);
  Complex & operator*=(const Complex &);
  Complex & operator/=(const Complex &);

private:
  int real_;
  int imaginary_;
};

//Overloading Function prototype. Important.

#endif
