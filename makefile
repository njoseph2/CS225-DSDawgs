# Makefile for PageRank
CC=g++
CFLAGS=-std=c++11 -I ./include
SOURCES=main.cpp graph.cpp CSV.cpp pagerank.cpp
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@

test:
	$(CC) $(CFLAGS) $(LDFLAGS) testcsv.cpp graph.cpp CSV.cpp pagerank.cpp -o test

clean:
	rm $(EXECUTABLE)
