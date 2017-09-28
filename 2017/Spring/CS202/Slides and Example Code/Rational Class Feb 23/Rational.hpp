//
//  Rational.hpp
//  Rational2017
//
//  Created by Chris Hartman on 2/21/17.
//  Copyright © 2017 Chris Hartman. All rights reserved.
//

#ifndef Rational_hpp
#define Rational_hpp

#include <iostream>

class Rational {
    friend std::ostream & operator<<(std::ostream &, const Rational &);
    friend Rational operator+(Rational, const Rational &);
    friend Rational operator-(Rational, const Rational &);
    friend bool operator==(const Rational &, const Rational &);
    friend bool operator<(const Rational &, const Rational &);
public:
    Rational(int=0, int=1); //Constructor
    Rational & operator *=(const Rational &rhs);
    Rational & operator /=(const Rational &rhs);
    Rational & operator +=(const Rational &rhs);
    Rational & operator -=(const Rational &rhs);
private:
    int _numerator;
    int _denominator;
};

Rational operator*(Rational, const Rational &);
Rational operator/(Rational, const Rational &);
bool operator!=(const Rational &, const Rational &);
bool operator>(const Rational &, const Rational &);
bool operator<=(const Rational &, const Rational &);
bool operator>=(const Rational &, const Rational &);
#endif /* Rational_hpp */
