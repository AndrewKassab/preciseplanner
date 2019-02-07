#ifndef PLANNER_HPP
#define PLANNER_HPP

#include <iostream>
#include "Show.hpp"
#include "Schedule.hpp"

#define FILE_PATH "data/schedule.txt"

// TODO: Add more functionalities
class Planner{
public:

    /**
     * Adds shows to our schedule
     */
    static void addShows( Schedule * showSchedule);

    /**
     * Reads in our schedule from a file.
     */
    static Schedule * readSchedule();
};

#endif