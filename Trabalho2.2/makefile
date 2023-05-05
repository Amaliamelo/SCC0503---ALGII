CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g
	
.PHONY: all
all: main

main: main.o biblioteca.o
	$(CC) $(CFLAGS) -o main main.o biblioteca.o
	
main.o: main.c biblioteca.h
	$(CC) $(CFLAGS) -c main.c

biblioteca.o: biblioteca.c biblioteca.h
	$(CC) $(CFLAGS) -c biblioteca.c

	
clean:
	rm -f *.o main

run:
	./programa