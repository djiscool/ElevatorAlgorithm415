/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : elevator.c

* Purpose : Software Engineering Assignment 

* Creation Date : 09-02-2013

* Last Modified : Friday 22 March 2013 04:16:23 PM IST

* Created By : npsabari
 
 
* Changed by DJ Scott and converted to cpp 10/15/2015

_._._._._._._._._._._._._._._._._._._._._.*/

#include "elevator.hpp"

using namespace std;

elevator::elevator(){

    curLevel = 0;
    isMov = 0;
    curCount = 0;
    curWt = 0;
}


void elevator::create_new_elevator(int _capacity, int _maxwt, int _max_level){
    	capacity = _capacity;
    	maxWt = _maxwt;
	MAXLEVEL = _max_level;
}

void elevator::move_up(){
    if(curLevel < MAXLEVEL){
        curLevel += 1;
        isMov = 2;
    }
    else{
        curLevel = 7;
        isMov = 1;
    }
}

void elevator::move_down(){
    if(curLevel > 0){
        curLevel -= 1;
        isMov = 1;
    }
    else{
        curLevel = 0;
        isMov = 2;
    }
}

void elevator::stop_elv(){
    if(isMov != 0){
        isMov = 0;
    }
}


