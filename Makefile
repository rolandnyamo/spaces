# # .author: Roland Nyamoga (nyamogar@oregonstate.edu)
# # .descr: Makefile for the final project

CC = g++

CFLAGS = -c
CFLAGS = -Wall
CFLAGS += -std=c++11
CFLAGS += -g #To debug with gdb

SRCS = gamespace.cpp item.cpp menu.cpp player.cpp sindoor.cpp space.cpp main.cpp moving.cpp dangerous.cpp
OBJS =  gamespace.o item.o menu.o player.o sindoor.o space.o main.o moving.o dangerous.o
HEADERS = gamespace.hpp item.hpp menu.hpp player.hpp sindoor.hpp space.hpp moving.hpp dangerous.hpp
OUT = fingames #Name of the executable

#My output depends on the objects.
$(OUT): $(OBJS)
	$(CC) $(SRCS) $(CFLAGS) -o $(OUT)
	rm $(OBJS) *.gch

#Objects depend on source and header files
$(OBJS): $(SRCS) $(HEADERS)
	$(CC) -c $(CFLAGS) $(SRCS) $(HEADERS) 

#This cleans all files created from compiling
clean:
	rm $(OUT)
	clear
