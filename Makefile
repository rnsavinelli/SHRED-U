CC = gcc
CFLAGS = `sdl2-config --libs --cflags` -Wall -g -lSDL2_image -lm
INCLUDES = -I ./inc
SOURCES = ./src/*.c
OBJS = $(SOURCES: .c = .o)
EXE = exe

compile:
	$(CC) $(SOURCES) $(INCLUDES) -o $(EXE) $(CFLAGS) $(LIBS)

execute:
	./$(EXE)

clean:
	rm -f $(EXE) $(OBJS)

.PHONY: all clean

