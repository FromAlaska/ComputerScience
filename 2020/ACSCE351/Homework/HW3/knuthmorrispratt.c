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
static inline void AllocateTable(uint64_t table[], 
										const unsigned char *str, 
										size_t m) {
	
	uint64_t traceback = 0;
	table[0] = -1;
	int pos = 0;
	
	while(pos < m) {
		printf("position = %d\n", pos);
		printf("str_pos = %d\n", str[pos]);
		printf("str_traceback = %d\n", str[traceback]);
		if(str[pos] == str[traceback]) {
			printf("Table. They are equal\n");
			table[pos] = table[traceback];
		}
		else {
			printf("Table. They aren't equal\n");
			table[pos] = traceback;
			printf("table traceBack = [%ld]\n", table[traceback]);
			printf("TRACEBACK (1) = %ld\n", traceback);
			traceback = table[traceback];
			printf("TRACEBACK (2) = %ld\n", traceback);
			while((traceback >= 0 && str[pos]) != str[traceback]) {
				printf("TRACEBACK (3) = %ld\n", traceback);
				printf("table traceBack = [%ld]\n", table[traceback]);
				traceback = table[traceback];
			}
		}
		printf("Went outside the loops\n\n");
		pos += 1;
		traceback += 1;
	}
	table[pos] = traceback;
	printf("################################################################## DONE ###########################################################\n");
}


static inline void matchStringsDoSomething(char *res,
										const unsigned char *haystack,
										size_t n,
										const unsigned char *needle,
										size_t m) {
	uint64_t table [TWO9_MOD_Q];
	AllocateTable(table,needle,n);
	int haystackIndex = 0;
	int needleIndex = 0;
	int numberOfPositions = 0;
	while(haystackIndex < n) {
		//printf("haystackIndex = [%d]\n",haystackIndex);
		//printf("needleIndex = [%d]\n",needleIndex);
		if(haystack[haystackIndex] == needle[needleIndex]) {
			haystackIndex += 1;
			needleIndex += 1;
			if(needleIndex == m) {
				res[numberOfPositions] = (char) 1;
				printf("res[%d] = %d\n", numberOfPositions, res[numberOfPositions]);
				numberOfPositions += 1;
				//printf("needle position = %ld \n", (uint64_t) table[needleIndex]);
				needleIndex = table[needleIndex];
				//printf("true: [%d]\n",res[numberOfPositions]);
			}
		}
		else { 
			if(needleIndex != m) {
				res[numberOfPositions] = (char) 0;
				printf("res[%d] = %d\n", numberOfPositions, res[numberOfPositions]);
			}
			needleIndex = table[needleIndex];
			if(needleIndex < 0) {
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
