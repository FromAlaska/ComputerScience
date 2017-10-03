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


template <typename ValueType>
ValueType lookUp(const LLNode<ValueType> * head,
                 size_t index)
{
    return ValueType();  // Dummy return, so that it compiles
                         // Elminate this return statement!
    // TODO: Write this!!!
}


// Implementation in source file
void callBetween(const function<void()> & start,
                 const function<void()> & middle,
                 const function<void()> & finish);


template <typename RAIter>
size_t uniqueCount(RAIter first,
                   RAIter last)
{
    //return size_t(42);  // Dummy return, so that it compiles
                        // Elminate this return statement!
    // TODO: Write this!!!

    auto ptrElement = first+1;
    size_t totalUniqueElements=0;
    bool foundAnother;

    while(first != last)
    {
      foundAnother = false;
      while(ptrElement != last)
      {
        if(*ptrElement == *first)
        {
          ptrElement++;
          foundAnother = true;
          break;
        }
      }
      first++;
      if(!foundAnother)
        ++totalUniqueElements;
    }
    return totalUniqueElements;
}


// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DA3_H_INCLUDED
