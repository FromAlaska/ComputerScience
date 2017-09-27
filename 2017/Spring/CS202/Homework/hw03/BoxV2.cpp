#include "BoxV2.h"

//Do not use. This is for making a cool box-y looking pattern.
void Box::printCoolBox()
{
  for(int row = 0; row < width_; row++)
  {
    cout << "*";
    for(int spaceRow = 0; spaceRow < width_; spaceRow++)
    {
      cout << " ";
    }

    for(int col = 0; col < height_-1; col++)
    {
      cout << "*";

      for(int space = 0; space < height_; space++)
      {
        cout << " ";
      }
    }
  }
}

//This prints a value to the output to solve for hw2
void Box::print(ostream &output) const
{
  //This will make a filled box
  if(boxType_ == Filled)
  {
    for(int row = 0; row < height_; row++)
    {
      for(int col = 0; col < width_; col++)
      {
        cout << "x";
        output << "x";
      }
      cout << endl;
      output << endl;
    }
  }
  //this will make a hollow box
  if(boxType_ == Hollow)
  {
    if(width_ == 1 && height_ == 1)
    {
      cout << "x" << endl;
      output << "x" << endl;
    }
    else
    {
      // This will make the top of the box
      for(int top = 0; top <= width_-1; top++)
      {
        cout << "x";
        output << "x";
      }
      cout << endl;
      output << endl;

      //This will make the two columns
      for(int col = 1; col <= (height_-2); col++)
      {
        cout << ("x");
        output << "x";

        for(int row = 1; row <= (width_-2); row++)
        {
          cout << (" ");
          output << " ";
        }
         cout << ("x") << endl;
         output << "x" << endl;
      }

      //This will make the bottom of the box
      for(int bottom = 0; bottom <= width_-1; bottom++)
      {
        cout << "x";
        output << "x";
      }
      cout << endl;
      output << endl;
    }
  }
  //This will make a checkered box
  if(boxType_ == Checkered)
  {
    cout << "checkered" << endl;
  }
  else
  {
    cout << "Invalid box type, use either 'checkered', 'hollow', or 'filled' " << endl;
  }
}

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
  if(boxType_ == Filled)
  {
    return "Filled";
  }
  if(boxType_ == Checkered)
  {
    return "Checkered";
  }
  else
  {
    return "Hollow";
  }
}
