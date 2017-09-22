// ksarray.h
// Jim Samson
// September 18, 2017
//
// For CS311 2017 Fall
// Header for ksarray.cpp

#ifndef KS_ARRAY_FILE
#define KS_ARRAY_FILE

#include <cstddef>

//*****************************
// Class array
//*****************************

// Class KSArray
//
// Invariants:
//            f
template <class ValType>
class KSArray
{
  // Operator ==
  // Compares object A and B and returns a boolean.
  // Two KSArray objects with the same value type are equal
  // if they have the same size and their corresponding items are all equal.
  // Pre: Two KSArray objects with different value types cannot be compared.
  // Post:
  friend bool operator==(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
  {
    return (lhs._arraySize == rhs._arraySize);
  }

  // Operator <
  // Compares object A and B and returns a boolean.
  // Pre:
  // Post:
  friend bool operator<(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
  {
    return (lhs._arraySize < rhs._arraySize);
  }

public:

  // Size Types & Value types
  using size_type = std::size_t;
  using value_type = ValType;

  // Default ctor
  // Creates an array of a size 10.
  // Pre: None.
  // Post:
  KSArray(): _arrayPtr(new value_type[10]), _arraySize(10)
  {}

  // Const Constructor
  // Creates an object using value from the parameter.
  // Pre: Value CANNOT be negative.
  // Post:
  //KSArray(ValType arraySize): _arraySize(arraySize)
  //{}

  // Constructor
  // Creates an object using value from the parameter.
  // Pre: Value CANNOT be negative.
  // Post:
  KSArray(const size_type arraySize): _arrayPtr(new value_type[arraySize]), _arraySize(arraySize)
  {}

  // Destructor
  // This frees any dynamically allocated memory.
  // Pre:
  // Post:
  ~KSArray()
  {
    delete _arrayPtr;
  }

  // Copy Constructor
  // Copies all of the data from A to B.
  // Pre:
  // Post:
  KSArray(const KSArray<ValType> &);

  // size
  // Returns the number of items in the array.
  // Pre:
  // Post:
  ValType size() const
  {
    return _arraySize;
  }

  // begin (non-const)
  // Returns the address of item 0 in the array (think “iterator”).
  // Pre:
  // Post:
  ValType * begin()
  {
    return &_arrayPtr[0];
  }

  // begin (const)
  // Returns the address of item 0 in the array (think “iterator”).
  // Pre:
  // Post:
  const ValType * begin() const
  {
    return &_arrayPtr[0];
  }

  // end (non-const)
  // Returns the address of the item one-past the end of the array (think “iterator”).
  // Pre:
  // Post:
  ValType * end()
  {
    return &_arrayPtr[_arraySize];
  }

  // end (const)
  // Returns the address of the item one-past the end of the array (think “iterator”).
  // Pre:
  // Post:
  const ValType * end() const
  {
    return &_arrayPtr[_arraySize];
  }

  // Big Five, well at least three of the big five
  KSArray(KSArray<ValType> &&)=default;
  KSArray & operator=(const KSArray<ValType> &)=default;
  KSArray & operator=(KSArray<ValType> &&)=default;

  // Bracket operator
  //
  // Pre:
  // Post:
  const value_type & operator[](const size_type & index) const
  {
    return _arrayPtr[index];
  }

  // Bracket operator non-const
  //
  // Pre:
  // Post:
  value_type & operator[](const size_type & index)
  {
    return _arrayPtr[index];
  }

private:
  ValType _arraySize;
  ValType *_arrayPtr;
};

//************************************************************
// Class KSArray - Declarations of associated global operators
//************************************************************

// Operator !=
// Compares objects A and B, then returns a boolean. Using Canonical code.
// Pre: Two KSArray objects with different value types cannot be compared.
// Post:
template <class ValType>
bool operator!=(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return !(lhs == rhs);
}

// Operator >
// Compares object A and B and returns a boolean
// Pre:
// Post:
template <class ValType>
bool operator>(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return (rhs < lhs);
}

// Operator <=
// Compares object A and B and returns a boolean
// Pre:
// Post:
template <class ValType>
bool operator<=(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return !(rhs < lhs);
}

// Operator >=
// Compares object A and B and returns a boolean
// Pre:
// Post:
template <class ValType>
bool operator>=(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return !(lhs < rhs);
}

#endif //KS_ARRAY_FILE
