all: CS415_Elevator.x
CFLAGS=-std=c++11
DEPS=cs415_elevator.hpp printer.hpp
CC=g++
OPT=-Ofast


CS415_Elevator.x: main.cpp cs415_elevator.cpp printer.cpp
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


clean:
	rm -f *.o *.x *~ core
