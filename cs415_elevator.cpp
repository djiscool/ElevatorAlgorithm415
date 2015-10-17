#include "cs415_elevator.hpp"

cs415_elevator::cs415_elevator()
{
	currentFloor = 0;
	floorReq = 0;
}

cs415_elevator::~cs415_elevator()
{
}

void cs415_elevator::call()
{
	std::cout << "Elevator called" << std::endl;
}

void cs415_elevator::move_up()
{
	std::cout << "Move elevator up" << std::endl;
}

void cs415_elevator::move_down()
{
	std::cout << "Move elevator down" << std::endl;
}

int cs415_elevator::get_current_floor()
{
	return currentFloor;
}

void cs415_elevator::set_current_floor(int floor)
{
	currentFloor = floor;
}

int cs415_elevator::get_floor_req()
{
	return floorReq;
}

void cs415_elevator::set_floor_req(int floor)
{
	floorReq = floor;
}
