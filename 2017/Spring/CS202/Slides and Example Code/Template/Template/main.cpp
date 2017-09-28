//
//  main.cpp
//  Playground
//
//  Created by Chris Hartman on 4/17/15.
//  Copyright (c) 2015 Chris Hartman. All rights reserved.
//

#include <string>
using std::string;
#include <memory>
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <chrono>
#include <cstdio>
#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ostream;
#include <vector>
using std::vector;
#include <initializer_list>
#include <numeric>
#include <functional>
#include <algorithm>
#include <sstream>
using std::istringstream;
#include <stdexcept>
using std::runtime_error;
#include <iostream>
#include <fstream>
#include "Templates.h"
#include "Wrap.hpp"

using std::ifstream;  //for input files (similar to cin)
using std::cout;
using std::endl;

int g(int r)
{
    return r+1;
}

int main()
{
    cout << timesTwo(3) << endl;
    cout << timesTwo(3.1) << endl;
    cout << timesTwo<int>(3.2) << endl;

    int f=7;
    double d=7.7;
    foo(f);
    foo(d);

    foo(3,string{"Hello"});
    foo(6.7,'h');

    cout << endl;
    cout << g(4) << endl;
    cout << doubleFunctionCaller(g, 4) << endl;
    cout << "------------------" << endl;

    int x=13;
    int *ptr = &x;

    cout << *ptr << endl;

    Wrap<int> ptr2(35);
    //    *ptr2 = 35;
    cout << *ptr2 << endl;

    auto ptr3 = make_wrap(3.5);

    cout << *ptr3 << endl;

}
