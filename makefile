# Makefile for PageRank
CC=g++
CFLAGS=-std=c++11 -I ./include -g
SOURCES=main.cpp graph.cpp CSV.cpp BFS.cpp pagerank.cpp FDG.cpp
TESTSOURCES=graph.cpp CSV.cpp BFS.cpp pagerank.cpp FDG.cpp
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o bin/$@

clean:
	-rm bin/$(EXECUTABLE)

tests: tests.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $(TESTSOURCES) $^ -o bin/tests
