all: main.o biblioteca.o
	@gcc main.o biblioteca.o -o main

main.o: main.c
	@gcc main.c -c

biblioteca.o: biblioteca.c
	@gcc biblioteca.c -c

run:
	@./main	