#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Show.hpp"

class Schedule{
private:
    vector<Show*>* schedule;    
    unsigned int isize;
public:
    Schedule();
    ~Schedule();
    Schedule( vector<Show*>* showVector );
    unsigned int size();
    bool empty();
    void add(Show * newShow);
    Show* get(int & index);
    vector<Show*>::iterator begin();
    vector<Show*>::iterator end();

    /**
     * Prints out the entire schedule 
     */
    void printSchedule();

    /**
     * Only prints out shows within that schedule that take place
     * during a given month.
     */
    void printSchedule( int & month );

    /**
     * Prints out the next show on the schedule 
     */
    void printNext();

};



#endif
