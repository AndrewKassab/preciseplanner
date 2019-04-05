#ifndef PLANNER_HPP
#define PLANNER_HPP

#include <iostream>
#include <time.h>
#include "Show.hpp"
#include "Schedule.hpp"

#define SCH_FILE_PATH "/etc/pschedule.txt"
#define ARCH_FILE_PATH "/etc/parchive.txt"

#define FLAGS "arpnhm"

#define ADD_FLAG 'a'
#define REMOVE_FLAG 'r'
#define PRINT_FLAG 'p'
#define NEXT_FLAG 'n'
#define HELP_FLAG 'h'
#define MONTH_FLAG 'm'
#define UNKNOWN_FLAG '?'

#define INVALID_MONTH "Invalid month input specified, exiting..."
#define INVALID_INPUT "Invalid date entered, date has passed."

#define STR_USAGE \
"Usage: planner [-arpnmh]\n"\
"   -a \t begin adding new shows to schedule\n"\
"   -r \t remove shows from the schedule\n"\
"   -p \t prints out the entire schedule of shows\n"\
"   -m \t [month] prints out shows only\n"\
"      \t in the current or specified month\n"\
"   -n \t prints out the next show\n"\
"   -h \t help, displays usage information\n"

#define STR_EXTRA_ARG "Invalid, extra arguments detected\n"
#define STR_NO_SHOWS "No shows present"
#define STR_PAST "Invalid input, past date entered."

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
   * Writes the schedule to the schedule file
   */
  static void writeSchedule( Schedule * showSchedule );

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

  /**
   * Prompts user to remove shows from the schedule
   */
  static void removeShows( Schedule * showSchedule );
  
  /**
   * Checks if a show has a valid date, ie. it isn't in the past.
   */
  static bool dateIsValid( Show * ourShow );

};

#endif