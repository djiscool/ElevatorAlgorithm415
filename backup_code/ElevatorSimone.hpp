#include <vector>
#include "elevator.hpp"

using namespace std;

class ElevatorSimone {
  public:
	ElevatorSimone();
	void input();
 	void runElevator(){
		input();
		//elevatorAlgorithm();
		
	}
	void stopElevator(){
		
	}
	void downFloor ();
	void upFloor ();
	
	
	
  private:
	int floors, elevators, width;
    	int currentLevel, currentDirection;
    	elevator *elevator1;
	vector<char> temp;
    	vector<vector <char> > building;
	
    	int currentWeight, maxHeight, minHeight, idlePosition;
	int currentFloorCheck;
	
    //queue floorsPressed;
	
	void updatePrintVector(int direction){ // 0 for up 1 for down
    	void createBuilding ( );
	void elevatorAlgorithm(int a[]);	//will clobber array
	
};
