class ElevatorSimone {
     ElevatorSimone::ElevatorSimone(){
	 idlePosition = (maxHeight + minHeight)/2;
	 currentLevel = idlePosition;
	 currentWeight = 0;
	 currentDirection = 0; // -1: down 0: not moving 1: up	 
	 }
  public:
	int currentLevel, currentDirection;
	
    int runElevator(){
		input();
		elevatorAlgorithm();
		
	}
	int stopElevator(){
		
	}
	
	void createBuilding ( int floors, int elevators, vector<vector<char>>& building, vector<char>& temp );
	
	private:
	int floors, elevators;
	vector<char> temp;
    vector<vector <char>> building;
	int currentWeight, maxHeight, minHeight, idlePosition;
	queue floorsPressed;
	int[] elevatorAlgorithm(int[] a);
	int[] input();	
	
};