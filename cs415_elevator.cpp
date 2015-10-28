#include "cs415_elevator.hpp"

cs415_elevator::cs415_elevator()
{
	currentFloor = 0;
	floorReq = 0;
    	summoned = false;
	direction = IDLE;
	maxFloors = 0;
}

cs415_elevator::~cs415_elevator()
{
}

void cs415_elevator::call(int input_direction)
{	
	int whichQueue = 0;
    if( !(input_direction >= -1 && input_direction <= 1) ) {
        std::cout << "A proper direction was not given." << std::endl;
    } else {
	if( direction == IDLE){
		direction = input_direction;		
	}
	if(input_direction != direction){
		std::cout << "Elevator is going opposite direction, call queued for later" << std::endl;
	}
	
        if( input_direction == DOWN ){
            std::cout << "Elevator called to head down." << std::endl;
            //move_down();
		whichQueue = DOWN;
	}
        else if( input_direction == UP ){
            std::cout << "Elevator called to head up." << std::endl;
       	    //move_up();
		whichQueue = UP;
	}
        else if( input_direction == IDLE )
            std::cout << "Elevator is idle." << std::endl;
    
	if(whichQueue == UP){
		minQueue.push(get_req_floor());
	}else{
		maxQueue.push(get_req_floor());
	}
	
}
}
void cs415_elevator::executeQueue(){
	//go through queue to each floor
	
	int flr;
	if(direction == UP){

	while(!minQueue.empty()){
		flr = minQueue.top();
		minQueue.pop();
		currentFloor = flr;

		std::cout << "waiting for move ......." << std::endl;
		std::cout << "moved to " << currentFloor << std::endl;

	}	

	}else{


	while(!maxQueue.empty()){
		flr = maxQueue.top();
		maxQueue.pop();
		currentFloor = flr;

		std::cout << "waiting for move ......." << std::endl;
		std::cout << "moved to " << currentFloor << std::endl;

	}
	}	
}

void cs415_elevator::setMax(int MAX){
	maxFloors = MAX;
}

void cs415_elevator::move_up()
{
	if(currentFloor < maxFloors){ 
		currentFloor++;
		std::cout << "Move elevator up" << std::endl;
	}
	else
		std::cout << "Can't move up" << std::endl;

}

void cs415_elevator::move_down()
{

	if(currentFloor > 1){
	currentFloor--;
	std::cout << "Move elevator down" << std::endl;
	}
	else{
		std::cout << "Can't move down" << std::endl;

	}
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
