//Jim Samson
//CS201
//This is caesar ciphering, it is an amazing piece of artwork that needs some changes.
//Update version 1.2: I need to add Cstrings to my project so that it cannot change whitespaces.

#ifndef CRYPTO_H_INCLUDED
#define CRYPTO_H_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;

//Functions for encrypting and decrypting
char * encryptCaesar(char &, int key);
char * decryptCaesar(char &, int key);

//This is for encrypting
char * encryptCaesar(char encryptCaesar[], int key)
{
	const int SIZE = 19;
	char *ptr = new char[SIZE];

	for(int i = 0; i < SIZE; i++)
	{
		ptr[i] = encryptCaesar[i];
	}

	for(int j = 0; j < SIZE; j++)
	{
		ptr[j] += (char)key;
	}

	return ptr;
	delete[] ptr;
}

//This is for decrypting
char * decryptCaesar(char decryptCaesar[], int key)
{
	const int SIZE = 19; 
	char *ptr = new char[SIZE];

	for(int i = 0; i < SIZE; i++)
	{
		ptr[i] = decryptCaesar[i];
	}

	for(int j = 0; j < SIZE; j++)
	{
		ptr[j] -= (char)key;
	}
	return ptr;
	delete[] ptr;
}
#endif