#include "Planner.hpp"
#include <cerrno>
#include <locale>
#include <algorithm>
#include <cstring>

#define MAX_DAYS 31
#define BASE 10

Show::Show(){}

Show::Show( string n, unsigned int m, unsigned int d, unsigned int y){
  name = n;
  month = m;
  day = d;
  year = y;
}

void Show::setName( string n ){
  name = n;
}

string Show::getName(){
  return name;
}

/**
 * Makes sure a valid month is entered
 *
 * Returns: True if valid and successful, false otherwise
 */
bool Show::setMonth( string inputMonth ){

  // User input a month as a string
  if ( inputMonth.length() > 2 ){
    // convert to lowercase
    transform( inputMonth.begin(), inputMonth.end(), inputMonth.begin(), ::tolower);
    string months[12] = {"january","february","march","april","may","june","july",
                            "august", "september", "october", "november", "december" };
    for ( string i : months ){
      if (inputMonth == i ){
        month = Planner::monthToInt(inputMonth);
        return true;
      }
    }

    cout << INVALID_INPUT << endl;
    return false;
  } 

  // User input a month as an int 
  try {
    month = stoi(inputMonth);
  // User did not input an integer
  } catch ( invalid_argument& ){
    cout << INVALID_INPUT << endl;
    return false;
  }

  if ( month > 12 || month < 1 ){
    cout << INVALID_INPUT << endl;
    return false;
  }

  return true;

}

unsigned int Show::getMonth(){
  return month;
}

/**
 * Makes sure the day is a valid day within range.
 *
 * Returns: True if valid and successful, false otherwise
 */
bool Show::setDay( string d ){

  try {
    day = stoi(d);
  } catch ( invalid_argument& ){
    cout << INVALID_INPUT << endl;
    return false;
  }

  if ( (day >= MAX_DAYS) || (day == 0) ){
    cout << INVALID_INPUT << endl;
    day = 0;
    return false;
  }

  /**
   * TODO: Add month edge cases, for example if the month
   * is February (2), then the day cannot be 31 
   */

  return true;
}

unsigned int Show::getDay(){
  return day;
}

bool Show::setYear( string y ){

  time_t theTime = time(NULL);
  struct tm *currentTime = localtime(&theTime);
  unsigned int currentYear = currentTime->tm_year - 100;

  try {
    year = stoi(y);
  } catch ( invalid_argument& ){
    cout << INVALID_INPUT << endl;
    return false;
  }

  // past event 
  if ( (year < currentYear) ){
    cout << INVALID_INPUT << endl;
    year = 0;
    return false;
  }

  return true;

}

unsigned int Show::getYear(){
  return year;
}

/**
 * Checks if a show comes before another show by 
 * comparing their months and dates.
 * 
 * Returns: true if firstShow comes first or is on the same day
 * 
 */
bool Show::compareDates(Show * firstShow, Show * secondShow){
  if ( firstShow->getYear() < secondShow->getYear() ){
    return true;
  }
  else if (firstShow->getMonth() < secondShow->getMonth()){
    return true;
  }
  else if (firstShow->getMonth() == secondShow->getMonth()){
    if ( firstShow->getDay() <= secondShow->getDay() ){
      return true;
    }
    else return false;
  }
  else return false;
}

/**
 * Print a show and its contents to the screen. Lines
 * up values properly.
 */ 
void Show::printShow(){
  if ( day < 10 ){
    if ( month < 10 ){
      cout << "0" << month << "-0" << day << "-" << year << ": " << name << endl;
    }
    else {
      cout << month << "-0" << day << "-" << year << ": " << name << endl;
    }
  } else {
    if ( month < 10 ){
      cout << "0" << month << "-" << day << "-" << year << ": " << name << endl;
    }
    else {
      cout << month << "-" << day << "-" << year << ": " << name << endl;
    }
  }
}

/**
 * TODO: Print the show + other important information
 */
void Show::printAll(){
}