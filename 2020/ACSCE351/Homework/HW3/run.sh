#!/bin/bash
clear && gcc ./kmp.c ./test.c -Wall -O3 -march=native -o testString -lm && ./testString ./Scripts/randomlyGeneratedString zbtyq
