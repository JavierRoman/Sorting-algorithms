CC = gcc
CFLAGS = -Wall -g -I headers
EXE = test

all: $(EXE)

test: test.o sorting.o utils.o
	$(CC) -o test $^
test.o: test.c headers/sorting.h headers/utils.h
	$(CC) $(CFLAGS) -c test.c 
sorting.o: src/sorting.c headers/sorting.h  headers/utils.h
	$(CC) $(CFLAGS) -c src/sorting.c
utils.o: src/utils.c headers/utils.h
	$(CC) $(CFLAGS) -c src/utils.c

clean: 
	rm -rf $(EXE) *.o
