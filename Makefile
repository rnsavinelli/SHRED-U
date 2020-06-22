# Makefile for SHRED-U to automate its compilation
# by Roberto Nicolás Savinelli

CC = gcc
CFLAGS = `sdl2-config --libs --cflags` -Wall -g -lSDL2_image -lSDL2_ttf -lm
INCLUDES = -I inc/ -I inc/sdl/
SOURCES = src/*.c src/sdl/*.c
OBJS = $(SOURCES: .c = .o)
EXE = exe

compile:
	$(CC) $(SOURCES) $(INCLUDES) -o $(EXE) $(CFLAGS) $(LIBS)

execute:
	./$(EXE)

clean:
	rm -f $(EXE)

.PHONY: all clean

