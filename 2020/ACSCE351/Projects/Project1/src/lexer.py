
#Jim Samson
#January 14, 2019
#lexer

ADD,SUB,MUL,LEFT_PAREN,RIGHT_PAREN = '+','-','*','(',')'

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
    left_Parent_Count = 0

    #STATES
    _DONE = 0
    _START = 1
    _PLUS = 2
    _SUB = 3
    _MUL = 4
    _LEFT_PAREN = 5
    _RIGHT_PAREN = 6
    _NUMBER = 7
    _STR_LIT = 8

    def __init__(self,input):
        self.string=input

    def currChar(self):
        if(self.pos+1 > len(self.string)):
            self.state = self._DONE
        else:
            return self.string[self.pos]

    def nextChar(self):
        if(self.pos+1 >= len(self.string)):
            self.state = self._DONE
        else:
            return self.string[self.pos+1]
    
    def nextNextChar(self):
        return self.string[self.pos+2]
    
    def drop1(self):
        self.pos += 1

    def add1(self):
        self.lexstr = self.lexstr + self.currChar()
        self.drop1()

    def maxMunch(self):
        return self.previous_Cat is LEXIT_OPERATOR or self.previous_Lex is LEXIT_OPERAND

    def isDigit(self,ch):
        return (ch >= '0' and ch <= '9')

    def handleStart(self):
        if self.isDigit(self.ch):
            self.add1()
            self.state = self._NUMBER
        elif self.ch == "(":
            self.add1()
            self.state = self._LEFT_PAREN
        else:
            self.add1()
            self.state = self._DONE

    def handleDigit(self):
        self.category = LEXIT_OPERAND
        if (self.isDigit(self.currChar())):
            self.add1()
            return [self.lexstr,self.category]

        elif(self.currChar() is "+"):
            self.state = self._PLUS

        elif(self.currChar() is '-'):
            self.state = self._SUB
            
        elif(self.currChar() is '*'):
            self.state = self._MUL

        elif(self.currChar() is '('):
            self.state = self._LEFT_PAREN

        elif(self.currChar() is ')'):
            self.state = self._RIGHT_PAREN
        else:
            self.state = self._DONE
    
    def handlePlus(self):
        self.category = LEXIT_OPERATOR
        if(self.isDigit(self.nextChar()) and not self.maxMunch()):
            self.add1()
            self.state = self._NUMBER
            return [self.lexstr,self.category]
        else:
            self.state = self._DONE
    
    def handleSub(self):
        self.category = LEXIT_OPERATOR
        if(self.isDigit(self.nextChar())):
            self.add1()
            self.state = self._NUMBER
            return [self.lexstr,self.category]
        else:
            self.state = self._DONE

    def handleMul(self):
        self.category = LEXIT_OPERATOR
        if(self.isDigit(self.nextChar()) and not self.maxMunch()):
            self.add1()
            self.state = self._NUMBER
            return [self.lexstr,self.category]
        elif(self.nextChar() is "(" and not self.maxMunch()):
            self.add1()
            self.state = self._LEFT_PAREN
            return [self.lexstr,self.category]
        else:
            self.state = self._DONE
           

    def handleLeftParen(self):
        self.category = LEXIT_OPERATOR
        self.left_Parent_Count += 1
        if(self.isDigit(self.nextChar()) and not self.maxMunch()):
            self.add1()
            self.state = self._NUMBER
            return [self.lexstr,self.category]
        elif(self.nextChar() is "("):
            self.add1()
            self.state = self._LEFT_PAREN
        else:
            self.state = self._DONE

    def handleRightParen(self):
        self.category = LEXIT_OPERATOR
        if(self.currChar() is ")"):
            self.add1()
            print("STRING: " + self.lexstr)
            if(self.nextChar() is '' or self.currChar() is '\n'):
                self.state = self._DONE
        elif(self.nextChar() is ")"):
            self.add1()
            self.state = self._RIGHT_PAREN

        elif (self.isDigit(self.nextChar())):
            self.add1()
            self.state = self._NUMBER

        elif(self.currChar() == "+"):
            self.state = self._PLUS

        elif(self.currChar() is '-'):
            self.state = self._SUB
            
        elif(self.currChar() is '*'):
            self.state = self._MUL

        elif(self.currChar() is '' or self.currChar() is '\n'):
            self.add1()
            self.state = self._DONE
        else:
            self.state = self._DONE
        return [self.lexstr,self.category]
    
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
            #print("STATE: " + str(self.state))
            #print("Current Char: " + self.currChar())
            #print("LEXSTR: " + self.lexstr)
            #print("NUM of LEFT PARENS: " + str(self.left_Parent_Count))
            if(self.state is self._START):
                self.handleStart()
            elif(self.state is self._NUMBER):
                #self.handleDigit()
                print(self.handleDigit())
            elif(self.state is self._PLUS):
                #self.handlePlus()
                print(self.handlePlus())
            elif(self.state is self._SUB):
                #self.handleSub()
                print(self.handleSub())
            elif(self.state is self._MUL):
                #self.handleMul()
                print(self.handleMul())
            elif(self.state is self._LEFT_PAREN):
                #self.handleLeftParen()
                print(self.handleLeftParen())
            elif(self.state is self._RIGHT_PAREN):
                #self.handleRightParen()
                print(self.handleRightParen())
            elif(self.state is self._STR_LIT):
                #self.handleStringLit()
                print(self.handleStringLit())
            self.previous_Lex = self.lexstr
            self.previous_Cat = self.category
        
        #self.previous_Lex = self.lexstr
        #self.previous_Cat = self.category
        return [self.lexstr, self.category]

    def getToken(self):
        return [self.lexstr, self.category]
        


# if __name__ == "__main__":
#     #inputString = input("Enter a list of numbers: ")
#     string = '5+3*(((((3+3))))))'
#     print("String: " + string)

#     x = lexer(string)
#     x.getLexeme()
#     #print("STATE: " + str(x.state))