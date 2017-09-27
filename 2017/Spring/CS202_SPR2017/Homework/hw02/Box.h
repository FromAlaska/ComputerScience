#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;


class Box
{
public:

  //Default constructor.
  Box()
  {
    width_ = 1;
    height_ = 1;
    filledBoxIfTrue_ = true;
  }

  //This is a constructor. It makes a filled box regardless of the condition.
  Box(int width, int height)
  {
    width_ = width;
    height_ = height;
    filledBoxIfTrue_ = true;
  }

  //This would make a filled box or a hollow box, depending on the boolean.
  Box(int width, int height, bool boxCheck)
  {
    width_ = width;
    height_ = height;
    filledBoxIfTrue_ = boxCheck; //If false, then make the box filled.
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
  bool filledBoxIfTrue_;
};
#endif
