#include "cs415_elevator.hpp"
//constructor
cs415_elevator::cs415_elevator()
{
	currentFloor = 1;
	floorReq = 0;
    	summoned = false;
	direction = IDLE;
	maxFloors = 0;
}

cs415_elevator::~cs415_elevator()
{
}
//takes input and queues up elevator calls
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
			whichQueue = DOWN;
		}
        else if( input_direction == UP ){
            std::cout << "Elevator called to head up." << std::endl;
			whichQueue = UP;
		}
        else if( input_direction == IDLE ){
            std::cout << "Elevator is idle." << std::endl;
		}
	if(whichQueue == UP){
		minQueue.push(get_req_floor());
	}else{
		maxQueue.push(get_req_floor());
	}
	
}
}
//moves the elevator to queued levels, will only stop if direction desired is the same as the elevators direction.
// calls itself to go the other direction when complete if not empty.
//sets to IDLE when complete
void cs415_elevator::executeQueue(){
	//go through queue to each floor
	if(maxQueue.empty() && minQueue.empty()){ // a little bit of recursion in my life
		return;
	}
	std::cout << "Elevator is at: " << currentFloor << std::endl;
	int flr;
	if(direction == UP){
		while(!minQueue.empty()){
			flr = minQueue.top();
			minQueue.pop();
			while(currentFloor <= flr){
				std::cout << "waiting for move ......." << std::endl;
				std::cout << "moved to " << currentFloor << std::endl;
				if(flr != currentFloor){
					move_up();
			}
			}
		}	
	}
	else if(direction == DOWN){
		while(!maxQueue.empty()){
			flr = maxQueue.top();
			maxQueue.pop();
			while(currentFloor >= flr){
				std::cout << "waiting for move ......." << std::endl;
				std::cout << "moved to " << currentFloor << std::endl;
				if(flr != currentFloor){
					move_down();
			}
			}
		}
	}
	if(direction == UP){
		direction = DOWN;
	}
	else{
		direction = UP;
	}
	executeQueue();
	direction = IDLE;
	std::cout << "Elevator is IDLE" << std::endl;
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
