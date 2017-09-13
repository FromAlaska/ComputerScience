// product.cpp
// Jim Samson
// 11 Sep 2017
//
// For CS 311 Fall 2017
// CPP file for Product.h


#include "product.h"
#include "product.h"

Product::Product(string name, int sales)
{
   _productName = name;
   _numberOfItemsSold = sales;
}

string Product::getName() const
{
   return _productName;
}

int Product::getSales() const
{
   return _numberOfItemsSold;
}

void Product::setName(string name)
{
  _productName = name;
}

void Product::setSales(int itemsSold)
{
   _numberOfItemsSold = itemsSold;
}

bool operator==(const Product & lhs, const Product & rhs)
{
  return (lhs._numberOfItemsSold == rhs._numberOfItemsSold);
}

bool operator!=(const Product & lhs, const Product & rhs)
{
  return !(lhs == rhs);
}

Product & Product::operator++()
{
  ++_numberOfItemsSold;
  return *this;
}

Product & Product::operator--()
{
  if(_numberOfItemsSold == 0)
  {
    return *this;
  }
  --_numberOfItemsSold;
  return *this;
}

Product Product::operator++(int increment)
{
  Product temp(_productName,_numberOfItemsSold);
  ++_numberOfItemsSold;
  return temp;
}

Product Product::operator--(int decrement)
{
  Product temp(_productName,_numberOfItemsSold);
  --_numberOfItemsSold;
  return temp;
}

string Product::toString() const
{
    ostringstream oss;
    oss << _productName << "(sales: " << _numberOfItemsSold << ")";
    return oss.str();
}
