#!/usr/bin/make
# Makefile for opencv compilation
CC=g++

CFLAGS = -O2 -Wall
LDFLAGS=
EXEC=main


SRC= ./src/main.cpp \
	./src/Matrix.cpp

OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< $(CFLAGS)

clean: $(OBJ)
	find . -name *.o -exec rm {} \;
	rm $(EXEC)
