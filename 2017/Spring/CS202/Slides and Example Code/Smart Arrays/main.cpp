//
//  main.cpp
//  Spring2017CS202SmartArray
//
//  Created by Chris Hartman on 3/2/17.
//  Copyright Â© 2017 Chris Hartman. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

#include "SmartArray.hpp"

int main() {

    SmartArray s(30);

    for(int ii=0;ii<30;++ii)
        s[ii] = ii;

    cout << s[23] << endl;

    {
        SmartArray copy(s);
        cout << copy[12] << endl;
    }

    cout << s[13] << endl;

    cout << s[-3] << endl;
    return 0;
}
