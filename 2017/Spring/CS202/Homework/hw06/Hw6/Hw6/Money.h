//
//  Money.h
//  Hw6
//
//  Created by Jim Samson on 4/28/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef Money_h
#define Money_h

#include <iostream>
#include <ostream>
#include <sstream>
#include <iomanip>

using std::ostringstream;
using std::ostream;
using std::string;
using std::cout;
using std::endl;

class Money
{
    friend bool operator==(const Money&,const Money&);
    friend bool operator<(const Money&,const Money&);
    friend Money operator+(Money,const Money&);
    friend Money operator-(Money,const Money&);

public:
    Money();
    Money(int,int);
    Money(double);
    Money(const Money&);

    string toString() const;

    Money & operator-=(const Money &);
    Money & operator+=(const Money &);
    Money & operator*=(const Money &);
    Money & operator/=(const Money &);

public:
    int _dollars;
    int _cents;
};

//ostream operator<< function
ostream &operator<<(ostream&,const Money&);

//Most of these are canotical code
Money operator/(Money,const Money&);
Money operator*(Money,const Money&);
bool operator!=(const Money&,const Money&);
bool operator<=(const Money&,const Money&);
bool operator>(const Money&,const Money&);
bool operator>=(const Money&,const Money&);

#endif /* Money_h */
