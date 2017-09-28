//
//  main.cpp
//  CS202Spring2017Shape
//
//  Created by Chris Hartman on 3/21/17.
//  Copyright Â© 2017 Chris Hartman. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::unique_ptr;
using std::make_unique;

class Shape {
public:
    Shape(double scale=1.0):_scale(scale)
    {}
    void setScale(double scale){
        _scale=scale;
    }
    double getScale(){
        return _scale;
    }
    virtual void describe() const =0;
    virtual ~Shape()
    {
        cout << "Base class Shape destructor." << endl;
    }

protected:
    double _scale;
};

class Circle : public Shape {
public:
    Circle(double scale=1,double radius=1):Shape(scale),_radius(radius)
    {}

    ~Circle()
    {
        cout << "Circle class Shape destructor." << endl;
    }

    void virtual describe() const override
    {
        cout << "I'm a Circle with scale " << _scale <<
        " and radius " << _radius << endl;
    }
private:
    double _radius;
};

class Square : public Shape {
public:
    Square(double scale=1,double side=1):Shape(scale),_side(side)
    {}

    void virtual describe() const override
    {
        cout << "I'm a Square with scale " << _scale <<
        " and side length " << _side << endl;
    }
private:
    double _side;
};

unique_ptr<Shape> getShape()
{
    if(rand()%2)
        return make_unique<Circle>();
    else
        return make_unique<Square>();
}

void foo(const Shape &s)
{
    cout << "In foo: ";
    s.describe();
}

int main() {
    srand((unsigned int)time(0));
//    Shape s(1.0);
//
//    s.describe();
//
//    Circle c(13);
//    c.setScale(13);
//
//    c.describe();
//
//    Square s2(4,5);
//    s2.describe();

    auto shapePtr = getShape();

    cout << "In main: ";
    shapePtr->describe();

    foo(*shapePtr);

//    Shape s2;
//    s2.describe();
    return 0;
}
