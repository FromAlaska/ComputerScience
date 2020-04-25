/*  

    Copyright 2019-20 by

    University of Alaska Anchorage, College of Engineering.

    All rights reserved.

    Contributors:  Jim Samson and
    			   Christoph Lauter
    
	MatchStrings Function
	3. Implement Knuth-Morris-Pratt multi-occurrence string search. This function does the same 		thing as the naive multi-occurrence string search specified above but uses the Knuth-Morris-Pratt implicit finite-automaton technique described in the textbook.
    
*/

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define TWO9_MOD_Q   ((uint64_t) (512))                        /* 2^9 mod Q */

// Returns the length of the string
// Stolen from Dr. Lauter in rabinkarp.c
static size_t length(const char *str) {
  size_t l;
  const char *curr;

  for (curr=str,l=(size_t)0; *curr!='\0'; curr++,l++);
  return l;
}

// AllocateTable
static inline void AllocateTable(uint64_t *table, 
										const unsigned char *needle, 
										size_t m) {
	int len = 0; 
	table[0] = 0;

	int index = 1; 
	while (index < m) { 
		if (needle[index] == needle[len]) { 
			len++; 
			table[index] = len; 
			index++; 
		} 
		else { 
			if (len != 0) { 
				len = table[len - 1]; 
			} 
			else { 
				table[index] = 0; 
				index++; 
			} 
		} 
	} 
}

static inline void matchStringsDoSomething(char *res,
										const unsigned char *haystack,
										size_t n,
										const unsigned char *needle,
										size_t m) {
	int table[m]; 
	AllocateTable(table, needle, m); 

	int needleIndex = 0;
	int haystackIndex = 0;
	while (needleIndex < n) { 
		if (needle[haystackIndex] == haystack[needleIndex]) { 
			haystackIndex++; 
			needleIndex++; 
		} 

		if (haystackIndex == m) {
			res[needleIndex-haystackIndex] = (char) 1; 
			haystackIndex = table[haystackIndex - 1]; 
		}

		else if (needleIndex < n && needle[haystackIndex] != haystack[needleIndex]) { 
			res[needleIndex-haystackIndex] = (char) 0;
			if (haystackIndex != 0) {
				haystackIndex = table[haystackIndex - 1];
			} 
			else {
				needleIndex += 1; 
			}
		} 
	} 
}

void matchStrings(char *res, const char *haystack, const char *needle) {
	matchStringsDoSomething(res,
							(const unsigned char *) haystack, 
							length(haystack), 
							(const unsigned char *) needle, 
							length(needle)
							);
}							
