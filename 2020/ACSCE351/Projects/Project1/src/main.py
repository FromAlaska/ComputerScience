#!/usr/bin/env python3

import sys

buffArray = []
stackArray = []
operatorIsTrue = False
ifOperand=False
ifParanthesis=False

#Evaluate things
def evaluateFunction(operand_2,operand_1,element):
    if(element == "+"):
        return int(operand_2) + int(operand_1)
    if(element == "-"):
        return int(operand_2) - int(operand_1)
    if(element == "*"):
        return int(operand_2) * int(operand_1)

#Basic Parsing Algorithm
def parse(inputString):
    buffArray = inputString #Make a copy of the stuff
    print("Input: " + buffArray)

    for indexElement in buffArray:
        #buffArray.append(indexElement)
        if(indexElement == "("):
            if(indexElement is "+" or 
                indexElement is "-" or 
                indexElement is ")" or
                indexElement is "*"):
                    ifOperand=False

            if(indexElement is not "+" and 
                indexElement is not "-" and 
                indexElement is not "(" and 
                indexElement is not ")" and
                indexElement is not "*"):
                    ifOperand=True
                    print("TOKEN: " + indexElement)
                    stackArray.append(indexElement)
        if(indexElement == ")"):
            print("stuff")
    print(buffArray)


if __name__ == "__main__":
    stringInput = input("Enter the stuff: ")
    parse(stringInput)
