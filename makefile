CC=g++
CFLAgs=-std=c++11

elevator.x: ElevatorSimone.cpp ElevatorSimone.hpp main.cpp
	$(CC) -ggdb -o elevator.x ElevatorSimone.cpp main.cpp -std=c++11

