#Jim Samson
#January 14, 2019
#State-machine

import parser.py

#Sets the state based on method.
class Context: 
    #Initialize state based on context.
    def __init__(self,state):
        self._state=state
    
    #Get-method based on request handle.
    def request(self):
        self._state.handle()

class State: #TODO add (metaclass=abc.ABCMeta):
    def handle(self):
        pass 

class StateParseString(State):

    def handle(self):
        pass

class 