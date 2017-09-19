#include "ksarray.h"

// KSArray::KSArray()
// See header for documentation.
KSArray::KSArray(ValType typeArray)
{
  _arraySize = typeArray;
}

// KSArray::~KSArray()
// See header for documentation.
KSArray::~KSArray()
{}

// KSArray::KSArray(const KSArray &)
// See header for documentation.
KSArray::KSArray(const KSArray & )
{}

// KSArray::size()
// See header for documentation.
KSArray::size()
{}

// KSArray::begin()
// See header for documentation.
KSArray::begin()
{}

// KSArray::end()
// See header for documentation.
KSArray::end()
{}

// operator==
// See header for documentation.
bool operator==(const KSArray & lhs, const KSArray & rhs)
{
  return (lhs._arraySize == rhs._arraySize);
}

// operator !=
// See header for documentation.
bool operator!=(const KSArray & lhs, const KSArray & rhs)
{
  return !(lhs == rhs);
}

// operator <
// See header for documentation.
bool operator<(const KSArray & lhs, const KSArray & rhs)
{
  return (lhs._arraySize < rhs._arraySize);
}

// operator >
// See header for documentation.
bool operator>(const KSArray & lhs, const KSArray & rhs)
{
  return (rhs < lhs);
}

// operator <=
// See header for documentation.
bool operator<=(const KSArray & lhs, const KSArray & rhs)
{
  return !(rhs < lhs);
}

// operator >=
// See header for documentation.
bool operator>=(const KSArray & lhs, const KSArray & rhs)
{
  return !(lhs < rhs);
}
