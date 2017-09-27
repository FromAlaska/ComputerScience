#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <string>
#include <sstream>

using std::ostream;
using std::string;
using std::ostringstream;

class MyString
{
  friend ostream & operator<<(ostream &, const MyString &);
  friend MyString operator+(const MyString &, const MyString &);
  friend MyString operator-(const MyString &, const MyString &);
  friend bool operator == (const MyString &, const MyString &);
  friend bool operator != (const MyString &, const MyString &);

public:
  MyString()
  {
    totalCharacters_ = new string;
    totalCharacters_ = 0;
    size_ = 0;
  }
  MyString(string characters, int size)
  {
    totalCharacters_ = new string;
    totalCharacters_ = &characters;
    size_ = size;
  }
  MyString(const MyString &rhs)
  {
    size_ = rhs.size_;
    totalCharacters_ = rhs.totalCharacters_;
  }
  ~MyString()
  {
    size_--;
    delete totalCharacters_;
  }

  string toString() const
  {
    ostringstream ss;
    ss << size_;
    ss << totalCharacters_;
    return ss.str();
  }
  int size()
  {
    return size_;
  }
private:
  string *totalCharacters_;
  int size_;
};

bool operator == (const MyString &, const MyString &);
bool operator != (const MyString &, const MyString &);

#endif
