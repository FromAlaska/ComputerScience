#!/usr/bin/env python3

import sys

buffArray = []
stackArray = []
operatorIsTrue = False
ifOperand = False
ifParanthesis = False

openParen = []

def joinNums(string_left, string_right):
    return string_left + string_right

#ONLY EVALUATES SINGLE NODES
def evalBuff(buffString):
    indexNumber = 0
    for i,char in enumerate(buffString):
        if(buffString[i+1] == "*"):
            return int(buffString[i]) + int(buffString[i+2])
        elif(buffString[i+1] == "+"):
            #indexNumber += 1
            return int(buffString[i]) + int(buffString[i+2])
        elif(buffString[i+1] == "-"):
            return int(buffString[i]) + int(buffString[i+2])
        

def joinString(leftSide, rightSide, string):
    for x in range(0,rightSide-leftSide):
        stackArray.append(string[x])

#Evaluate things
def evaluate(inputString):
    buffString = []
    left_paren_index = 0
    right_paren_index = 0
    for i,char in enumerate(inputString):
        if(char == "("):
            left_paren_index = i+1
            #print(left_paren_index)
        if(inputString[i] == ")"):
            right_paren_index = i
            #print(right_paren_index)
    #stackArray = inputString[0:left_paren_index-1]
    joinString(0,left_paren_index-1,inputString)
    print("STACK: " + str(stackArray))
    buffString = inputString[left_paren_index:right_paren_index]
    print(buffString)
    print("EVAL: " + str(evalBuff(buffString)))
    joinString(0,1,str(evalBuff(buffString)))
    print("STACK: " + str(stackArray))


#Basic Parsing Algorithm
def parse(inputString):
    character = ''
    buffArray = inputString #Make a copy of the stuff
    print("Input: " + buffArray)
    evaluate(inputString)

if __name__ == "__main__":
    stringInput = input("Enter the stuff: ")
    parse(stringInput)
