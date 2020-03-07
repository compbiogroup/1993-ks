CXX = g++
CPPFLAGS = -ggdb -Wall -pedantic -O3 -std=c++11
OBJS = ../include/permutation.o ../include/events.o ../include/breakpoint.o ../include/reversal.o ../include/algorithm.o
BIN = main

files: $(OBJS)
	ar rvs libavocado.a $(OBJS)
clean:
	rm -f *.a ../include/*.o
