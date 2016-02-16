#!/usr/bin/make
# Makefile for opencv compilation
CC=icpc

#OPENCV=-I/opt/local/include/ -L/opt/local/lib -lcxcore -lcv -lhighgui
CFLAGS = -Ofast `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`

all: clean mandelbrot

mandelbrot:
	$(CC) mandelbrot.cpp -o mandelbrot $(CFLAGS) $(LIBS)

julia:
	$(CC) julia.cpp -o julia $(OPENCV)

clean:
	rm -rf *o mandelbrot julia
