#ifndef PLANNER_HPP
#define PLANNER_HPP

#include <iostream>
#include "Show.hpp"
#include "Schedule.hpp"

#define FILE_PATH "data/schedule.txt"
#define FLAGS "apmnh"

#define STR_USAGE \
"Usage: planner [-apnmh]\n"\
"   -a \t begin adding new shows to schedule\n"\
"   -p \t prints out the entire schedule of shows\n"\
"   -m \t [month] following 'p', prints out shows only\n"\
"      \t in current or specified month\n"\
"   -n \t prints out the next show\n"\
"   -h \t help, displays usage information\n"

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