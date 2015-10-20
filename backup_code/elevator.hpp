#ifndef ELEVATOR_H
#define ELEVATOR_H

class elevator{
private:
    int capacity;
    int maxWt;
    int isMov;          //0 if not moving, 1 moving down, 2 moving up
    int curLevel;
    int curCount;
    int curWt;
    int max_level;
        
public:
	void create_new_elevator(int , int);
	void move_up();
	void move_down();
	void stop_elv();

};
#endif

