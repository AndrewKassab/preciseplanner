#include "Planner.hpp"
#include "getopt.h"

/**
 * Main driver for our preciseplanner program.
 * Usage: ./preciseplanner [-apnmh]
 * Parameters:
 *      -a -- allows the user to add new shows to the
 *            planner and its schedule.
 *      -p -- prints out the entire schedule
 *      -m -- [month] prints out all shows within the current or specified month.
 *      -n -- prints out the next show in the schedule. 
 *      -h -- displays usage message (help)
 */                   
int main( int argc, char *argv[] ){

  int opt;
  bool print = false;
  bool printMonth = false;
  bool add = false;
  bool next = false;
  char * month; // TODO: set to current system month

  opt = getopt(argc, argv, FLAGS);
  
  if ( opt == -1 ){
    cout << STR_USAGE;
    return EXIT_FAILURE;
  }

  // parse our flag
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
    case MONTH_FLAG:
      printMonth = true;
      break;
    case HELP_FLAG:
      cout << STR_USAGE;
      return EXIT_SUCCESS;
    case UNKNOWN_FLAG:
      cerr << STR_USAGE;
      return EXIT_FAILURE;
  }

  cout << month << endl;

  // there are still more arguments 
  if ( optind != argc ){
    cerr << STR_EXTRA_ARG;
    cerr << STR_USAGE;
    return EXIT_FAILURE;
  }

  Schedule * ourSchedule = Planner::readSchedule();

  // Add shows functionality
  if ( add ){
    Planner::addShows(ourSchedule);
    // TODO: delete ourSchedule;
    return EXIT_SUCCESS;
  }

  // Print the next show
  if ( next ){
    ourSchedule->printNext();
    // TODO: delete ourSchedule;
    return EXIT_SUCCESS;
  }

  if ( print ){
    ourSchedule->printSchedule();
    // TODO: delete ourSchedule;
    return EXIT_SUCCESS;
  }

  if ( printMonth ){
    if ( !Planner::monthIsValid(month) ){
      cerr << INVALID_MONTH << endl;
      return EXIT_FAILURE;
    }
    int monthAsInt = Planner::monthToInt(month);
    ourSchedule->printSchedule(monthAsInt);
  } 

  // TODO: delete ourSchedule;
  return EXIT_SUCCESS;

}