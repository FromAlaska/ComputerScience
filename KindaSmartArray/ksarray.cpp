// ksarray.cpp
// Jim Samson
// September 18, 2017
//
// For CS311 2017 Fall
// Source File for Class KSArray

#include "ksarray.h"

// Destructor
// KSArray::~KSArray()
// See header for documentation.
template <class ValType>
KSArray<ValType>::~KSArray()
{
  delete *_arrayPtr;
}

// Copy Constructor
// KSArray::KSArray(const KSArray &)
// See header for documentation.
template <class ValType>
KSArray<ValType>::KSArray(const KSArray<ValType> & other)
{
  
}

// Returns number of items in the array.
// KSArray::size()
// See header for documentation.
template <class ValType>
ValType KSArray<ValType>::size() const
{
  return _arraySize;
}

// Returns the address of the array.
// KSArray::begin()
// See header for documentation.
template <class ValType>
ValType * KSArray<ValType>::begin()
{
  return _arrayPtr[0];
}

// Returns the address of the array.
// KSArray::begin()
// See header for documentation.
template <class ValType>
ValType * KSArray<ValType>::begin() const
{
  return _arrayPtr[0];
}

// KSArray::end()
// See header for documentation.
template <class ValType>
ValType * KSArray<ValType>::end()
{
  return *_arrayPtr[_arraySize];
}

// KSArray::end()
// See header for documentation.
template <class ValType>
ValType * KSArray<ValType>::end() const
{
  return *_arrayPtr[_arraySize];
}

// operator==
// See header for documentation.
template <class ValType>
bool operator==(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return (lhs._arraySize == rhs._arraySize);
}

// operator !=
// See header for documentation.
template <class ValType>
bool operator!=(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return !(lhs == rhs);
}

// operator <
// See header for documentation.
template <class ValType>
bool operator<(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return (lhs._arraySize < rhs._arraySize);
}

// operator >
// See header for documentation.
template <class ValType>
bool operator>(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return (rhs < lhs);
}

// operator <=
// See header for documentation.
template <class ValType>
bool operator<=(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return !(rhs < lhs);
}

// operator >=
// See header for documentation.
template <class ValType>
bool operator>=(const KSArray<ValType> & lhs, const KSArray<ValType> & rhs)
{
  return !(lhs < rhs);
}
