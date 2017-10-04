// da3.h  INCOMPLETE
// Glenn G. Chappell
// 24 Sep 2017
//
// For CS 311 Fall 2017
// Header for Assignment 3 Functions

#ifndef FILE_DA3_H_INCLUDED
#define FILE_DA3_H_INCLUDED

#include <cstddef>
using std::size_t;
#include <functional>
using std::function;
#include <algorithm>
#include <stdexcept>
#include <iostream>

// **************************************************************** // *
// Begin DO-NOT-CHANGE section                                      // *
// Do not alter the lines below                                     // *
// **************************************************************** // *
                                                                    // *
                                                                    // *
// struct LLNode                                                    // *
// Linked List node, with client-specified value type               // *
// Intended Invariants (breakable, as data members are public):     // *
//     Either _next is nullptr, or _next points to an LLNode,       // *
//      allocated with new, owned by *this.                         // *
// Requirements on Types:                                           // *
//     ValueType must have a copy ctor and a dctor.                 // *
template <typename ValueType>                                       // *
struct LLNode {                                                     // *
    ValueType _data;  // Data for this node                         // *
    LLNode *  _next;   // Ptr to next node, or nullptr if none      // *
                                                                    // *
    // The following simplify creation & destruction                // *
                                                                    // *
    // 1- & 2-param ctor                                            // *
    // Pre:                                                         // *
    //     theNext, if passed, is either nullptr, or else it        // *
    //      points to an LLNode, allocated with new, with           // *
    //      ownership transferred to *this.                         // *
    // Post:                                                        // *
    //     _data == data.                                           // *
    //     If _next passed, then _next == next. Otherwise, _next    // *
    //      is nullptr.                                             // *
    explicit LLNode(const ValueType & data,                         // *
                    LLNode * next = nullptr)                        // *
        :_data(data),                                               // *
         _next(next)                                                // *
    {}                                                              // *
                                                                    // *
    // dctor                                                        // *
    // Pre: None.                                                   // *
    // Post: None. (_next delete'd)                                 // *
    ~LLNode()                                                       // *
    { delete _next; }                                               // *
};  // End struct LLNode                                            // *
                                                                    // *
                                                                    // *
// **************************************************************** // *
// End DO-NOT-CHANGE section                                        // *
// Do not alter the lines above                                     // *
// **************************************************************** // *

// lookUp()
// lookUp is a null-terminated Linked List and an integer index. LookUp functions
// similarly like to an array bracket operator, returning the item correspoinding
// to the given index.
// Pre: Index must not be negative, head must have values
// Post:
//      Checks if index <= 0, head != NULL, and index >= counter.
//      Otherwise, this function throws if any of the checks fail.
//      Counter checks the next linked list in the array.
template <typename ValueType>
ValueType lookUp(const LLNode<ValueType> * head,
                 size_t index)
{
    size_t counter = 0;
    while(head != NULL)
    {
      if(counter == index)
      {
        return head -> _data;
      }
      head = head -> _next;
      ++counter;
    }
    if(index <= 0 || head == NULL || index>=counter)
    {
      throw std::out_of_range("Index is negative, an empty list, or greater than your counter.");
    }
    return head -> _data;
}

// callBetween()
// This function calls functions of the functions that were passed by reference.
// To call a function, use start() within the scope of this function.
// Pre: none.
// Post:
//      The start() function is checked by the outer try/catch exceptions.
//      If start() throws, then all the other functions must not be called.
//      If middle() throws, the finish() function cleans up start().
void callBetween(const function<void()> & start,
                 const function<void()> & middle,
                 const function<void()> & finish);

// uniqueCount()
// uniqueCount is a function that checks the elements and the array, then returns
// the unique amount of elements in the array.
// Pre: none.
// Post:
//      First, the std::sort() algorithm sorts the elements in the list.
//      Second, a pointer is allocated and a std::unique() is called to remove equivelant elements.
//      Third, using the pointer, a while loop is constructed and compared to the first element.
//      Inside the while loop, an iterator increments while the RaIter first iterator increments.
//      uniqueCount returns the total amount that has been incremented.
template <typename RAIter>
size_t uniqueCount(RAIter first,
                   RAIter last)
{
  std::sort(first,last);
  auto uniqueElements = std::unique(first,last);
  int totalAmount = 0;

  while(uniqueElements != first)
  {
    ++first;
    ++totalAmount;
  }
  return totalAmount;
}

// gcd();
// The gcd() function returns the greatest common denominator of the values inside gcd(a,b).
// Unfortunately, the function does not check if the values are negative, but it does check if
// a is equal to zero.
// Pre: a != 0, a & b !< 0
// Post:
//      First, it checks if a is equal to zero, if so, it returns b.
//      Second, if a > b, it returns recursive function gcd(a,b) = gcd(b,a).
//      Third, if the first two checks passed, then the function returns the recursive
//      function gcd(b%a,a).
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DA3_H_INCLUDED
