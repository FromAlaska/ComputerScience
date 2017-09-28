//Jim Samson
//CS201

#ifndef CRYPTO_H_INCLUDED
#define CRYPTO_H_INCLUDED
#include <cstring>

//This is for encrypting
char * encryptCaesar(char encryptCaesar[], int key)
{
	const int LENGTH = strlen(encryptCaesar);
	char *ptr = new char[LENGTH];

	//This copies the array of characters
	for(int i = 0; i < LENGTH; i++)
	{
		ptr[i] = encryptCaesar[i];
	}

	//This is for changing the pointer
	for(int j = 0; j < LENGTH; j++)
	{
		//If character has a blankspace in it, leave it be.
		if(ptr[j] == ' ')
		{
			continue;
		}

		//If character pointer is greater than 'Z', subtract 26
		if(ptr[j] + key > 'Z')
		{
			ptr[j] -= 26;
		}

		if(ptr[j] < 'A')
		{
			ptr[j] += key;
		}

		//This is if each of the two tests fail
		else
		{
			ptr[j] += (char)key;
		}
	}
	return ptr;
	delete[] ptr;
}

//This is for decrypting
char * decryptCaesar(char decryptCaesar[], int key)
{
	const int LENGTH = strlen(decryptCaesar);
	char *ptr = new char[LENGTH];

	//This is for copying the array
	for(int i = 0; i < LENGTH; i++)
	{
		ptr[i] = decryptCaesar[i];
	}

	//This is for decrypting the pointer
	for(int j = 0; j < LENGTH; j++)
	{
		//If character has a blankspace in it, leave it be.
		if(ptr[j] == ' ')
		{
			continue;
		}

		//If character pointer is less than 'A', add 26
		if(ptr[j] - key < 'A')
		{
			ptr[j] += 26;
		}

		//If character pointer is greater than Z, then subtract it with key
		if(ptr[j] > 'Z')
		{
			ptr[j] -= key;
		}

		//This is if each of the two tests fail
		else
		{
			ptr[j] -= (char)key;
		}
	}
	return ptr;
	delete[] ptr;
}
#endif