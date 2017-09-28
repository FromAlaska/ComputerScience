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

void Rational::fixDenominator() {
    if(_denominator<0) {
        _denominator *= -1;
        _numerator *= -1;
    }
}

Rational::Rational(int n, int d) : _numerator{n},_denominator{d}
//default n=0, d=1
{
    if (d==0) {
        throw runtime_error("Zero denominator in Rational constructor");
    }
    fixDenominator();
    auto f = gcd(_numerator,_denominator);
    _numerator /= f;
    _denominator /= f;
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
    fixDenominator();
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

int Rational::gcd(int a, int b)
{
    if (a<0) a*= -1;
    if (b<0) b*= -1;

    if (a==0 && b==0)
        throw std::runtime_error("gcd(0,0) called");
    while (a != b && b != 0) {
        if (a<b)
            std::swap(a,b);
        a -= b;
    }
    return a;
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
{
    return (lhs._numerator * rhs._denominator < rhs._numerator * lhs._denominator);
}

bool operator>(const Rational &lhs, const Rational &rhs)
{ //Canonical
    return rhs<lhs;
}

bool operator<=(const Rational &lhs, const Rational &rhs)
{ //Canonical
    return !(rhs<lhs);
}

bool operator>=(const Rational &lhs, const Rational &rhs)
{ //Canonical
    return !(lhs<rhs);
}
