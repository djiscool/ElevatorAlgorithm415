#ifndef __CS415_ELEVATOR__
#define __CS415_ELEVATOR__
/***********************
 * CS415 Elevator Class
 *
 ***********************/
#include <iostream>
#include <queue>
#include <unistd.h>
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

    void setMax(int MAX);
    void executeQueue();
    bool minQempty();
    bool maxQempty();
    int get_direction();
	void set_direction(int dirtn);
    int get_minq_top();
    int get_maxq_top();
    void push_maxq(int var);
    void push_minq(int var);
    void pop_minq();
    void pop_maxq();

private:
    struct compare
    {
        bool operator()(const int& l, const int& r)
        {
            return l > r;
        }
    };

    int maxFloors;
    int currentFloor;
    int floorReq;
    int direction;
    bool summoned;
    std::priority_queue<int> maxQueue;
    std::queue<int> floorQueue;
    std::priority_queue<int,std::vector<int>, compare > minQueue;
const int DOWN = -1;
const int IDLE = 0;
const int UP = 1;


};
#endif

