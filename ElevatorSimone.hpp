#include <vector>
using namespace std;
class ElevatorSimone {
  public:
	ElevatorSimone();
	int currentLevel, currentDirection;
	void input();
    int runElevator(){
		input();
		//elevatorAlgorithm();
		
	}
	int stopElevator(){
		
	}
	void downFloor ();
	void upFloor ();
	
	
	
	private:
	int floors, elevators, width;
	vector<char> temp;
    vector<vector <char> > building;
	int currentWeight, maxHeight, minHeight, idlePosition;
	int currentFloorCheck;
	//queue floorsPressed;
	void createBuilding ( );
	void elevatorAlgorithm(int a[]);	//will clobber array
	
};