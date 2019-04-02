#include <ctime>
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

  // there are still more arguments 
  if ( !printMonth && optind != argc ){
    cerr << STR_EXTRA_ARG;
    cerr << STR_USAGE;
    return EXIT_FAILURE;
  }

  Schedule * ourSchedule = Planner::readSchedule();

  // Add shows functionality
  if ( add ){
    Planner::addShows(ourSchedule);
    delete ourSchedule;
    return EXIT_SUCCESS;
  }

  // Print the next show
  if ( next ){
    ourSchedule->printNext();
    delete ourSchedule;
    return EXIT_SUCCESS;
  }

  if ( print ){
    ourSchedule->printSchedule();
    delete ourSchedule;
    return EXIT_SUCCESS;
  }

  if ( printMonth ){

    string month = "";
    int monthAsInt = 0;

    if ( argc == 3 ){
      month = argv[2];
      if ( !Planner::monthIsValid(month) ){
        cerr << INVALID_MONTH << endl;
        delete ourSchedule;
        return EXIT_FAILURE;
      } else {
        monthAsInt = Planner::monthToInt(month);
      }
    } 
    else if ( argc > 3 ){
      cerr << STR_EXTRA_ARG;
      cerr << STR_USAGE;
      delete ourSchedule;
      return EXIT_FAILURE;
    } 
    else {
      time_t theTime = time(NULL);
      struct tm *aTime = localtime(&theTime);
      monthAsInt = aTime->tm_mon + 1;
    }

    ourSchedule->printSchedule(monthAsInt);
  } 

  delete ourSchedule;
  return EXIT_SUCCESS;

}