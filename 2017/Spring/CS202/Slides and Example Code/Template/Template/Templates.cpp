//
//  Templates.cpp
//  Playground
//
//  Created by Chris Hartman on 4/11/17.
//  Copyright Â© 2017 Chris Hartman. All rights reserved.
//

#include "Templates.h"
#include <iostream>

void foo(int &x)
{
    x *= 2;
    std::cout << "Int version! " << x << std::endl;
}
