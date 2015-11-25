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
    if ( !(input_direction >= -1 && input_direction <= 1) ) {
        std::cout << "A proper direction was not given." << std::endl;
    } else {
        if ( direction == IDLE) {
            direction = input_direction;
        }
        if (input_direction != direction) {
            std::cout << "Elevator is going opposite direction, call queued for later" << std::endl;
        }
        if ( input_direction == DOWN ) {
            std::cout << "Elevator called to head down." << std::endl;
            whichQueue = DOWN;
        }
        else if ( input_direction == UP ) {
            std::cout << "Elevator called to head up." << std::endl;
            whichQueue = UP;
        }
        else if ( input_direction == IDLE ) {
            std::cout << "Elevator is idle." << std::endl;
        }
        if (whichQueue == UP) {
            minQueue.push(get_req_floor());
        } else {
            maxQueue.push(get_req_floor());
        }

    }
}
//moves the elevator to queued levels, will only stop if direction desired is the same as the elevators direction.
// calls itself to go the other direction when complete if not empty.
//sets to IDLE when complete
void cs415_elevator::executeQueue() {
    //go through queue to each floor
    if (maxQueue.empty() && minQueue.empty()) { // a little bit of recursion in my life
        return;
    }
    std::cout << "Elevator is at: " << currentFloor << std::endl;
    int flr;
    if (direction == UP) {
        while (!minQueue.empty()) {
            flr = minQueue.top();
            if (flr < currentFloor) { // this check is for if the floor is in the opposite direction the elevator is travelling
                // skipping this essentially queues for later when executeQueue is called again.
                maxQueue.push(flr);
                break;

            }
            minQueue.pop();

            std::cout << "moving up ......." << std::endl;
            while (currentFloor < flr) {

                sleep(1);
                std::cout << "moved to " << currentFloor << std::endl;
                move_up();
            }

            std::cout << "Arriving at requested floor: " << flr << std::endl;
        }
    }
    else if (direction == DOWN) {
        while (!maxQueue.empty()) {
            flr = maxQueue.top();

            if (flr > currentFloor) {// this check is for if the floor is in the opposite direction the elevator is travelling
                // skipping this essentially queues for later when executeQueue is called again.

                minQueue.push(flr);
                break;

            }
            maxQueue.pop();

            std::cout << "moving down ......." << std::endl;
            while (currentFloor > flr) {

                sleep(1);
                std::cout << "moved to " << currentFloor << std::endl;
                move_down();
            }
            std::cout << "Arriving at requested floor: " << flr << std::endl;

        }
    }
    if (direction == UP) {
        direction = DOWN;
    }
    else {
        direction = UP;
    }
    executeQueue();
    direction = IDLE;
    std::cout << "Elevator is IDLE" << std::endl;
}

void cs415_elevator::setMax(int MAX) {
    maxFloors = MAX;
}

void cs415_elevator::move_up()
{
    if (currentFloor <= maxFloors) {
        currentFloor++;
        std::cout << "Move elevator up" << std::endl;
    }
    else
        std::cout << "Can't move up" << std::endl;

}

void cs415_elevator::move_down()
{

    if (currentFloor >= 1) {
        currentFloor--;
        std::cout << "Move elevator down" << std::endl;
    }
    else {
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

bool cs415_elevator::minQempty() {
    return minQueue.empty();
}

bool cs415_elevator::maxQempty() {
    return maxQueue.empty();
}

int cs415_elevator::get_direction() {
    return direction;
}

void cs415_elevator::set_direction(int dirtn) {
    direction = dirtn;
}

int cs415_elevator::get_minq_top() {
    return minQueue.top();
}

int cs415_elevator::get_maxq_top() {
    return maxQueue.top();
}

void cs415_elevator::push_maxq(int var) {
    maxQueue.push(var);
}

void cs415_elevator::push_minq(int var) {
    minQueue.push(var);
}

void cs415_elevator::pop_minq() {
    minQueue.pop();
}

void cs415_elevator::pop_maxq() {
    maxQueue.pop();
}