#ifndef __CS415_ELEVATOR__
#define __CS415_ELEVATOR__
/***********************
 * CS415 Elevator Class
 *
 ***********************/
#include <iostream>
#include <queue>
class cs415_elevator
{
	public:
		//  Constructor & Desconstructor
		cs415_elevator();
		~cs415_elevator();

		void call(int direction);
		void move_up();
		void move_down();

		int get_current_floor();
		void set_current_floor(int floor);

		int get_req_floor();
		void set_req_floor(int floor);


	private:
		int currentFloor;
		int floorReq;
		int direction;
        	bool summoned;
		std::queue<int> floorQueue;
        	enum direction { DOWN = -1, IDLE = 0, UP = 1 };
};

#endif
