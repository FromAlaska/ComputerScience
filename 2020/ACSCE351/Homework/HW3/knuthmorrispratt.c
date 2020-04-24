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

// Returns the length of the string
// Stolen from Dr. Lauter in rabinkarp.c
static size_t length(const char *str) {
  size_t l;
  const char *curr;

  for (curr=str,l=(size_t)0; *curr!='\0'; curr++,l++);
  return l;
}

static inline int compareFirst(const unsigned char *str1, 
								const unsigned char *str2,
								size_t n) {
	size_t i;
	for(i = 0; i < n; ++i) {
		if(str1[i] != str2[i]) return 0;
	}
	return 1;
}

// makeTable
static inline uint64_t* makeTable(const unsigned char *str, size_t m) {
	
	uint64_t traceback = 0;
	uint64_t table[m];
	table[0] = -1;
	
	for(int i = 0; i <= m; ++i) {
		if(str[i] == str[traceback]) {
			table[i] = table[traceback];
		}
		else {
			table[i] = traceback;
			traceback = table[traceback];
			while((traceback >= 0 && str[i]) != str[traceback]) {
				traceback = table[traceback];
			}
			table[i+1] = traceback; 
		}
	}
	return table;
}

static inline void matchStringsDoSomething(char *res,
										const unsigned char *haystack,
										size_t n,
										const unsigned char *needle,
										size_t m) {
	uint64_t * table = makeTable(needle,m);
	int haystackIndex, needleIndex = 0;
	while(haystackIndex < m) {
		if(needleIndex == needle[needleIndex]) {
			haystackIndex += 1;
			needleIndex += 1;
			if(needleIndex == m) {
				res[haystackIndex - needleIndex] = (char) 1;
				needleIndex = table[needleIndex];
			}			
		}
		else {
			needleIndex = table[needleIndex];
			if(needleIndex == -1) {
				haystackIndex += 1;
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
