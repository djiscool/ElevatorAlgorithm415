#ifndef __CS415_ELEVATOR__
#define __CS415_ELEVATOR__
/***********************
 * CS415 Elevator Class
 *
 ***********************/
#include <iostream>

class cs415_elevator
{
	public:
		//  Constructor & Desconstructor
		cs415_elevator();
		~cs415_elevator();

		void call();
		void move_up();
		void move_down();

		int get_current_floor();
		void set_current_floor(int floor);

		int get_floor_req();
		void set_floor_req(int floor);

	private:
		int currentFloor;
		int floorReq;
};

#endif
