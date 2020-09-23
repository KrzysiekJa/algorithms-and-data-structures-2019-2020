#compiler
CC = g++
LD = g++

#flags
CFLAGS = -std=c++11


all: list


list: list_run.o
	$(LD) $(CFLAGS) -o list list_run.o -Wall

list_run.o: list_run.cpp list.hpp node.hpp
	$(CC) $(CFLAGS) -c list_run.cpp list.hpp node.hpp -Wall


.PHONY: clean run

run: list
	./list

clean:
	rm -f *.o