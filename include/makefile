CXX = g++
CPPFLAGS = -ggdb -Wall -pedantic -O3 -std=c++11
OBJS = permutation.o events.o breakpoint.o reversal.o algorithm.o main.o
BIN = main

file: $(OBJS)
	$(CXX) -o $(BIN) $(CPPFLAGS) $(OBJS) -lm
clean:
	rm -f *.o
