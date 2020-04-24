/*  

    Copyright 2019-20 by

    University of Alaska Anchorage, College of Engineering.

    All rights reserved.

    Contributors:  Jim Samson and
		   Christoph Lauter
    
*/

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Prime numbers
#define Q            ((uint64_t) (18446744073709551359ull))    /* 2^64 - 257 is prime */
#define TWO64_MOD_Q  ((uint64_t) (257))                        /* 2^64 mod Q */
#define TWO9_MOD_Q   ((uint64_t) (512))                        /* 2^9 mod Q */

// Bernstein's hash 
#define INITIAL_VALUE ((uint64_t) (5381))

// length(*str)
// Iterates through a list of strings. Returns the length of the string of characters.
static size_t length(const char *str) {
  size_t l;
  const char *curr;

  for (curr=str,l=(size_t)0; *curr!='\0'; curr++,l++);
  return l;
}

// getBase()
// Magic? But the magic should return the base of the number.
// Don't typically need to use.
static inline uint64_t getBase() {
  unsigned char m;
  uint64_t base;

  m = (unsigned char) 0;
  m--;
  base = (uint64_t) m;
  base++;
  return base;
}

// addModulo(int a, int b)
// Adds two 128-bit integers together into a temporary variable t. 
// Converts the 128-bit integers into 64-bit integers and adds it to variable s.
// Coverts variable t and bit shifts the integer by 64 bits.
// Returns ((s mod Q) + (c times TWO64_MOD_Q) mod Q), which happens to be the modulus of a, b.
static inline uint64_t addModulo(uint64_t a, uint64_t b) {
  __uint128_t t;
  uint64_t c, s;

  t = ((__uint128_t) a) + ((__uint128_t) b);
  s = (uint64_t) t;
  c = (uint64_t) (t >> 64);
  return (((s % Q) + (c * TWO64_MOD_Q)) % Q);
}

// addModuloChar(int a, int b)
static inline uint64_t addModuloChar(uint64_t a, unsigned char b) {
  if (getBase() > TWO64_MOD_Q) {
    return addModulo(a, (uint64_t) b);
  }

  return (((a % Q) + ((uint64_t) b)) % Q);
}

// subModulo(int a, int b)
static inline uint64_t subModulo(uint64_t a, uint64_t b) {
  return addModulo(a, Q - (b % Q));
}

// mulModulo(int a, int b)
// Does some magic. Multiplies two hashes together. No need to think about it too much.
static inline uint64_t mulModulo(uint64_t a, uint64_t b) {
  __uint128_t t, r;
  uint64_t h, l, s, c;

  t = ((__uint128_t) a) * ((__uint128_t) b);
  l = (uint64_t) t;
  h = (uint64_t) (t >> 64);
  r = (((__uint128_t) h) * ((__uint128_t) TWO64_MOD_Q)) + ((__uint128_t) l);
  s = (uint64_t) r;
  c = (uint64_t) (r >> 64);
  return (((s % Q) + (c * TWO64_MOD_Q)) % Q);
}

// mulModuloBase()
// Multiples the base with the hash.
static inline uint64_t mulModuloBase(uint64_t a) {
  uint64_t base;
  __uint128_t r;
  uint64_t h, l, s, c;

  base = getBase();
  if (base != (1 << 8)) {
    return mulModulo(a, base);
  }

  l = a << 8;
  h = a >> 56;
  r = (((__uint128_t) h) * ((__uint128_t) TWO64_MOD_Q)) + ((__uint128_t) l);
  s = (uint64_t) r;
  c = (uint64_t) (r >> 64);
  return (((s % Q) + (c * TWO64_MOD_Q)) % Q);
}

// mulModuloChar()
// 
static inline uint64_t mulModuloChar(uint64_t a, unsigned char b) {
  return mulModulo(a, ((uint64_t) b));
}

// hash(char *, size_t)
// Computes the hash of the given text and size.
static inline uint64_t hashHaystack(const unsigned char *text, size_t m) {
	uint64_t i;
	uint64_t hash = INITIAL_VALUE; // Initial value = Bernstein's hash function
	for(i = 0; i < m-1; i++) {
		printf("value: %s \n", &text[i]);
		hash = ((hash * Q) + (uint64_t) &text[i]) % Q;
	} 
	return hash;
}

// updateHash(int, int, int)
// updateHash(current hash, &haystack[i], &haystack[i+m])
// updates the next hash.
static inline uint64_t updateHash(uint64_t hash, uint64_t b_i, uint64_t b_i_plus_m) {
	return addModulo(b_i_plus_m, mulModuloBase(subModulo(hash,mulModulo(b_i,mulModuloBase(b_i_plus_m))))) % Q;
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

static inline uint64_t hashfdsa(char *str) {
	uint64_t sum = 0;
	while(*str != '\0') {
		sum += (int) *str++;
	}
	return sum % Q;
}

static inline uint64_t hash(char *str, size_t m) {
	uint64_t sum = 0;
	for(int i = 0; i < m; ++i) {
		sum = (TWO64_MOD_Q*sum + str[i])%Q;
	}
	return sum;
}

static void matchStringsDoWork(char *res,
			       const unsigned char *haystack,
			       size_t n,
			       const unsigned char *needle,
			       size_t m) {
  if(m>n) return;
  
  int i;
  uint64_t haystack_hash = 0;
  uint64_t needle_hash = 0;
  
  // Compute the first hash for the needle
  needle_hash = hash(needle, m);
  printf("Computed hash for needle: %ld [%ld]\n", needle_hash, m);
  haystack_hash = hash(haystack, m);
  printf("Computed hash for haystack: %ld [%ld]\n", haystack, n);
  
  for(i = 0; i < n-m; ++i) {
  	if(haystack_hash == needle_hash) {
  		res[i] = (char) compareFirst(&haystack[i], needle, m);
  	}
  	haystack_hash = updateHash(haystack_hash, haystack[i], haystack[i + m]);
  }
}

void matchStrings(char *res, const char *haystack, const char *needle) {
  matchStringsDoWork(res,
		     (const unsigned char *) haystack, length(haystack),
		     (const unsigned char *) needle, length(needle));
}

