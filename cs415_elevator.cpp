#include "cs415_elevator.hpp"

cs415_elevator::cs415_elevator()
{
	currentFloor = 0;
	floorReq = 0;
    summoned = false;
}

cs415_elevator::~cs415_elevator()
{
}

void cs415_elevator::call(int direction)
{
    if( !(direction >= -1 && direction <= 1) ) {
        std::cout << "A proper direction was not given." << std::endl;
    } else {
        if( direction == -1 )
            std::cout << "Elevator called to head down." << std::endl;
        
        if( direction == 1 )
            std::cout << "Elevator called to head up." << std::endl;
        
        if( direction == 0 )
            std::cout << "Elevator is idle." << std::endl;
    }
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

int cs415_elevator::get_req_floor()
{
	return floorReq;
}

void cs415_elevator::set_req_floor(int floor)
{
	floorReq = floor;
}
