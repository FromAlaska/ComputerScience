// product.h
// Jim Samson
// CS311
// September 11, 2017
// This is for Assignment 1
// This is the Product hpp code

#ifndef PRODUCT_HPP_FILE
#define PRODUCT_HPP_FILE

#include <sstream>
#include <string>

using std::ostringstream;
using std::ostream;
using std::string;

// class Product
// product name
// Invariants:
//	ints
class Product
{
	friend bool operator==(const Product &, const Product &);

public:
	Product() : _productName(""), _numberOfItemsSold(0)
	{}

	Product(string, int);

	//Big Five
	~Product()=default;
	Product(const Product & other)=default;
	Product(Product && other)=default;
	Product & operator=(const Product & other)=default;
	Product & operator=(Product && other)=default;

  string getName() const;
	int getSales() const;
	void setName(string);
	void setSales(int);

	string toString() const;

	Product & operator++();
	Product & operator--();

	Product operator++(int);
	Product operator--(int);

private:
	string _productName;
	int _numberOfItemsSold;
};

bool operator!=(const Product &, const Product &);

ostream & operator<<(ostream & str,
			   const Product & obj)
{
	str << obj.toString();
   return str;
}

#endif //PRODUCT_HPP_FILE
