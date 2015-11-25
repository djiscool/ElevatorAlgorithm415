/***********************
 * CS415 Elevator Main
 ***********************/
#include <iostream>
#include <vector>
#include "cs415_elevator.hpp"
#include "printer.hpp"

void executeQueue(int whichElevator, std::vector<cs415_elevator*> *elevators, printer* elvPrinter) {
    const int DOWN = -1;
    const int IDLE = 0;
    const int UP = 1;
    //go through queue to each floor
    if (elevators->at(whichElevator)->maxQempty() && elevators->at(whichElevator)->minQempty()) { // a little bit of recursion in my life
        return;
    }
    std::cout << "Elevator is at: " << elevators->at(whichElevator)->get_current_floor() << std::endl;
    int flr;
    if (elevators->at(whichElevator)->get_direction() == UP) {
        while (!elevators->at(whichElevator)->minQempty()) {
            flr = elevators->at(whichElevator)->get_minq_top();
            if (flr < elevators->at(whichElevator)->get_current_floor()) { // this check is for if the floor is in the opposite direction the elevator is travelling
                // skipping this essentially queues for later when executeQueue is called again.
                elevators->at(whichElevator)->push_maxq(flr);
                break;

            }
            elevators->at(whichElevator)->pop_minq();
            std::cout << "moving up ......." << std::endl;
            while (elevators->at(whichElevator)->get_current_floor() < flr) {

                sleep(1);
				int curflr = elevators->at(whichElevator)->get_current_floor();
                std::cout << "moved to " << curflr << std::endl;
                elevators->at(whichElevator)->move_up();
				elvPrinter->upFloor (0, 1, curflr);
				elvPrinter->printBuilding();
            }

            std::cout << "Arriving at requested floor: " << flr << std::endl;
        }
    }
    else if (elevators->at(whichElevator)->get_direction() == DOWN) {
        while (!elevators->at(whichElevator)->maxQempty()) {
            flr = elevators->at(whichElevator)->get_maxq_top();

            if (flr > elevators->at(whichElevator)->get_current_floor()) {// this check is for if the floor is in the opposite direction the elevator is travelling
                // skipping this essentially queues for later when executeQueue is called again.

                elevators->at(whichElevator)->push_minq(flr);
                break;

            }
            elevators->at(whichElevator)->pop_maxq();
            std::cout << "moving down ......." << std::endl;
            while (elevators->at(whichElevator)->get_current_floor() > flr) {

                sleep(1);
				int curflr = elevators->at(whichElevator)->get_current_floor();
                std::cout << "moved to " << curflr << std::endl;
                elevators->at(whichElevator)->move_down();
				elvPrinter->downFloor(0,1, curflr);
				elvPrinter->printBuilding();
            }
            std::cout << "Arriving at requested floor: " << flr << std::endl;

        }
    }
    if (elevators->at(whichElevator)->get_direction() == UP) {
        elevators->at(whichElevator)->set_direction(DOWN);
    }
    else {
        elevators->at(whichElevator)->set_direction(UP);
    }
    executeQueue(0, elevators, elvPrinter);
    elevators->at(whichElevator)->set_direction(IDLE);
    std::cout << "Elevator is IDLE" << std::endl;
}

void chooseElevatorForMe(int floor, int* whichElevator) {

}

int main(int argc, char **argv)
{
    std::vector<cs415_elevator*> *elevators = new std::vector<cs415_elevator*>;
    printer* elvPrinter = new printer();
    int buildingFloors = 0;
    int numElevators = 0;

    const int DOWN = -1;
    const int IDLE = 0;
    const int UP = 1;

    //Get Input
    std::cout << "Building has how many floors? ";
    std::cin >> buildingFloors;

    std::cout << "How many elevators in the building? ";
    std::cin >> numElevators;

    elvPrinter->createBuilding(buildingFloors, numElevators);

    // Make a vector of elevators
    for (int i = 0; i < numElevators; i++) {
        cs415_elevator *tmp = new cs415_elevator;
        elevators->push_back(tmp);
    }

    std::cout << "Elevators installed: " << elevators->size() << std::endl;
    elevators->at(0)->setMax(buildingFloors);
    for (int i = 0; i < numElevators; i++) {
        std::cout << "Elevator: " << i+1 << " is at floor: " << elevators->at(i)->get_current_floor() << std::endl;
    }
    int inputFloor;
    int direction;
    bool more = true;
    //loop for running elevator, elevator dies when exited.
    while (more) {
        std::cout << "Elevator at: " << elevators->at(0)->get_current_floor() << std::endl;
        //loop(the do-while one) to get input, elevator does not move until this loop ends
        do {
            //Get input
            std::cout << "Enter floor you are on(-1 to quit)";
            std::cin >> inputFloor;
            if (inputFloor == -1) {
                break;
            }
            if (inputFloor == elevators->at(0)->get_current_floor()) {
                std::cout << "Elevator already there!" << std::endl;
                continue;
            }
            std::cout << "Enter desired direction (1:UP, 2:DOWN)";
            std::cin >> direction;
            if (direction == -1)
                break;
            if (inputFloor < 0 || inputFloor > buildingFloors) {
                std::cout << "invalid floor, not a floor!" << std::endl;;
                break;
            }

            //parse input
            if (direction == 1)
                direction = UP;
            if (direction == 2)
                direction = DOWN;
            elevators->at(0)->set_req_floor(inputFloor);
            //store input
            elevators->at(0)->call(direction);


        } while ((direction == -1 || direction == 1) &&  inputFloor != -1) ;
        //move elevator
        executeQueue(0, elevators, elvPrinter); // need to move this to main so I can use the printer.
        elvPrinter->printBuilding();

        std::cout << "continue? (y/n): ";
        char cont;
        std::cin >> cont;
        if (cont == 'n' || cont == 'N') {
            std::cout << "Elevators' final resting place is: " << elevators->at(0)->get_current_floor() << std::endl;
            more = false;
        }
        std::cout << "-----------------------------------------------" << std::endl;

    }
    // Free up pointers
    elevators->clear();
    delete elevators;

    return 0;
}

