//Jim Samson
//Main.cpp
//This is the main file used to solve complex functions.

#include "Complex.h"

int main()
{
  Complex number(2,3);
  Complex otherNumber(5,8);

  cout << "Here are my objects" << endl;
  cout << "number: " << number << endl;
  cout << "otherNumber: " << otherNumber << endl;
  cout << endl;

  //This chunk of code adds,multiplies,subtracts a number to the complex number
  cout << "1 + number: " <<  1 + number << endl;
  cout << "4 * number: " << 4 * number << endl;
  cout << "3 - number: " << 1 - number << endl;
  cout << endl;

  //This chunk of code adds two complex numbers together.
  cout << "number + otherNumber: " << number + otherNumber << endl;
  cout << "number - otherNumber: " << number - otherNumber << endl;
  cout << "number * otherNumber: " << number * otherNumber << endl;
  cout << endl;

  //This chunk of code adds two complex numbers together. It woks just like A+B
  cout << "(" << number << ") += (" << otherNumber << "): ";
  number += otherNumber;
  cout << number << endl;

  cout << "(" << number << ") -= (" << otherNumber << "): ";
  number -= otherNumber;
  cout << number << endl;

  cout << "(" << number << ") *= (" << otherNumber << "): ";
  number *= otherNumber;
  cout << number << endl;
  cout << endl;


  //This doesn't work. I figured += works only for Complex numbers
  cout << "(" << number << ") += (" << 20 << "): ";
  number += otherNumber;
  cout << number << endl;

  cout << endl;

  return 0;
}
