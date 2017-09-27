// ksarray.h
// Jim Samson
// September 18, 2017
//
// For CS311 2017 Fall
// Header for ksarray.cpp

#ifndef KS_ARRAY_H
#define KS_ARRAY_H

#include <cstddef>
#include <utility>
#include <algorithm>
#include <typeinfo>

using std::swap;
using std::equal;
using std::min;
using std::copy;

//*****************************
// Class array
//*****************************

// Class KSArray
// This class creates a "smart" array class that tracks its size.
// This is compiled using the C++14 Standard.
// Invariants:
//            0 >= ArraySize
template <typename ValType>
class KSArray
{

public:

  // Size Types & Value types
  using size_type = std::size_t;
  using value_type = ValType;

  // Default ctor
  // Creates an array of a size 10.
  // Pre: None.
  // Post:
  //      - Allocates an array size of 10
  //      - Allocates a pointer size using the _arraySize
  KSArray(): _arraySize(10), _arrayPtr(new value_type[_arraySize])
  {}

  // Const Constructor
  // Creates an object using value from the parameter.
  // Pre: Value is not negative.
  // Post:
  //      - Checks if value is not negative.
  //      - Assigns the array size
  //      - Assigns a new array ptr.
  KSArray(const size_type arraySize): _arraySize(arraySize), _arrayPtr(new value_type[arraySize])
  {}

  // Const Copy Constructor
  // Copies all of the data from A to B.
  // Pre: Array size cannot be negative
  // Post:
  //      - Copies the array size from other.
  //      - Sets the new copy from the array other.
  KSArray(const KSArray<ValType> & other): _arraySize(other._arraySize), _arrayPtr(new value_type[_arraySize])
  {
    for(int increment = 0; increment < _arraySize; increment++)
      {
          *(_arrayPtr + increment) = *(other._arrayPtr + increment);
      }
  }

  // Move constructor
  // Moves all of the data from A to B.
  // Pre: None.
  // Post:
  //      - This swaps array size from object B to object A.
  //      - This swaps array ptr from object B to object A.
  KSArray(KSArray<ValType> && other) noexcept :_arraySize(0), _arrayPtr(NULL)
  {
    swap(_arraySize,other._arraySize);
    swap(_arrayPtr,other._arrayPtr);
  }

  // Copy assignment operator
  // Copies values from a new Object A to Object B
  // Pre: None.
  // Post:
  //      - Copies the value from rhs to new object A.
  KSArray & operator=(const KSArray<ValType> & rhs)
  {
    if(this != &rhs)
    {
      delete[] _arrayPtr;

      _arrayPtr = new value_type[rhs._arraySize];
      _arraySize = rhs._arraySize;

      copy(rhs.begin(),rhs.end(),_arrayPtr);
    }
    return *this;
  }

  // Move assignment
  // Moves all the objects from rhs to object and destroys rhs.
  // Pre: None.
  // Post:
  //      - Copies the value from rhs, then destroys it.
  KSArray & operator=(KSArray<ValType> && rhs) noexcept
  {
    if(this != &rhs)
    {
      swap(_arraySize,rhs._arraySize);
      swap(_arrayPtr,rhs._arrayPtr);
    }
    return *this;
  }

  // Destructor
  // This frees any dynamically allocated memory.
  // Pre: None.
  // Post:
  //      - Frees all allocated memory from the pointer.
  ~KSArray()
  {
    delete[] _arrayPtr;
  }

  // size
  // Returns the number of items in the array.
  // Pre: None.
  // Post:
  //      - Returns the size of the array.
  size_type size() const
  {
    return _arraySize;
  }

  // begin (non-const)
  // Returns the address of item 0 in the array (think “iterator”).
  // Pre: None.
  // Post:
  //      - Returns the first element of the array ptr.
  ValType * begin()
  {
    return _arrayPtr;
  }

  // begin (const)
  // Returns the address of item 0 in the array (think “iterator”).
  // Pre: None.
  // Post:
  //      - Returns the first element of the array ptr.
  const ValType * begin() const
  {
    return _arrayPtr;
  }

  // end (non-const)
  // Returns the address of the item one-past the end of the array (think “iterator”).
  // Pre: None.
  // Post:
  //      - Returns the address of the last element of the array.
  ValType * end()
  {
    return _arrayPtr + _arraySize;
  }

  // end (const)
  // Returns the address of the item one-past the end of the array (think “iterator”).
  // Pre: None.
  // Post:
  //      - Returns the address of the last element of the array.
  const ValType * end() const
  {
    return _arrayPtr + _arraySize;
  }

  // Bracket operator
  // Creates an array pointer with the size.
  // Pre: Index must not be negative.
  // Post:
  //      - Creates an array pointer with the size.
  const ValType & operator[](const size_type & index) const
  {
    return _arrayPtr[index];
  }

  // Bracket operator non-const
  // Creates an array pointer with the size.
  // Pre: Integer must not be negative.
  // Post:
  //      Creates an array pointer with the size.
  ValType & operator[](const size_type & index)
  {
    return _arrayPtr[index];
  }

  // Operator ==
  // Compares object A and B and returns a boolean.
  // Two KSArray objects with the same value type are equal
  // if they have the same size and their corresponding items are all equal.
  // Pre: - Two KSArray objects with different value types cannot be compared.
  //      - Value type cannot be different.
  //      - Returns a boolean if Object A is equal to Object B.
  // Post:
  //      Returns a boolean if object A is equal to object B
  friend bool operator==(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
  {
    if(lhs.size() == rhs.size())
    {
      return equal(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    }
    return false;
  }

  // Operator <
  // Compares object A and B and returns a boolean.
  // Pre: Two KSArray objects with different value types cannot be compared.
  // Post:
  //      - Returns a boolean if either object A is less than object B.
  friend bool operator<(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
  {
    for(size_t iterator = 0; iterator < min(lhs._arraySize,rhs._arraySize); iterator++)
    {
        if(lhs[iterator] < rhs[iterator])
        {
            return true;
        }
        if(lhs[iterator] > rhs[iterator])
        {
            return false;
        }
    }
    return lhs._arraySize < rhs._arraySize;
  }

private:
  size_type _arraySize; // Member Variables
  value_type *_arrayPtr;
}; // End of Class KSArray

//************************************************************
// Class KSArray - Declarations of associated global operators
//************************************************************

// Operator !=
// Compares objects A and B, then returns a boolean. Using Canonical code.
// Pre: Two KSArray objects with different value types cannot be compared.
// Post:
//      - Checks to see if object A is not equal to object B
//      - Uses Canonical coding.
template <typename ValType>
bool operator!=(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return !(lhs == rhs);
}

// Operator >
// Compares object A and B and returns a boolean
// Pre: Two KSArray objects with different value types cannot be compared.
// Post:
//      - Returns a boolean if either object A is greater than object B.
template <typename ValType>
bool operator>(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return (rhs < lhs);
}

// Operator <=
// Compares object A and B and returns a boolean
// Pre: Two KSArray objects with different value types cannot be compared.
// Post:
//      - Returns a boolean if either object A is less or equal to object B.
template <typename ValType>
bool operator<=(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return !(rhs < lhs);
}

// Operator >=
// Compares object A and B and returns a boolean
// Pre: Two KSArray objects with different value types cannot be compared.
// Post:
//      - Returns a boolean if either object A is less or equal to object B.
template <typename ValType>
bool operator>=(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return !(lhs < rhs);
}

#endif //KS_ARRAY_FILE
