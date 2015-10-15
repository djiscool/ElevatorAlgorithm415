#include "ElevatorSimone.hpp"
#include <iostream>

int main(int argc, char* argv[]){
	ElevatorSimone my_simone;
	std::cout << "starting Elevator" << std::endl;	
	my_simone.runElevator();
	std::cout << "moving floor up 1" << std::endl;
	my_simone.upFloor();
	
	std::cout << "moving floor up 1" << std::endl;
	my_simone.upFloor();
	
	std::cout << "moving floor down 1" << std::endl;
	my_simone.downFloor();
	
	std::cout << "moving floor down 1" << std::endl;
	my_simone.downFloor();
	
	std::cout << "shutting down" << std::endl;
	my_simone.stopElevator();


}
