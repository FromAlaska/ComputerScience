//
//  Rational.cpp
//  Rational2017
//
//  Created by Chris Hartman on 2/21/17.
//  Copyright Â© 2017 Chris Hartman. All rights reserved.
//

#include "Rational.hpp"
#include <exception>
using std::runtime_error;

Rational::Rational(int n, int d) //default n=0, d=1
{
    _numerator=n;
    if (d==0)
        throw runtime_error("Zero denominator in Rational constructor");
    _denominator=d;
}

Rational & Rational::operator *=(const Rational &rhs)
{
    _numerator *= rhs._numerator;
    _denominator *= rhs._denominator;
    return *this;
}

Rational & Rational::operator /=(const Rational &rhs)
{
    _numerator *= rhs._denominator;
    _denominator *= rhs._numerator;
    return *this;
}

Rational & Rational::operator +=(const Rational &rhs)
{
    return *this = *this + rhs;
}

Rational & Rational::operator -=(const Rational &rhs)
{
    return *this = *this - rhs;
}

//Rational operator*(const Rational &lhs, const Rational &rhs) { //canonical
//    Rational temp(lhs);
//    return temp *= rhs;
//}
// can be optimized as below

Rational operator*(Rational lhs, const Rational &rhs) { //canonical
    return lhs *= rhs;
}

Rational operator/(Rational lhs, const Rational &rhs) { //canonical
    return lhs /= rhs;
}

Rational operator+(Rational lhs, const Rational &rhs) { //canonical
    return Rational{lhs._numerator*rhs._denominator + lhs._denominator*rhs._numerator,
        rhs._denominator*lhs._denominator};
}

Rational operator-(Rational lhs, const Rational &rhs) { //canonical
    return Rational{lhs._numerator*rhs._denominator - lhs._denominator*rhs._numerator,
        rhs._denominator*lhs._denominator};
}

std::ostream & operator<<(std::ostream &out, const Rational &rhs) {
    return out << rhs._numerator << "/" << rhs._denominator;
}

bool operator==(const Rational &lhs, const Rational &rhs)
{
    return (lhs._numerator * rhs._denominator == rhs._numerator * lhs._denominator);
}

bool operator!=(const Rational &lhs, const Rational &rhs)
{//Canonical!!
    return !(lhs==rhs);
}

bool operator<(const Rational &lhs, const Rational &rhs)
{ // !!! THIS isn't right for negatives...
    return (lhs._numerator * rhs._denominator < rhs._numerator * lhs._denominator);
}

bool operator>(const Rational &lhs, const Rational &rhs)
{ //Canonical
// !!! THIS isn't right for negatives...
    return rhs<lhs;
}

bool operator<=(const Rational &lhs, const Rational &rhs)
{ //Canonical
    // !!! THIS isn't right for negatives...
    return !(rhs<lhs);
}

bool operator>=(const Rational &lhs, const Rational &rhs)
{ //Canonical
    // !!! THIS isn't right for negatives...
    return !(lhs<rhs);
}
