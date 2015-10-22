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
	int inputFloor;
	int direction;
do{
	std::cout << "Enter floor you are on(-1 to quit)";
	std::cin >> inputFloor;
	
	if(direction == -1 || inputFloor == -1)
		break;
	
	std::cout << "Enter desired direction (1:UP, 2:DOWN)";
	std::cin >> direction;
	if(direction == -1 || inputFloor == -1)
		break;
	if(inputFloor < 0 || inputFloor > buildingFloors){
		std::cout << "invalid floor, self destruct enabled" << std::endl;;
		break;
	}
	if(direction == 1)
		direction = UP;
	if(direction == 2)
		direction = DOWN;
    	elevators->at(0)->set_req_floor(inputFloor);
	elevators->at(0)->call(direction);
	
        std::cout << "Elevator: " << 0 << " is at floor: " << elevators->at(0)->get_current_floor() << std::endl;
	
	}while(direction == -1 || inputFloor == -1 || direction == 1 || direction == 2 );
 

    
    // Free up pointers
    elevators->clear();
    delete elevators;
    
	return 0;
}

