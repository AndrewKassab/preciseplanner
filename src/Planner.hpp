#ifndef PLANNER_HPP
#define PLANNER_HPP

#include <iostream>
#include "Show.hpp"
#include "Schedule.hpp"

#define FILE_PATH "/home/precisemotion/Documents/workspace/cpp/preciseplanner/data/schedule.txt"

#define FLAGS "apnhm"

#define ADD_FLAG 'a'
#define PRINT_FLAG 'p'
#define NEXT_FLAG 'n'
#define HELP_FLAG 'h'
#define MONTH_FLAG 'm'
#define UNKNOWN_FLAG '?'

#define INVALID_MONTH "Invalid month input specified, exiting..."

#define STR_USAGE \
"Usage: planner [-apnmh]\n"\
"   -a \t begin adding new shows to schedule\n"\
"   -p \t prints out the entire schedule of shows\n"\
"   -m \t [month] prints out shows only\n"\
"      \t in the current or specified month\n"\
"   -n \t prints out the next show\n"\
"   -h \t help, displays usage information\n"

#define STR_EXTRA_ARG "Invalid, extra arguments detected\n"

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

  /**
   * Converts a string representation of a month to a number
   */
  static unsigned int monthToInt( string inputMonth );

  /**
   * Converts an int representation of a month to a string 
   */
  static string monthToString( unsigned int inputMonth );

  /**
   * Checks if a month input is valid 
   */
  static bool monthIsValid( string inputMonth );

};

#endif