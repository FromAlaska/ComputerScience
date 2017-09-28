//
//  SmartArayy.cpp
//  Spring2017CS202SmartArray
//
//  Created by Chris Hartman on 3/2/17.
//  Copyright Â© 2017 Chris Hartman. All rights reserved.
//

#include "SmartArray.hpp"

#include <stdexcept>
using std::runtime_error;

//Constructor
SmartArray::SmartArray(int size)
{
    _size = size;
    _data = new int [_size];
}

//Copy Constructor
SmartArray::SmartArray(const SmartArray &old)
{
    _size = old._size;
    _data = new int [_size];
    for(int ii=0;ii<_size;++ii)
        _data[ii] = old[ii];
}

SmartArray & SmartArray::operator=(const SmartArray &rhs)
{
    if (this != &rhs) {             // Always check self-assign
        delete [] _data;            // Destructor

        _size = rhs._size;          // Copy Constructor
        _data = new int [_size];    // Copy Constructor
        for(int ii=0;ii<_size;++ii) // Copy Constructor
            _data[ii] = rhs[ii];    // Copy Constructor
    }
    return *this;
}

//returning the size
int SmartArray::size() const
{
    return _size;
}

//Destructor. It gives the memory back to the computer
SmartArray::~SmartArray()
{
    delete [] _data;
}

//Overloaded operator[] Constructor
int & SmartArray::operator[](int index)
{
//    if (index < 0 || index >= _size)
//        throw runtime_error("int & SmartArray::operator[](int index) had out of bounds index");
    return _data[index];
}

int SmartArray::operator[](int index) const
{
    return _data[index];
}
