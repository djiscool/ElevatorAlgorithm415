#include <vector>
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
    
	vector<char> temp;
    vector<vector <char> > building;
	
    int currentWeight, maxHeight, minHeight, idlePosition;
	int currentFloorCheck;
	
    //queue floorsPressed;
	
    void createBuilding ( );
	void elevatorAlgorithm(int a[]);	//will clobber array
	
};