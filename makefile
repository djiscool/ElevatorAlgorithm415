CC=g++
CFLAGS=-std=c++11

elevator.x: ElevatorSimone.cpp ElevatorSimone.hpp main.cpp elevator.o
	$(CC) -ggdb -o elevator.x ElevatorSimone.cpp main.cpp elevator.o $(CFLAGS)

elevator.o: elevator.cpp elevator.hpp
	$(CC) -ggdb -c elevator.cpp $(CFLAGS)
clean:
	rm -f *.o *.x ~* core

