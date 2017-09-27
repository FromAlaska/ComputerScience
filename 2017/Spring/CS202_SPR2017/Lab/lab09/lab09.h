#ifndef lab09_h
#define lab09_h

#include <iostream>

using namespace std;

template <class N>
class Thing
{
public:
    //Integer
    N value;

    Thing(N thing)
    {
        value = thing;
    }

    N getValue();
};


template <class N>
N Thing<N>::getValue()
{
    N returnValue;
    returnValue = value;
    return returnValue;
}

#endif
