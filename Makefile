CC = g++
CCFLAGS = -std=c++11 -g
tictac: main.cpp TicTac.h TicTac.cpp
	$(CC) $(CCFLAGS) -o tictac main.cpp TicTac.cpp
