#ifndef BOXV2_H
#define BOXV2_H

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::equal;
using std::ostringstream;


class Box
{
public:

  enum Type
  {
    Filled, Hollow, Checkered
  };

  //Default constructor.
  Box()
  {
    width_ = 1;
    height_ = 1;
  }

  Box(int width, int height, Type type)
  {
    width_ = width;
    height_ = height;
    boxType_ = type;
  }

  ostream & operator<<(ostream &os, const Box &rhs)
  {
  return os << rhs.toString();
  }

  string toString() const
  {
    ostringstream oss;
    oss << _dat;
    return oss.str();
  }


  void printCoolBox();
  string type() const;
  void print(ostream &) const;
  int getWidth() const;
  int getHeight() const;
  void setWidth(int);
  void setHeight(int);

private:
  int width_;
  int height_;
  int _dat;
  Type boxType_;
};

#endif
