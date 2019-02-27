#include "Planner.hpp"
#include "getopt.h"

/**
 * Main driver for our preciseplanner program.
 * Usage: ./preciseplanner [-apnmh]
 * Parameters:
 *      -a -- allows the user to add new shows to the
 *            planner and its schedule.
 *      -p -- [mn] prints out the schedule, optional flags follow.
 *       m -- [month] follows p, prints out all shows within the current
 *            or specified month.
 *       n -- follows p, prints out the next show in the schedule. 
 *      -h -- displays usage message (help)
 */                   
int main( int argc, char *argv[] ){

    int opt;
    bool print = false;
    bool next = false;
    int month;

    Schedule * ourSchedule = Planner::readSchedule();

    while ((opt = getopt(argc, argv, FLAGS))){
        
    }

}