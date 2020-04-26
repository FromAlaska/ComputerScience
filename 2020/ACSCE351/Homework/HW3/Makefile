CC = gcc
PY = python2
CFLAGS = -Wall -O3 -march=native
TEST = test.c
PROGS = naive rabin knuth
	
all: $(PROGS)

naive: $(TEST) MatchStrings.c
	$(CC) -o $@ $^ $(CFLAGS)

rabin: $(TEST) rabinkarp.c
	$(CC) -o $@ $^ $(CFLAGS)

knuth: $(TEST) kmp.c
	$(CC) -o $@ $^ $(CFLAGS)
	
randomchar:
	$(PY) randomcharactergenerator.py

clean:
	rm -rf naive rabin knuth
