CC = g++
CFLAGS = -ggdb -Wall -pedantic -O3
OBJS = permutation.o events.o breakpoint.o reversal.o algorithm.o main.o
BIN = main

file: $(OBJS)
	$(CC) -o $(BIN) $(CFLAGS) $(OBJS) -lm
clean:
	rm -f *.o
