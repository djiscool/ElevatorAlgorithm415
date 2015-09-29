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
	
	private:
	int currentWeight, maxHeight, minHeight, idlePosition;
	queue floorsPressed;
	int[] elevatorAlgorithm(int[] a);
	int[] input();	
	
};