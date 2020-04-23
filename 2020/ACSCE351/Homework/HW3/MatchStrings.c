/*  

    Copyright 2019-20 by

    University of Alaska Anchorage, College of Engineering.

    All rights reserved.

    Contributors:  Jim Samson and
    			   Christoph Lauter
    
	MatchStrings Function
	1. Implement naive multi-occurrence string search: given a string, in the form of a data-structure that
		allows each of the characters of the string to be accessed in O(1), called the haystack, and another
		string called the needle, the function computes all indices i such that the needle appears as a substring
		of the haystack, starting at the i-th character of the haystack. Return the set of such indices i in the
		form of an array of booleans.

		In C, your function could have the following signature:
			void matchStrings(char *res,
			const char *haystack,
			const char *needle);
    
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

// compareFirst()
// Compares two strings together to get the result.
static inline int compareFirst(const unsigned char *str1, 
								const unsigned char *str2,
								size_t n) {
	size_t i;
	for(i = 0; i < n; ++i) {
		if(str1[i] != str2[i]) return 0;
	}
	return 1;
}

// Similar to what was shown in class
// Looks through the indices i and makes a list of "booleans".
/*
	Best case:
				Haystack: aab
				Needle: aab
	Worst case:
				Haystack: aaaaaaaaaaaaaa
				Needle: a
*/
static inline void matchStringsBoolean(char *res,
										const unsigned char *haystack,
										size_t n,
										const unsigned char *needle,
										size_t m) {
	if(m > n) return;
	
	// Search through the haystack
	for(int iterX = 0; iterX <= n-m; ++iterX) {
		int iterY;
		
		// Compare the haystack at iterX with the pattern
		for(iterY = 0; iterY < m; ++iterY) {
			// Returns false if the two strings don't equal each other;
			if(haystack[iterX + iterY] != needle[iterY]) {res[iterX] = (char) 0; break;} 
		}
		// Returns true if the two strings equal each other.
		if(iterY == m) {
			res[iterX] = (char) 1;
		}
	}
}

// MatchStrings()
// Uses almost the same method that was shown as an example in class.
void matchStrings(char *res, const char *haystack, const char *needle) {
	matchStringsBoolean(res,
							(const unsigned char *) haystack, 
							length(haystack), 
							(const unsigned char *) needle, 
							length(needle)
							);
}
