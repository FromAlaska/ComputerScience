//Jim Samson
//Computer Science
//February 9, 2017
//This program is for HW1. I added comments everywhere
///Users/jimsamson/2017Spring/HW1DataFiles

#include "hw1.h"

int getIdFromFile(string nameOfFile, istream &usernameId, ostream &outputId)
{

	string usernameFromIStream;

	//This program opens and checks each input that the user gives me
	while(usernameId >> usernameFromIStream)
	{
		//Each time this loop iterates, it opens the file again and checks each time
		ifstream inputFile(nameOfFile.c_str());

		//This checks if there was an error opening the file
		if(!inputFile)
			return -1;

		bool foundName = false; //Important! This will send an "error" if it hasn't been found

		//This will check if there was no end of file
		while(!inputFile.eof())
		{
			//This takes in input from the file
			string usernameFromFile;
			int idFromFile;
			inputFile >> usernameFromFile >> idFromFile;

			//This checks the string of the input from the file and the istream input
			if(usernameFromFile == usernameFromIStream)
			{
				outputId << idFromFile << endl;
				foundName = true;
			}
		}
			//IMPORTANT! This will send the user an "error" if no such username was found
			if(!foundName)
			{
				outputId << "error" << endl;
			}
		}
	return 0; //Return true if the file was good
}

// In this exercise, you will write a function to read a binary file in "random access" mode.
// Your function will open a file that contains a list of 4-byte binary integers.
// You should read the first integer to find the index of the next integer, print this index to an ostream, and repeat until you hit a negative integer.

void numberChase(string nameOfFile, ostream &outputFile)
{
	ifstream inputFile(nameOfFile.c_str(), ios::binary); //Opens the file

	int temp = 0;
	vector<int> arrayFile;

	//This will read the file and put variables into a vector
	while(inputFile.read(reinterpret_cast<char *>(&temp), 4))
	{
		arrayFile.push_back(temp);
	}

	temp = 0;
	outputFile << arrayFile[temp] << endl; //This will open the first variable of the array and sends it to the user

	//This will check the array x amount of times
	for(int total = 0; total < arrayFile.size(); ++total)
	{
		//This will stop the loop if the number is negative
		if(arrayFile[temp] < 0)
		{
			break;
		}
		//If there is no negative number, go to the next variable input and send it back to the user
		else
		{
			temp = arrayFile[temp];
			outputFile << arrayFile[temp] << endl;
		}
	}
}
