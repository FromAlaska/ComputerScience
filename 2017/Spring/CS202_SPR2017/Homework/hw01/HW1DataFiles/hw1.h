#ifndef HW1_H
#define HW1_H

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <ostream>
#include <vector>

using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::ifstream;
using std::string;
using std::istream;
using std::ostream;
using std::ios;
using std::vector;

int getIdFromFile(string nameOfFile, istream &iFile, ostream &oFile);
void numberChase(string nameOfFile, ostream &outputFile);

#endif
