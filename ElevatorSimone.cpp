#include <iostream>
#include "ElevatorSimone.hpp"
using namespace std;
ElevatorSimone::ElevatorSimone(){
	 idlePosition = (maxHeight + minHeight)/2;
	 currentLevel = idlePosition;
	 currentWeight = 0;
	 currentDirection = 0; // -1: down 0: not moving 1: up	 
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


void upFloor (){
	if (curFloorCheck < floors){
		for (int i =0; i < width; i ++){
			if (i==0)
			{
				building[curFloor][i] = '|';
			}
			for (int y = 1; y < (width -1); y++){
				building[curFloor][y] = ' ';
			}
			building[curFloor][width] = '|';
		}
		curFloor -= 1;
		for (int i =0; i < width; i++){
			if (i==0)
			{
				building[curFloor][i] = '|';
			}
			for (int y = 1; y < (width -1); y++){
				building[curFloor][y] = ' ';
			}
			building[curFloor][width-1] = '|';
		}
		for (int x = 0; x < elevators; x++)
			building[curFloor][(((width) / 2) - x)] = 'X';

	}
	curFloorCheck += 1;
}

void downFloor (){
	if (curFloorCheck < floors){
		for (int i =0; i < width; i ++){
			if (i==0)
			{
				building[curFloor][i] = '|';
			}
			for (int y = 1; y < (width -1); y++){
				building[curFloor][y] = ' ';
			}
			building[curFloor][width] = '|';
		}
		curFloor += 1;
		for (int i =0; i < width; i++){
			if (i==0)
			{
				building[curFloor][i] = '|';
			}
			for (int y = 1; y < (width -1); y++){
				building[curFloor][y] = ' ';
			}
			building[curFloor][width-1] = '|';
		}
		for (int x = 0; x < elevators; x++)
			building[curFloor][(((width) / 2) - x)] = 'X';

	}

curFloorCheck -= 1;
}

void ElevatorSimone::elevatorAlgorithm(int a[]){	//will clobber array

}