#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Show.hpp"

class Schedule{
private:
    vector<Show*>* schedule;    
    unsigned int isize;
public:
    Schedule();
    ~Schedule();
    Schedule( vector<Show*>* showVector );
    void add(Show * newShow);

    /**
     * Prints out the entire schedule, using
     * the toString() method of each Show.
     */
    void printSchedule();

    /**
     * Only prints out shows within that schedule that take place
     * during a given month.
     */
    void printSchedule( string & month );
};



#endif