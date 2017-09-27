/*
Jim Samson
CS202
January 24, 2017
*/

//This is lab one. It is reflected on what I have learned today.
#include <iostream>
#include <random>

using std::cout;
using std::endl;

int main()
{
  // I have made an array that holds 100 objects and made a pointer named iPtr
   int numbers[100];
   int *iPtr;

   // Then I have copied the address of numbers and allocated 28 to slot 0
   iPtr = numbers;
   iPtr[0] = 28;

   // The first cout has printed the address of numbers[]
   // The second cout has printed 28 in the first slot of numbers[0]
   cout << iPtr << endl;
   cout << iPtr[0] << endl;

   // This didn't work the first time. I must have done something wrong.
   // Checking google, fixing this issue.
   // I forgot how to use rand. I've used rand(10). Code is now working.
   // This program was used to change the pointer of numbers[n] using random
   // Generated numbers. It works, but it's not changing everytime it is being
   // Called.
   for(int totalInt = 0; totalInt < 100; ++totalInt)
   {
     iPtr[totalInt] = rand() % 100;
   }
   //This was supposed to change numbers[10] each time the for-loop is being called.
   cout << numbers[10] << endl;

   return 0;
}
