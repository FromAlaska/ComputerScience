//
//  Hw5.h
//  HW5
//
//  Created by Jim Samson on 4/27/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef Hw5_h
#define Hw5_h

#include <iostream>
#include <ostream>
#include <vector>

template <typename T>
void printVector(std::ostream& os, std::vector<T> t)
{
    for(unsigned int begin = 0; begin < t.size(); ++begin)
    {
        os << t[begin] << std::endl;
    }
}

template <typename T>
class RAIIPtr
{
public:
    RAIIPtr(T*);
    ~RAIIPtr();

    T &operator*();
    T *operator->();
private:
    T* _ptr;
};

template <typename T>
RAIIPtr<T>::RAIIPtr(T*outer)
{
    this -> _ptr = outer;
}

template <typename T>
RAIIPtr<T>::~RAIIPtr()
{
    delete _ptr;
}

template <typename T>
T & RAIIPtr<T>::operator*()
{
    return *_ptr;
}

template <typename T>
T * RAIIPtr<T>::operator->()
{
    return _ptr;
}

#endif /* Hw5_h */
