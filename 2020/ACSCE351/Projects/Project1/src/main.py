#!/usr/bin/env python3

import sys

buffArray = []
stackArray = []
state = None

STATE_ADD = None

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
        if(indexElement is "+" or 
           indexElement is "-" or 
           indexElement is "(" or 
           indexElement is ")" or
           indexElement is "*"):
            print("TOKEN (operator): " + indexElement)
            operand_2 = stackArray.pop()
            operand_1 = stackArray.pop()
            result = evaluateFunction(operand_2, operand_1, indexElement)
            print("RESULT: " + str(result))
        if(indexElement is not "+" and 
           indexElement is not "-" and 
           indexElement is not "(" and 
           indexElement is not ")" and
           indexElement is not "*"):
            print("TOKEN: " + indexElement)
            stackArray.append(indexElement)
    print(buffArray)

if __name__ == "__main__":
    stringInput = input("Enter the stuff: ")
    parse(stringInput)
