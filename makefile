CC = clang++
CFLAGS = -Wall -lmenu -lncurses -std=c++11 -I$(HANDLE_INCLUDES) -I$(IMPLEMENT_INCLUDES) -g

IDIR = ./include/
SRCDIR = ./src/

HANDLE_INCLUDES=$(IDIR)handle/
IMPLEMENT_INCLUDES=$(IDIR)implement/

SOURCES = $(SRCDIR)implement/*.cpp\
		  $(SRCDIR)handle/*.cpp\



all: nethack

nethack: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./nethack

clean:
	rm nethack