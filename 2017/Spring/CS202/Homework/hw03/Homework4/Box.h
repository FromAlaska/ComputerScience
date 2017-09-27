//
//  Box.h
//  Homework4
//
//  Created by Jim Samson on 3/27/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#ifndef Box_h
#define Box_h

#include <iostream>
#include <string>
#include <sstream>
#include <memory>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::ostringstream;
using std::unique_ptr;
using std::make_unique;

//A Parent Class
class Box
{
public:
    friend ostream & operator<<(ostream &, const Box &);

    //Constructor with two parameters, default box type
    Box(int width,int height): width_(width), height_(height)
    {
        width_ = width;
        height_ = height;
    }

    //This is the copy constructor
    Box(const Box & old)
    {
        width_ = old.width_;
        height_ = old.height_;
    }

    void setWidth(int width)
    {
        width_ = width;
    }

    void setHeight(int height)
    {
        height_ = height;
    }

    int getWidth() const
    {
        return width_;
    }

    int getHeight() const
    {
        return height_;
    }

    virtual ~Box()
    {
    }

    virtual string type() const = 0;
    virtual void print(ostream &os) const = 0;


protected:
    int width_;
    int height_;
};





//This prints the box to the user
inline ostream & operator<<(ostream &output, const Box &rhs)
{
    rhs.print(output);
    return output;
}






//Prints a Filled Box
class FilledBox: public Box
{
public:
    //Default Constructor
    FilledBox(): Box(1,1)
    {}

    //Constructor
    FilledBox(int width, int height): Box(width, height) 
    {}

    virtual string type() const
    {
        return "Filled";
    }

    void print(ostream &output = cout) const
    {
        //This will make a filled box
        for(int col = 0; col < height_; col++)
        {
            for(int row = 0; row < width_; row++)
            {
                cout << "x";
                output << "x";
            }
            cout << endl;
            output << endl;
        }
    }
};








class HollowBox: public Box
{
public:
    //Default Constructor
    HollowBox(): Box(1,1)
    {}

    //Constructor
    HollowBox(int width, int height): Box(width, height)
    {}

    string type() const
    {
        return "Hollow";
    }

    void print(ostream &output) const
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
                cout << "x";
                output << "x";

                for(int row = 1; row <= (width_-2); row++)
                {
                    cout << " ";
                    output << " ";
                }
                cout << "x" << endl;
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
};







class CheckeredBox: public Box
{
public:
    //Default Constructor
    CheckeredBox(): Box(1,1)
    {}

    //Constructor
    CheckeredBox(int width, int height): Box(width, height)
    {}

    string type() const
    {
        return "Checkered";
    }

    void print(ostream &output) const
    {
        for (int col = 0; col < height_; col++)
        {
            for (int row = 0; row < width_; row++)
            {
                if (row%2 == col%2)
                {
                    cout << "x";
                    output << "x";
                }
                else
                {
                    cout << " ";
                    output << " ";
                }
            }
            cout << endl;
            output << endl;
        }
    }
};


unique_ptr<Box> boxFactory(char c, int w, int h)
{
    if(c == 'f')
        return make_unique<FilledBox>(w,h);
    if(c == 'h')
        return make_unique<HollowBox>(w,h);
    else
        return make_unique<CheckeredBox>(w,h);
}

#endif /* Box_h */
