// ksarray.h
// Jim Samson
// September 18, 2017
//
// For CS311 2017 Fall
// Header for ksarray.cpp

#ifndef KS_ARRAY_FILE
#define KS_ARRAY_FILE

//*****************************
// Class array
//*****************************

// Class KSArray
//
// Invariants:
//            f
template <typename ValType>
class KSArray
{
  // Operator ==
  // Compares object A and B and returns a boolean.
  // Two KSArray objects with the same value type are equal
  // if they have the same size and their corresponding items are all equal.
  // Pre: Two KSArray objects with different value types cannot be compared.
  // Post:
  friend bool operator==(const KSArray &, const KSArray &);

private:

  // Default ctor
  // Creates an array of a size 10.
  // Pre: None.
  // Post:
  KSArray(): _arraySize(10)
  {}

  // Constructor
  // Creates an object using value from the parameter.
  // Pre: Value CANNOT be negative.
  // Post:
  KSArray(ValType);

  // Destructor
  // This frees any dynamically allocated memory.
  // Pre:
  // Post:
  ~KSArray();

  // Copy Constructor
  // Copies all of the data from A to B.
  // Pre:
  // Post:
  KSArray(const KSArray &);

  // size
  // Returns the number of items in the array.
  // Pre:
  // Post:
  size();

  // begin
  // Returns the address of item 0 in the array (think “iterator”).
  // Pre:
  // Post:
  begin();

  // end
  // Returns the address of the item one-past the end of the array (think “iterator”).
  // Pre:
  // Post:
  end();

  // Big Five, well at least three of the big five
  KSArray(KSArray &&)=delete;
  KSArray & operator=(const KSArray &)=delete;
  KSArray & operator=(KSArray &&)=delete;

public:
  ValType _arraySize;
}

//************************************************************
// Class KSArray - Declarations of associated global operators
//************************************************************

// Operator !=
// Compares objects A and B, then returns a boolean. Using Canonical code.
// Pre: Two KSArray objects with different value types cannot be compared.
// Post:
bool operator!=(const KSArray &, const KSArray &);

// Operator >
// Compares object A and B and returns a boolean
// Pre:
// Post:
bool operator>(const KSArray &, const KSArray &);

// Operator <=
// Compares object A and B and returns a boolean
// Pre:
// Post:
bool operator<=(const KSArray &, const KSArray &);

// Operator >=
// Compares object A and B and returns a boolean
// Pre:
// Post:
bool operator>=(const KSArray &, const KSArray &);

// Operator <
// Compares object A and B and returns a boolean.
// Pre:
// Post:
bool operator<(const KSArray &, const KSArray &);

#endif //KS_ARRAY_FILE
