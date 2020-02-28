CC= gcc
CFLAGS= -ansi -W -std=c99 -Wall -pedantic
EXEC= main

all: $(EXEC)
	
main: main.o main.c ListManager.h ListManager.c
	$(CC) -o main.o main.c $(CFLAGS)

clean :
	$(rm -rf *.o)