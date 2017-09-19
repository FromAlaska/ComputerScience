// product.h
// Jim Samson
// September 11, 2017
//
// For CS311 2017 Fall
// Header for class Product

#ifndef PRODUCT_HPP_FILE
#define PRODUCT_HPP_FILE

#include <sstream> //Additional includes
#include <string>

using std::ostringstream;
using std::ostream;
using std::string;

//*********************************
// Class Product - Class Definition
//*********************************

// class Product
// This class is used for
// Invariants:
//						_numberOfItemsSold >= 0
class Product
{
	// op==
	// Compares the two objects together and returns a boolean
	// Pre: None.
	// Post:
	//			Compares two objects together and returns a boolean.
	friend bool operator==(const Product &, const Product &);

public:

	// Default Constructor for Product.
	// Sets _numberOfItemsSold to zero and _productName to ""
	// Pre: None.
	// Post:
	//			Sets the values for _productName to "" and _numberOfItemsSold to zero.
	Product() : _productName(""), _numberOfItemsSold(0)
	{}

	// Constructor for Product.
	// Sets the values inside the Product class and checks if the number
	// of items sold is less than zero.
	// Pre: Integer CANNOT be less than zero.
	// Post:
	//			Sets the values that were sent to it.
	Product(string, int);

	// Big Five
	// They are all set to default.
	~Product()=default;
	Product(const Product & other)=default;
	Product(Product && other)=default;
	Product & operator=(const Product & other)=default;
	Product & operator=(Product && other)=default;

  // getName
	// Pre: None.
	// Post:
	//			Returns the name of the item.
  string getName() const;

	// getSales
	// Pre: None.
	// Post:
	//			Returns the number of items sold.
	int getSales() const;

	// setName
	// Sets the name of the product
	// Pre: None.
	// Post:
	//			Sets the name of the item of the Product Object
	void setName(string);

	// setName
	// Sets the number of the product sold by using the integer that was sent.
	// Pre: None.
	// Post:
	//			Sets the number of sales of the Product Object
	void setSales(int);

  // toString
	// Gets the product name and number of associated items sold of the product object.
	// Pre: None.
	// Post:
	// 			Puts the given Product object as "'Product name'(sales: )'number of sales'", with product name padded on the
	// 			left, and , (sales: ) are padded on the right. It returns the padded objects as a ostringstream.
	string toString() const;

	// op++ [pre]
	// Pre: None
	// Post:
	//			Increments number of items sold by 1 item and returns *this.
	Product & operator++();

	// op-- [pre]
	// Pre: _numberOfItemsSold !< 0
	// Post:
	//			Decrements the number of items sold by 1 item and returns *this.
	Product & operator--();

	// op++ [post]
	// Pre: None
	// Post:
	//			Increments the number of items sold by 1 item.
	Product operator++(int);

	// op-- [post]
	// Pre: _numberOfItemsSold !< 0
	// Post:
	//			Decrements the number of items sold by 1 item.
	Product operator--(int);

private:
	string _productName;     // Product name of the object.
	int _numberOfItemsSold;  // The number of items sold.
}; // End of class Product.

//************************************************************
// Class Product - Declarations of associated global operators
//************************************************************

// operator!=(Product,Product)
// Compares the given product that will return true or false on the given.
bool operator!=(const Product &, const Product &);

// operator<<(ostream, Product)
// Prints the given Product object as "'Product name'(sales: )'number of sales'", with product name padded on the
// left, and , (sales: ) are padded on the right.
// Pre: None.
// Post:
//     Product object printed to given stream as described.
//     Return is given stream.
ostream & operator<<(ostream &, const Product &);

#endif //PRODUCT_HPP_FILE
