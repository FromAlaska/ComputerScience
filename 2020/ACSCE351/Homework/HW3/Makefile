CC = gcc
PY = python2
CFLAGS = -Wall -O3 -march=native
TEST = ./src/test.c
PROGS = naive rabin knuth
	
all: $(PROGS)

naive: $(TEST) ./src/MatchStrings.c
	$(CC) -o $@ $^ $(CFLAGS)

rabin: $(TEST) ./src/rabinkarp.c
	$(CC) -o $@ $^ $(CFLAGS)

knuth: $(TEST) ./src/kmp.c
	$(CC) -o $@ $^ $(CFLAGS)
	
randomchar:
	$(PY) ./src/randomcharactergenerator.py

multipleoccurance:
	$(PY) ./src/multipleOccuranceAgenerator.py

clean:
	rm -rf naive rabin knuth
