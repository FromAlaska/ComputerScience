//
//  main.cpp
//  Rational2017
//
//  Created by Chris Hartman on 2/21/17.
//  Copyright Â© 2017 Chris Hartman. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

#include "Rational.hpp"


int main() {
    Rational one(1);
    Rational zero;
    Rational oneHalf (1,2);

    cout << "one is " << one << endl;
    cout << "zero is " << zero << endl;
    cout << "oneHalf is " << oneHalf << endl;

    Rational r(5);
    r *= oneHalf;
    cout << "r is " << r << endl;
    r *= oneHalf;
    cout << "r is " << r << endl;
    r *= oneHalf;
    cout << "r is " << r << endl;
    r *= oneHalf;
    cout << "r is " << r << endl;

    cout << oneHalf * 13 * oneHalf << endl;
    cout << 13/one << endl;
    cout << 1/oneHalf << endl;
    cout << oneHalf+oneHalf << endl;
    Rational x(3);
    x += oneHalf;
    cout << x << endl;

    cout << zero - one << endl;
    Rational r2(zero-one);
    cout << 1/r2 << endl;
    if (oneHalf == one/2)
        cout << "oneHalf == one/2" << endl;
    if (oneHalf+oneHalf == one)
        cout << "oneHalf+oneHalf == one" << endl;
    if (oneHalf+oneHalf != one)
        cout << "oneHalf+oneHalf != one" << endl;
    if (oneHalf+zero != one)
        cout << "oneHalf+zero != one" << endl;
    if (one < oneHalf)
        cout << "one < oneHalf" << endl;
    if (oneHalf < one)
        cout << "oneHalf < one" << endl;

    Rational comp(2482,1056);
    cout << comp << endl;

    return 0;
}
