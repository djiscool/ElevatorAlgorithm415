/***********************
 * CS415 Elevator Main
 ***********************/
#include <iostream>
#include "cs415_elevator.hpp"

int main(int argc, char **argv)
{
	cs415_elevator E1;

	int buildingFloors = 0;
	int numElevators = 0;
	std::cout << "Building has how many floors? ";
	std::cin >> buildingFloors;
	std::cout << "How many elevators in the building? ";
	std::cin >> numElevators;

	E1.set_current_floor(4);
	E1.call();
	std::cout << "Current floor: " << E1.get_current_floor() << std::endl;
	E1.set_floor_req(7);
	std::cout << "Requested floor: " << E1.get_floor_req() << std::endl;
	E1.move_up();
	E1.move_down();
	
	return 0;
}

