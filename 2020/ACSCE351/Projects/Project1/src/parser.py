#!/usr/bin/env python3

#Jim Samson
#CSCE 351
#January 14, 2019
#Parsing algorithm using AST

from lexer import lexer

#Symbolic Constants
STMT_LIST = 1

class parse(lexer):

    #Class Variables

    #For lexit iteration
    iterate = None #iter returned from lexit
    state = [] #state returned from lexit
    lexer_out_s = None
    lexer_out_c = None 

    #Current Lexeme
    lexstr = ""
    lexcat = 0

    def iterateString(self,string):
        return self.lexer_out_s[self.iterate]

    def __init__(self):
        string = "456*4+4*(4-2)"
        x = lexer(string)
        self.iterate, self.lexer_out_s, self.lexer_out_c = x.getLexeme()
        
        self.advance()

    def advance(self):
        print("fdsa1: " + self.lexer_out_s)
        self.lexer_out_s = iter(self.lexer_out_s)
        print("fdsa: " + str(self.lexer_out_s))
        if self.lexer_out_s is not None:
            self.lexstr, self.lex = self.lexer_out_s, self.lexer_out_c
        else:
            self.lexstr, self.lexcat = "", 0

    def atEnd(self):
        return self.lexcat == 0
    
    def matchString(self, string):
        if(self.lexstr is string):
            self.advance()
            return True
        else:
            return False

    def matchCat(self, character):
        if(self.lexcat is character):
            self.advance()
            return True
        else:
            return False

    def parse(self):
        good, ast = self.parse_program()
        done = self.atEnd()
        return good, done, ast
    
    def parse_program(self):
        good, ast = parse_statement_list()
        return good, ast

    def parse_statement_list(self):
        good, ast, ast2 = None, None, None

        ast = [STMT_LIST]

        # while(True):
        #     if lexstr is not 
if __name__ == "__main__":
    p = parse()

