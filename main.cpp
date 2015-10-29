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
    
    //Get Input
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
    elevators->at(0)->setMax(buildingFloors);
    for(int i = 0; i < numElevators; i++) {
        std::cout << "Elevator: " << i+1 << " is at floor: " << elevators->at(i)->get_current_floor() << std::endl;
    }
    int inputFloor;
    int direction;
    bool more = true;
    //loop for running elevator, elevator dies when exited.
    while(more){
        std::cout << "Elevator at: " << elevators->at(0)->get_current_floor() << std::endl;
        //loop(the do-while one) to get input, elevator does not move until this loop ends
        do{
            //Get input
            std::cout << "Enter floor you are on(-1 to quit)";
            std::cin >> inputFloor;
            if(inputFloor == -1){
                break;
            }
            if(inputFloor == elevators->at(0)->get_current_floor()){
                std::cout << "Elevator already there!" << std::endl;
                continue;
            }
            std::cout << "Enter desired direction (1:UP, 2:DOWN)";
            std::cin >> direction;
            if(direction == -1)
                break;
            if(inputFloor < 0 || inputFloor > buildingFloors){
                std::cout << "invalid floor, not a floor!" << std::endl;;
                break;
            }
            
            //parse input
            if(direction == 1)
                direction = UP;
            if(direction == 2)
                direction = DOWN;
            elevators->at(0)->set_req_floor(inputFloor);
            //store input
            elevators->at(0)->call(direction);
            
            
        }while((direction == -1 || direction == 1) &&  inputFloor != -1) ;
        //move elevator
        elevators->at(0)->executeQueue();
        
        std::cout << "continue? (y/n): ";
        char cont;
        std::cin >> cont;
        if(cont == 'n' || cont == 'N'){
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

