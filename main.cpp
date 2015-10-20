/***********************
 * CS415 Elevator Main
 ***********************/
#include <iostream>
#include <vector>
#include "cs415_elevator.hpp"

int main(int argc, char **argv)
{
    std::vector<cs415_elevator*> *elevators = new std::vector<cs415_elevator*>;
	int buildingFloors = 0;
	int numElevators = 0;
    enum direction { DOWN = -1, IDLE = 0, UP = 1 };
    
	std::cout << "Building has how many floors? ";
	std::cin >> buildingFloors;
    
	std::cout << "How many elevators in the building? ";
	std::cin >> numElevators;
    
    // Make a vector of elevators
    for(int i = 0; i < numElevators; i++) {
        cs415_elevator *tmp = new cs415_elevator;
        elevators->push_back(tmp);
    }
    
    std::cout << "Elevators installed: " << elevators->size() << std::endl;
    
    for(int i = 0; i < numElevators; i++) {
        std::cout << "Elevator: " << i << " is at floor: " << elevators->at(i)->get_current_floor() << std::endl;
    }
    
    
    // Free up pointers
    elevators->clear();
    delete elevators;
    
	return 0;
}

