#ifndef lab08_H
#define lab08_H
#include <iostream>
#include <exception>
#include <stdexcept>

using std::cout;
using std::endl;
using std::exception;
using std::string;

class Player
{
public:
  Player()
  {
    cout << "Constructor of a class" << endl;
  }
  ~Player()
  {
    cout << "Destructor of a class" << endl;
    throw std::runtime_error("Blast! Our plans have been foiled!");
  }
};
#endif
