//Jim Samson
//Box.cpp

#include "Box.h"

int Box::boxTotal_ = 0;

//This gets the width of the object
int Box::getWidth() const
{
  return width_;
}
int Box::getHeight() const
{
  return height_;
}

//This sets the width or the height of the object
void Box::setWidth(int width)
{
  width_ = width;
}
void Box::setHeight(int height)
{
  height_ = height;
}

//This returns hollow if true, and filled if false.
string Box::type() const
{
  if(boxType_ == FILLED)
  {
    return "Filled";
  }
  if(boxType_ == CHECKERED)
  {
    return "Checkered";
  }
  if(boxType_ == HOLLOW)
  {
    return "Hollow";
  }
  else
  {
    return "none";
  }
}
