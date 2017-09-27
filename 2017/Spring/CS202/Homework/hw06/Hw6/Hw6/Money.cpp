//
//  Money.cpp
//  Hw6
//
//  Created by Jim Samson on 4/28/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include "Money.h"
#include <iomanip>
#include <cmath>
#include <exception>

//Default Constructor
Money::Money()
{
    _dollars = 0.00;
    _cents = 0.00;
}

//Constructor (int,int)
Money::Money(int dollars, int cents)
{
    _dollars = (double) dollars;
    _cents = (double) cents;
}

//Constructor (double)
Money::Money(double money)
{
    //Important for homework
    _dollars = (int) money;
    _cents = (std::fabs(money) - (double)std::abs((int)money))*1000;
    _cents = round((double)_cents/10.0);
    _cents = (int) _cents;
}

//Copy Constructor
Money::Money(const Money& rhs)
{
    _dollars = rhs._dollars;
    _cents = rhs._cents;
}

//Ostream operator constructor
ostream &operator<<(ostream& os,const Money&rhs)
{
    os << rhs.toString();
    return os;
}

//Tostring function
string Money::toString() const
{
    ostringstream oss;
    if(_dollars < 0)
    {
        oss << "-$" << _dollars*-1 << ".";
    }
    else
    {
        oss << "$" << _dollars << ".";
    }
    if(_cents < 10)
    {
        oss << "0" << _cents;
    }
    else
    {
        oss << _cents;
    }
    return oss.str();
}

//These are all operator fucntions
Money operator+(Money lhs, const Money&rhs)
{
    return Money{lhs._dollars + rhs._dollars, lhs._cents + rhs._cents};
}

Money operator-(Money lhs, const Money&rhs)
{
    return Money{lhs._dollars - rhs._dollars, lhs._cents - rhs._cents};
}

Money operator/(Money lhs, const Money&rhs)
{
    return lhs /= rhs;
}

Money operator*(Money lhs, const Money&rhs)
{
    return lhs *= rhs;
}

Money & Money::operator-=(const Money &rhs)
{
    _dollars -= rhs._dollars;
    _cents -= rhs._cents;
    return *this;
}

Money & Money::operator+=(const Money &rhs)
{
    _dollars += rhs._dollars;
    _cents += rhs._cents;
    return *this;
}

Money & Money::operator*=(const Money &rhs)
{
    //Important for checking if cents are over 100 cents
    while(_cents >= 100)
    {
        _cents -= 100;
        _dollars++;
    }
    _dollars *= rhs._dollars;
    _cents *= rhs._cents;
    while(_cents >= 100)
    {
        _cents -= 100;
        _dollars++;
    }
    //cout << "After Dollars: " << _dollars << " After Cents: " << _cents << endl;
    return *this;
}

Money & Money::operator/=(const Money &rhs)
{
    //Important for checking if cents are over 100 cents
    while(_cents >= 100)
    {
        _cents -= 100;
        _dollars++;
    }

    if(rhs._dollars != 0)
    {
        _dollars /= rhs._dollars;
    }
    if(rhs._cents != 0)
    {
        _cents /= rhs._cents;
    }

    if(_cents<0) {
        _cents *= -1;
        _dollars *= -1;
    }

    while(_cents >= 100)
    {
        _cents -= 100;
        _dollars++;
    }
    cout << *this << endl;
    return *this;
}

//These are all boolean operator functions
bool operator==(const Money& lhs, const Money& rhs)
{
    return (lhs._dollars == rhs._dollars && lhs._cents == rhs._cents);
}

bool operator!=(const Money& lhs, const Money& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Money& lhs, const Money& rhs)
{
    return (lhs._dollars < rhs._dollars || (lhs._dollars < rhs._dollars && lhs._cents < rhs._cents));
}

bool operator<=(const Money& lhs, const Money& rhs)
{
    return !(rhs < lhs);
}

bool operator>(const Money& lhs, const Money& rhs)
{
    return rhs < lhs;
}

bool operator>=(const Money& lhs, const Money& rhs)
{
    return !(lhs < rhs);
}
