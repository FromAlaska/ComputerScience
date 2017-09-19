// product.cpp
// Jim Samson
// 11 Sep 2017
//
// For CS 311 Fall 2017
// Source file for Product.h

#include "product.h"
#include "product.h"

// Product::Product
// See header for documentation.
Product::Product(string name, int sales)
{
   _productName = name;
   _numberOfItemsSold = sales;
}

// Product::getName
// See header for documentation.
string Product::getName() const
{
   return _productName;
}

// Product getSales
// See header for documentation.
int Product::getSales() const
{
   return _numberOfItemsSold;
}

// Product::setName
// See header for documentation.
void Product::setName(string name)
{
  _productName = name;
}

// Product::setSales
// See header for documentation.
void Product::setSales(int itemsSold)
{
   _numberOfItemsSold = itemsSold;
}

// op==
// See header for documentation.
bool operator==(const Product & lhs, const Product & rhs)
{
  // Checks if the two objects are equal to each other.
  return (lhs._numberOfItemsSold == rhs._numberOfItemsSold && lhs._productName == rhs._productName);
}

// op!=
// See header for documentation.
bool operator!=(const Product & lhs, const Product & rhs)
{
  // Canonical coding!!! Professor Hartman would be proud.
  // It sends the two objects to op== and returns false if the
  // two objects are not equal to each other.
  return !(lhs == rhs);
}

// Product::op++ [pre]
// See header for documentation.
Product & Product::operator++()
{
  ++_numberOfItemsSold;
  return *this;
}

// Product::op-- [pre]
// See header for documentation.
Product & Product::operator--()
{
  // Before this decrements, it checks to ses if the
  // number of items are greater than zero. If not,
  // it returns *this.
  if(_numberOfItemsSold > 0)
  {
    --_numberOfItemsSold;
  }
  return *this;
}

// Product::op++ [post]
// See header for documentation.
Product Product::operator++(int increment)
{
  Product temp(_productName,_numberOfItemsSold);
  ++_numberOfItemsSold;
  return temp;
}

// Product::op-- [post]
// See header for documentation.
Product Product::operator--(int decrement)
{
  // Before this decrements, it checks to ses if the
  // number of items are greater than zero. If not,
  // it returns the temporary object.

   Product temp(_productName,_numberOfItemsSold);

   if(_numberOfItemsSold > 0)
   {
     --_numberOfItemsSold;
   }
 return temp;
}

// Product::toString
// See header for documentation.
string Product::toString() const
{
    ostringstream oss;
    oss << _productName << " (sales: " << _numberOfItemsSold << ")";
    return oss.str();
}

// op<<(ostream,Product)
// See header for documentation.
ostream & operator<<(ostream & str, const Product & obj)
{
	str << obj.toString();
   return str;
}
