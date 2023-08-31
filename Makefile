CC = gcc
CFLAGS = -o

split: main.o split.o
	$(CC) $(CFLAGS) split main.o

main.o: main.c split.h

split.o: split.c split.h