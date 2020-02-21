# Jim Samson
# 02/18/2020
# CSCE351
# Homework 1 
# This is a homework assignment for CSCE 351. 
# Included is the transition function 
# for the DFA class. 

from automata import *

""" ********(Delta Function)********
    delta is either a function taking a state and a 1-character
    string in argument (positional arguments in this order) and
    returning either a state or a frozenset of states (see above) 
    or a dictionary mapping pairs (q,a) of a state q and a 1-character
    string a to a state or to a frozenset of states (see above)

    delta must be defined on all possible combinations of states
    and symbols in the alphabet, i.e. the automaton must have a 
    transition with every symbol in the alphabet for every state, 
    possibly to a capture state.
"""
def transition(q, a):
    state = q
    if state == "0":
        return "(1)


# MAIN
if __name__ == "__main__":
    a = DFA("DFA", "{0,1}", "ASDF", transition(), "{0}", "{1}")