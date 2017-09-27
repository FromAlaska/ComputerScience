//Jim Samson
//Complex.cpp
//This holds all the data for the Complex Class. It solves the equations. 

#include "Complex.h"

// This spits out the variables of the object
ostream & operator<<(ostream &os, const Complex &rhs)
{
  return os << rhs.real_ << " + " << rhs.imaginary_ << "i";
}

//This adds two objects together
Complex operator+(Complex lhs, const Complex &rhs)
{
  return Complex(lhs.real_ + rhs.real_ , lhs.imaginary_ + rhs.imaginary_);
}

//This subtracts Complex numbers
Complex operator-(Complex lhs, const Complex &rhs)
{
  return Complex(lhs.real_ - rhs.real_ , lhs.imaginary_ - rhs.imaginary_);
}

//This multiplies two complex numbers
Complex operator*(Complex lhs, const Complex &rhs)
{
  return Complex((lhs.real_ * rhs.real_) - (lhs.imaginary_ * rhs.imaginary_), (lhs.real_ * rhs.imaginary_) + (lhs.imaginary_ * rhs.real_));
}

//This is supposed to subtract objects
Complex & Complex::operator-=(const Complex &rhs)
{
  return *this = *this - rhs;
}

//This is just like Complex A - Complex B
Complex & Complex::operator+=(const Complex &rhs)
{
  return *this = *this + rhs;
}

//This is just like Complex A * Complex B
Complex & Complex::operator*=(const Complex &rhs)
{
  return *this = *this * rhs;
}

//Accessors/mutators
int Complex::getReal()
{
  return real_;
}
int Complex::getImaginary()
{
  return imaginary_;
}
void Complex::setReal(int real)
{
  real_ = real;
}
void Complex::setImaginary(int imaginary)
{
  imaginary_ = imaginary;
}
