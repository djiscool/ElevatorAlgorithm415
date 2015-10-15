#include <iostream>
#include "ElevatorSimone.hpp"
using namespace std;
ElevatorSimone::ElevatorSimone(){
	 idlePosition = (maxHeight + minHeight)/2;
	 currentLevel = idlePosition;
	 currentWeight = 0;
	 currentDirection = 0; // -1: down 0: not moving 1: up	 
	 elevators = 0;
	 currentFloorCheck = 0;
}
	 
void ElevatorSimone::input(){
		  
    cout << "How many floors does the building have?: ";
    cin >> floors;
    cout << "Many elevators does the building have?: ";
    cin >> elevators;
    cout << endl;
   
    
   
    createBuilding();
    // print building
    for ( const auto &row : building )
    {
        for ( const auto &s : row ) cout << s << ' ';
        cout << endl;
    }
}
	
void ElevatorSimone::createBuilding ( ){
    // Remember this definition of with is local to the function
    int width = (5 * (elevators/2));
    if (width == 0)
        width = 5;
 
    for (int i = 0; i < floors; i++){
        if (i == 0){
            for (int z = 0; z < width; z++){
                temp.push_back('-');
            }
            building.push_back(temp);
            temp.clear();
        }
        for (int j = 0; j <= floors; j++){
            if (j == 0){
                temp.push_back('|');
                for (int y = 1; y < (width -1); y++){
                    temp.push_back(' ');
                }
                temp.push_back('|');
                building.push_back(temp);
                temp.clear();
            }
        }
    }
    for (int x = 0; x < elevators; x++)
        building[floors][(((width) / 2) - x)] = 'X';
}


void ElevatorSimone::upFloor (){
	if (currentFloorCheck < floors){
		for (int i =0; i < width; i ++){
			if (i==0)
			{
				building[currentLevel][i] = '|';
			}
            
            // Here's the segfault
            // width in private: section of header never initialized
            cout << "Width: " << width << endl;
			for (int y = 1; y < (width -1); y++){
				building[currentLevel][y] = ' ';
			}
			building[currentLevel][width] = '|';
		}
		currentLevel -= 1;
		for (int i =0; i < width; i++){
			if (i==0)
			{
				building[currentLevel][i] = '|';
			}
			for (int y = 1; y < (width -1); y++){
				building[currentLevel][y] = ' ';
			}
			building[currentLevel][width-1] = '|';
		}
		for (int x = 0; x < elevators; x++)
			building[currentLevel][(((width) / 2) - x)] = 'X';

	}
	currentFloorCheck += 1;
}

void ElevatorSimone::downFloor (){
	if (currentFloorCheck < floors){
		for (int i =0; i < width; i ++){
			if (i==0)
			{
				building[currentLevel][i] = '|';
			}
			for (int y = 1; y < (width -1); y++){
				building[currentLevel][y] = ' ';
			}
			building[currentLevel][width] = '|';
		}
		currentLevel += 1;
		for (int i =0; i < width; i++){
			if (i==0)
			{
				building[currentLevel][i] = '|';
			}
			for (int y = 1; y < (width -1); y++){
				building[currentLevel][y] = ' ';
			}
			building[currentLevel][width-1] = '|';
		}
		for (int x = 0; x < elevators; x++)
			building[currentLevel][(((width) / 2) - x)] = 'X';

	}

currentFloorCheck -= 1;
}

void ElevatorSimone::elevatorAlgorithm(int a[]){	//will clobber array

}