#include "Planner.hpp"
#include "getopt.h"

/**
 * Main driver for our preciseplanner program.
 * Usage: ./preciseplanner [-apnmh]
 * Parameters:
 *      -a -- allows the user to add new shows to the
 *            planner and its schedule.
 *      -p -- [mn] prints out the schedule, optional flags follow.
 *       m -- [month (as number)] follows p, prints out all shows within the current
 *            or specified month.
 *       n -- follows p, prints out the next show in the schedule. 
 *      -h -- displays usage message (help)
 * 
 * TODO: Complete
 */                   
int main( int argc, char *argv[] ){

    int opt;
    bool print = false;
    bool add = false;
    bool next = false;

    //while ((opt = getopt(argc, argv, FLAGS))){

    opt = getopt(argc, argv, FLAGS);
    switch( opt ){
        case ADD_FLAG:
            add = true;
            break;
        case PRINT_FLAG:
            print = true;
            break;
        case NEXT_FLAG:
            next = true;
            break;
        case HELP_FLAG:
            cout << STR_USAGE;
            return EXIT_SUCCESS;
        // Invalid flags 
        case UNKNOWN_FLAG:
            cerr << STR_USAGE;
            return EXIT_FAILURE;
    }

    Schedule * ourSchedule = Planner::readSchedule();
    
    // Add shows functionality
    if ( add ){
        if ( optind != argc ){
            cerr << STR_EXTRA_ARG;
            cerr << STR_USAGE;
            return EXIT_FAILURE;
        }
        
        Planner::addShows(ourSchedule);
        return EXIT_SUCCESS;
    }

    // Print the next show
    if ( next ){
        // TODO: call printNext()
        return EXIT_SUCCESS;
    }

    // no functionality edge case  
    if ( !print ){
        cerr << STR_USAGE;
        return EXIT_FAILURE;
    }

    // TODO: Set month to current time 
    string month;
    bool printMonth = false;
    
    // if p is followed by m, print only for a specific month
    if ( (opt = getopt(argc, argv, PRINT_FLAGS) == MONTH_FLAG ) ){
        printMonth = true; 
        // if there is a month argument, print shows in that month
        if ( optarg ){
            month = optarg;
        }
    }
    
    if ( optind != argc ){
        cerr << STR_EXTRA_ARG;
        cerr << STR_USAGE;
        return EXIT_FAILURE;
    }

    if ( !Planner::monthIsValid(month)){
        cerr << INVALID_MONTH << endl;
        return EXIT_FAILURE;
    }

    //unsigned int monthInt = Planner::monthToInt(month);

    if ( printMonth ){
        // TODO: call ourSchedule->printSchedule( monthInt )
    }

    ourSchedule->printSchedule();
    
    return EXIT_SUCCESS;

}