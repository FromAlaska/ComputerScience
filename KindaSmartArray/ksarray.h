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
  friend bool operator==(const KSArray<ValType> &, const KSArray<ValType> &);

public:

  // Size Types & Value types
  using size_type = std::size_t;
  using value_type = ValType;

  // Default ctor
  // Creates an array of a size 10.
  // Pre: None.
  // Post:
  KSArray(): _arraySize(10), _arrayPtr(new(ValType))
  {}

  // Constructor
  // Creates an object using value from the parameter.
  // Pre: Value CANNOT be negative.
  // Post:
  KSArray(ValType arraySize): _arraySize(arraySize)
  {}

  // Destructor
  // This frees any dynamically allocated memory.
  // Pre:
  // Post:
  ~KSArray();

  // Copy Constructor
  // Copies all of the data from A to B.
  // Pre:
  // Post:
  KSArray(const KSArray<ValType> &);

  // size
  // Returns the number of items in the array.
  // Pre:
  // Post:
  ValType size() const;

  // begin (non-const)
  // Returns the address of item 0 in the array (think “iterator”).
  // Pre:
  // Post:
  ValType * begin();

  // begin (const)
  // Returns the address of item 0 in the array (think “iterator”).
  // Pre:
  // Post:
  ValType * begin() const;

  // end (non-const)
  // Returns the address of the item one-past the end of the array (think “iterator”).
  // Pre:
  // Post:
  ValType * end();

  // end (const)
  // Returns the address of the item one-past the end of the array (think “iterator”).
  // Pre:
  // Post:
  ValType * end() const;

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
bool operator!=(const KSArray<ValType> &, const KSArray<ValType> &);

// Operator >
// Compares object A and B and returns a boolean
// Pre:
// Post:
template <class ValType>
bool operator>(const KSArray<ValType> &, const KSArray<ValType> &);

// Operator <=
// Compares object A and B and returns a boolean
// Pre:
// Post:
template <class ValType>
bool operator<=(const KSArray<ValType> &, const KSArray<ValType> &);

// Operator >=
// Compares object A and B and returns a boolean
// Pre:
// Post:
template <class ValType>
bool operator>=(const KSArray<ValType> &, const KSArray<ValType> &);

// Operator <
// Compares object A and B and returns a boolean.
// Pre:
// Post:
template <class ValType>
bool operator<(const KSArray<ValType> &, const KSArray<ValType> &);

#endif //KS_ARRAY_FILE
