#!/usr/bin/env python3

#Jim Samson
#January 14, 2019
#lexer

ADD,SUB,MUL,LEFT_PAREN,RIGHT_PAREN = '+','-','*','(',')'
CATEGORIES=[ADD,SUB,MUL,LEFT_PAREN,RIGHT_PAREN]
white_space = ' '

lex_catnames=['ADD','SUB','MUL','LEF_PAR','RIG_PAR']

#Lexit categories
LEXIT_OPERATOR = 1 
LEXIT_OPERAND = 2

#Class LEXER!
#Can be used as an object to tokenize strings.
class lexer():
    lexeme = ''
    previous_Cat = ''
    previous_Lex = ''
    state = None
    category = None
    handler = None
    pos = 0
    lexstr = ''
    ch = '' 

    #STATES
    _DONE = 0
    _START = 1
    _PLUS = 2
    _SUB = 3
    _MUL = 4
    _LEFT_PAREN = 5
    _RIGHT_PAREN = 6
    _NUMBER = 7

    def __init__(self,input):
        self.string=input

    def currChar(self):
        print(self.string[self.pos])
        return self.string[self.pos]

    def nextChar(self):
        return self.string[self.pos+1]
    
    def nextNextChar(self):
        return self.string[self.pos+2]
    
    def drop1(self):
        print("STRING: "+self.lexstr)
        self.pos += 1

    def add1(self):
        self.lexstr = self.lexstr + self.currChar()
        self.drop1()

    def maxMunch(self):
        return self.previous_Cat is LEXIT_OPERATOR or previous_Lex is LEXIT_OPERAND

    def isDigit(self,ch):
        return (ch >= '0' and ch <= '9')

    def handleStart(self):
        if self.isDigit(self.ch):
            self.add1()
            self.state = self._NUMBER
        elif self.ch == "+":
            self.add1()
            self.state = self._PLUS
        elif self.ch == "-":
            self.add1()
            self.state = self._SUB
        elif self.ch == "*":
            self.add1()
            self.state = self._MUL
        elif self.ch == "(":
            self.add1()
            self.state = self._LEFT_PAREN
        elif self.ch == ")":
            self.add1()
            self.state = self._RIGHT_PAREN
        else:
            self.add1()
            self.state = self._DONE

    def handleDigit(self):
        if (self.isDigit(self.ch)):
            self.add1()

        if(self.isDigit(self.nextChar())):
            self.add1()
            self.state = self._NUMBER
            
        elif(self.currChar() == "+"):
            self.state = self._PLUS

        elif(self.currChar() is '-'):
            self.state = self._SUB
            
        elif(self.nextChar() == "*"):
            self.state = self._MUL

        elif(self.nextChar() == "("):
            self.state = self._LEFT_PAREN

        elif(self.nextChar() == ")"):
            self.state = self._RIGHT_PAREN
        else:
            self.state = self._DONE
    
    def handlePlus(self):
        if(self.isDigit(self.nextChar()) and not self.maxMunch()):
            self.add1()
            self.state = self._NUMBER
        else:
            self.state = self._DONE
    
    def handleSub(self):
        print("SUB STATE")

    def handleMul(self):
        print("MUL STATE")    

    def handleLeftParen(self):
        if(self.isDigit(self.nextChar()) and not self.maxMunch()):
            self.add1()
            self.state = self._NUMBER
        else:
            self.state = self._DONE

    def handleRightParen(self):
        print("RIGHT STATE")
    
    def handleDone(self):
        print("Error in parsing")
        assert(0)

    #getLexeme
    #Base case: get the current lexeme and put state to start.
    def getLexeme(self):
        if self.pos > len(self.string):
            return None

        self.state = self._START

        while(self.state is not self._DONE):
            self.ch = self.currChar()
            if(self.state is self._START):
                self.handleStart()
            if(self.state is self._NUMBER):
                self.handleDigit()
            if(self.state is self._PLUS):
                self.handlePlus()
            if(self.state is self._SUB):
                self.handleSub()
            if(self.state is self._MUL):
                self.handleMul()
            if(self.state is self._LEFT_PAREN):
                self.handleLeftParen()
            if(self.state is self._RIGHT_PAREN):
                self.handleRightParen()
        
        self.previous_Lex = self.lexstr
        self.previous_Cat = self.category

        return self.lexstr, self.category
        


if __name__ == "__main__":
    #inputString = input("Enter a list of numbers: ")
    string = '53-2*(3+3)'
    print("String: " + string)

    x = lexer(string)
    x.getLexeme()
    #print("STATE: " + str(x.state))