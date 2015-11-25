#ifndef __PRINTER__
#define __PRINTER__
/***********************
 * Class managing the visual representation of a building.
 *
 ***********************/
#include <iostream>
#include <vector>

class printer
{
public:
//  Constructor & Desconstructor
    printer();
    ~printer();

void createBuilding (int floors, int elevator_amount); //essentially the constructor...
void upFloor (int whichElevator, int floors, int currentLevel); // doesn't check for bounds
void downFloor (int whichElevator, int floors, int currentLevel); //doesn't check for bounds

void printBuilding(); //couts the building

private: 
int elevators;
int totalFloors;
int width;
int* position_of;
std::vector<std::vector <char> > building;
std::vector<char> temp;

};
#endif