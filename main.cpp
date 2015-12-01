/***********************
 * CS415 Elevator Main
 ***********************/
#include <iostream>
#include <vector>
#include "cs415_elevator.hpp"
#include "printer.hpp"

    const int DOWN = -1;
    const int IDLE = 0;
    const int UP = 1;

void executeQueue(int whichElevator, std::vector<cs415_elevator*> *elevators, printer* elvPrinter) {
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
    executeQueue(whichElevator, elevators, elvPrinter);
    elevators->at(whichElevator)->set_direction(IDLE);
    std::cout << "Elevator is IDLE" << std::endl;
}

int chooseElevator(int floor, int direction, int numElevators, std::vector<cs415_elevator*> *elevators) {
    int theChosenOne = 0;

    int difference = 0;

    bool isIdle = true;

    // for each elevator

    for (int i = 0; i < numElevators; i++) {
        // get its current floor

        int curFlr = elevators->at(i)->get_current_floor();
        // get its direction

        int curDir = elevators->at(i)->get_direction();
        // compare what elevator is closest, and going the same direction
        if (curDir != direction) {

            continue;

        }

        int temp = abs(elevators->at(theChosenOne)->get_current_floor() - floor); // how far away the elevator

        // is from the requested floor.



        if (temp < difference) {

            theChosenOne = i;

            difference = temp;

        }


        // if idle elvator is as good as another elevator
        // choose the idle elevator

        if ((curDir == IDLE && isIdle == false) && (temp == difference)) {

            theChosenOne = i;

            difference = temp;

            isIdle = true;

        }

    }
    // return chosen elevator
    return theChosenOne;
}

bool isElevatorThere(int floor, int numElevators, std::vector<cs415_elevator*> *elevators) {
    // loop through each elevator
    for (int i = 0; i < numElevators; i++) {
        int curFlr = elevators->at(i)->get_current_floor();
        // if floor = elevator->currentfloor()

        if (floor == curFlr) {

            // return true

            return true;

        }

    }
    // end loop
    return false;

}

int main(int argc, char **argv)
{
    std::vector<cs415_elevator*> *elevators = new std::vector<cs415_elevator*>;
    printer* elvPrinter = new printer();
    int buildingFloors = 0;
    int numElevators = 0;


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

    for (int i = 0; i < numElevators; i++) {
        elevators->at(i)->setMax(buildingFloors);
        std::cout << "Elevator: " << i+1 << " is at floor: " << elevators->at(i)->get_current_floor() << std::endl;
    }
    int inputFloor;
    int direction;
    bool more = true;
    //loop for running elevator, elevator dies when exited.
    while (more) {
        for (int i = 0; i < numElevators; i++) { // we can take this for loop out.
            std::cout << "Elevator at: " << elevators->at(i)->get_current_floor() << std::endl;
        }
        //loop(the do-while one) to get input, elevator does not move until this loop ends
        do {
            //Get input
            std::cout << "Enter floor you are on(-1 to quit)";
            std::cin >> inputFloor;
            if (inputFloor == -1) {
                break;
            }
            if (isElevatorThere(inputFloor, numElevators, elevators)) {
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
            int chosen_elevator = chooseElevator(inputFloor, direction, numElevators, elevators);
            elevators->at(chosen_elevator)->set_req_floor(inputFloor);
            //store input
            elevators->at(chosen_elevator)->call(direction);


        } while ((direction == -1 || direction == 1) &&  inputFloor != -1) ;
        //move elevators
        for (int i = 0; i < numElevators; i++) {
            executeQueue(i, elevators, elvPrinter);
            elvPrinter->printBuilding();
        }

        std::cout << "continue? (y/n): ";
        char cont;
        std::cin >> cont;
        if (cont == 'n' || cont == 'N') {
            for (int i = 0; i < numElevators; i++) {
                std::cout << "Elevator " << i << "'s final resting place is: " << elevators->at(i)->get_current_floor() << std::endl;
            }
            more = false;
        }
        std::cout << "-----------------------------------------------" << std::endl;

    }
    // Free up pointers
    elevators->clear();
    delete elevators;

    return 0;
}


