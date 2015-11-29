#include "printer.hpp"
    printer::printer()
	{
		
	}
    printer::~printer(){
		
	}


void printer::createBuilding(int floors, int elevator_amount) {
    totalFloors = floors;
    elevators = elevator_amount;
    position_of = new int[elevator_amount]; //array storing the position(in the visual vector) which column elevator is
    // i.e. elevator 1 is position_of[0]
    // Remember this definition of width is local to the function
    width = (5 * (elevators/2));
    if (width == 0) // case for when elevators is 1(the above calculation will return 0)
        width = 5;
	// calculate positions for all elevators
	int middle = (width / 2);
	int deviation = elevators / 2;
	for(int i = 0; i < elevators; i++){
		position_of[i] = (middle - deviation);
		deviation--;
	}

    std::cout << "width initialized to: " << width << std::endl;
    for (int i = 0; i < floors; i++) {
        if (i == 0) {
            for (int z = 0; z < width; z++) {
                temp.push_back('-');
            }
            building.push_back(temp);
            temp.clear();
        }
        for (int j = 0; j <= floors; j++) {
            if (j == 0) {
                temp.push_back('|');
                for (int y = 1; y < (width -1); y++) {
                    temp.push_back(' ');
                }
                temp.push_back('|');
                building.push_back(temp);
                temp.clear();
            }
        }
    }
    for (int x = 0; x < elevators; x++)
        building[1][position_of[x]] = 'X';


}

void printer::upFloor(int whichElevator, int floors, int currentLevel) {

    // calculate position of elevator

    int elevator_number = position_of[whichElevator];
    if (floors == 0 ) {

        // redundant but takes care of our base case, and if floors passed in is 0

        building[currentLevel][elevator_number] = 'X';
        return;
    }

    // Unecessary code(redundant since it was put there in createBuilding)

    /*
    if (currentLevel < Totfloors) {
        for (int i =0; i < width; i ++) {
            if (i==0)
            {

                building[currentLevel][i] = '|';
            }

            //cout << "Width: " << width << endl;
            for (int y = 1; y < (width -1); y++) {
                building[currentLevel][y] = ' ';
            }
            building[currentLevel][width] = '|';
        }
        for (int i =0; i < width; i++) {
            if (i==0)
            {
                building[currentLevel][i] = '|';
            }
            for (int y = 1; y < (width -1); y++) {
                building[currentLevel][y] = ' ';
            }
            building[currentLevel][width-1] = '|';
        }

    	*/



    // change elevator position
    building[currentLevel][elevator_number] = ' ';

    building[currentLevel+1][elevator_number] = 'X';


    //std::cout << "currentLevel: " << currentLevel << endl;

    // I wrote it this way, so that if we want we can print out the building each iteration of this loop

    // printBuilding();
	upFloor(whichElevator, floors -1, currentLevel+1);
}





void printer::downFloor (int whichElevator, int floors, int currentLevel) {
    // calculate position of elevator

    int elevator_number = position_of[whichElevator];

    if (floors == 0 ) {

        // redundant but takes care of our base case, and case where inital floors is 0

        building[currentLevel][elevator_number] = 'X';

        return;

    }


    // change elevator position

    building[currentLevel][elevator_number] = ' ';

    building[currentLevel+1][elevator_number] = 'X';


//std::cout << "currentLevel: " << currentLevel << endl;

// I wrote it this way, so that if we want we can print out the building each iteration of this loop

// printBuilding();

downFloor(whichElevator, floors -1, currentLevel-1);
}


void printer::printBuilding() { //prints upside down (needs fix)
for ( const auto &row : building )
    {
for ( const auto &s : row ) std::cout << s << ' ';
        std::cout << std::endl;
    }

}