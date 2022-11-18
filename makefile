# Makefile for PageRank
CC=g++
CFLAGS=-std=c++11 -I ./include
SOURCES=main.cpp graph.cpp csv.cpp pagerank.cpp
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@

clean:
	-rm $(EXECUTABLE)