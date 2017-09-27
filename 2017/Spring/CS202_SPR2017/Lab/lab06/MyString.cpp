#include "MyString.h"

ostream & operator<<(ostream &os, const MyString &rhs)
{
  return os << rhs.toString();
}

MyString::MyString operator+(const MyString &lhs, const MyString &rhs)
{
  return lhs.totalCharacters_ + rhs.totalCharacters_;
}

MyString::MyString operator-(const MyString &lhs, const MyString &rhs)
{
  return lhs.totalCharacters_ + rhs.totalCharacters_;
}

bool operator == (const MyString &lhs, const MyString &rhs)
{
  return lhs.totalCharacters_ == rhs.totalCharacters_;
}

bool operator != (const MyString &lhs, const MyString &rhs)
{
  return !(lhs.totalCharacters_ == rhs.totalCharacters_);
}
