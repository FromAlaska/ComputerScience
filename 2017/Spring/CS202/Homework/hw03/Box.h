//Jim Samson
//Box.h
//Computer Science
//This is version two of the box class. It includes an overloaded operator class,
//an enum class, constructor and destructor, it also checks for how much times this
//class has been called.

//How to add more types for the box:
//1. Add a type of box under enum Type.
//2. Under the type() function, add an if statement to check if your type is equal to it.
//3. Under the overloaded << function, add code related to the new type of function.
//4. Hack Facebook, gain money, attain women.

ifndef BOX_H
#define BOX_H

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::ostringstream;


class Box
{
public:
  friend ostream & operator<<(ostream &, const Box &);
  static int boxTotal_;

  enum Type
  {
    FILLED,
    HOLLOW,
    CHECKERED
  };

  //Default constructor.
  Box()
  {
    width_ = 1;
    height_ = 1;
    boxTotal_++;
    boxType_ = FILLED;
  }

  //Constructor with two parameters, default box typw
  Box(int width, int height)
  {
    width_ = width;
    height_ = height;
    boxType_ = FILLED;
    boxTotal_++;
  }

  //Constructor with three parameters, sets the default to the type requested
  Box(int width, int height, Type type)
  {
    width_ = width;
    height_ = height;
    boxType_ = type;
    boxTotal_++;
  }

  //This is the copy constructor
  Box(const Box & old)
  {
    width_ = old.width_;
    height_ = old.height_;
    boxType_ = old.boxType_;
    boxTotal_++;
  }

  //This is the destructor
  ~Box()
  {
    boxTotal_--;
  }

  //This gets the value of how much boxes were made
  static int howMany()
  {
    return boxTotal_;
  }

  string type() const;
  ostream & print(ostream &);

  //General accessors and mutators
  int getWidth() const;
  int getHeight() const;
  void setWidth(int);
  void setHeight(int);

private:
  int width_;
  int height_;
  Type boxType_; //Important. This gets the enumerated type
};

//This prints the box to the user
inline ostream & operator<<(ostream &output, const Box &rhs)
{
  //This will make a filled box
  if(rhs.boxType_ == Box::FILLED)
  {
    for(int row = 0; row < rhs.height_; row++)
    {
      for(int col = 0; col < rhs.width_; col++)
      {
        output << "x";
      }
      output << endl;
    }
  }

  //this will make a hollow box
  if(rhs.boxType_ == Box::HOLLOW)
  {
    if(rhs.width_ == 1 && rhs.height_ == 1)
    {
      output << "x" << endl;
    }
    else
    {
      // This will make the top of the box
      for(int top = 0; top <= rhs.width_-1; top++)
      {
        output << "x";
      }
      output << endl;

      //This will make the two columns
      for(int col = 1; col <= (rhs.height_-2); col++)
      {
        output << "x";

        for(int row = 1; row <= (rhs.width_-2); row++)
        {
          output << " ";
        }
         output << "x" << endl;
      }

      //This will make the bottom of the box
      for(int bottom = 0; bottom <= rhs.width_-1; bottom++)
      {
        output << "x";
      }
      output << endl;
    }
  }

  //This creates a checkered box
  if(rhs.boxType_ == Box::CHECKERED)
  {
    int count = 0;
    for (int row = 0; row < rhs.height_; x++)
    {
      for (int col = 0; col < rhs.width_; y++)
      {
        if ((count++ % 2) == 0)
        {
          output << "x";
          cout << "x";
        }
        else
        {
          output << " ";
          cout << " ";
        }
      }
      cout << endl;
      output << endl;
    }
  }
  return output;
}
#endif
