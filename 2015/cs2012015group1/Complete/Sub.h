#ifndef _SUBSTITUTION_H_
#define _SUBSTITUTION_H_

//Takes a char string and will subsitute the letter with a value from the given key
char * encryptSub(char * plainText, char * key);

//Takes the given cipher and uses that to find the correct letter to subsitute back
char * decryptSub(char * cipher, char * key);

//Returns which letter of the alphabet the letter is. 
int getPlace(char letter);

//Returns which letter of the KEY the letter is. 
int getKeyPlace(char letter, char * key);

//returns the size of the array
int getStringSize(char * string);

//returns the size of an array
int getSizeSub(char * string);

#endif