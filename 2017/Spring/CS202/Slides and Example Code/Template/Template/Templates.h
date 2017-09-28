//
//  Templates.h
//  Playground
//
//  Created by Chris Hartman on 4/11/17.
//  Copyright Â© 2017 Chris Hartman. All rights reserved.
//

#ifndef Templates_h
#define Templates_h
#include <iostream>


template <typename T>
T timesTwo(T x)
{
    return 2*x;
}

template <typename T>
void foo(T &x)
{
    x *= 2;
    std::cout << x << std::endl;
}

void foo(int &x);

template <typename Func>
int doubleFunctionCaller(Func f, int x)
{
    return f(f(x));
}

template <typename T, typename S>
void foo(T t, const S &s)
{
    std::cout << t << " " << s << std::endl;
}

#endif /* Templates_h */
