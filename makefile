# Makefile for PageRank
CC=g++
CFLAGS=-std=c++11 -I ./include -g
SOURCES=main.cpp graph.cpp CSV.cpp BFS.cpp pagerank.cpp FDG.cpp cs225/PNG.cpp cs225/HSLAPixel.cpp lodepng/lodepng.cpp visualize.cpp
TESTSOURCES=graph.cpp CSV.cpp BFS.cpp FDG.cpp pagerank.cpp cs225/PNG.cpp cs225/HSLAPixel.cpp lodepng/lodepng.cpp visualize.cpp
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o bin/$@

clean:
	-rm bin/$(EXECUTABLE)

tests: tests.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $(TESTSOURCES) $^ -o bin/tests
