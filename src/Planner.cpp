#include "Planner.hpp"
#include <cstring>
#include <algorithm>

/**
 * Returns the month as an int by examining which 
 * month it is. Assume we pass in a valid month or integer string
 * between 1-12.
 */
unsigned int Planner::monthToInt( string inputMonth ){

  unsigned int monthAsInt = 0;

  if ( inputMonth == "january"){
    monthAsInt = 1; 
  }
  else if ( inputMonth == "february"){
    monthAsInt = 2; 
  }
  else if ( inputMonth == "march"){
    monthAsInt = 3; 
  }
  else if ( inputMonth == "april"){
    monthAsInt = 4; 
  }
  else if ( inputMonth == "may"){
    monthAsInt = 5; 
  }
  else if ( inputMonth == "june"){
    monthAsInt = 6; 
  }
  else if ( inputMonth == "july"){
    monthAsInt = 7; 
  }
  else if ( inputMonth == "august"){
    monthAsInt = 8; 
  }
  else if ( inputMonth == "september"){
    monthAsInt = 9; 
  }
  else if ( inputMonth == "october"){
    monthAsInt = 10; 
  }
  else if ( inputMonth == "november"){
    monthAsInt = 11; 
  }
  else if ( inputMonth == "december"){
    monthAsInt = 12; 
  } else {
    monthAsInt = stoi(inputMonth);
  }

  return monthAsInt;
}

/**
 * Returns the month as an int by examining which 
 * month it is. Assume we pass in a valid month or integer string
 * between 1-12.
 */
 string Planner::monthToString( unsigned int inputMonth ){

  string monthAsString = "";

  switch (inputMonth){
    case 1:
      monthAsString = "January";
      break;
    case 2:
      monthAsString = "February";
      break;
    case 3:
      monthAsString = "March";
      break;
    case 4:
      monthAsString = "April";
      break;
    case 5:
      monthAsString = "May";
      break;
    case 6:
      monthAsString = "June";
      break;
    case 7:
      monthAsString = "July";
      break;
    case 8:
      monthAsString = "August";
      break;
    case 9:
      monthAsString = "September";
      break;
    case 10:
      monthAsString = "October";
      break;
    case 11:
      monthAsString = "November";
      break;
    case 12:
      monthAsString = "December";
      break;
    default:
      cout << "Error, invalid month as integer passed in, exiting..." << endl;
      exit(-1);
  }

  return monthAsString;
}

/**
 * Makes sure a valid month is entered
 *
 * Returns: True if valid , false otherwise
 */
bool Planner::monthIsValid( string inputMonth ){

  int month;

  // User input a month as a string
  if ( inputMonth.length() > 2 ){
    // convert to lowercase
    transform( inputMonth.begin(), inputMonth.end(), inputMonth.begin(), ::tolower);
    string months[12] = {"january","february","march","april","may","june","july",
                            "august", "september", "october", "november", "december" };
    for ( string i : months ){
      if (inputMonth == i ){
        month = monthToInt(inputMonth);
        return true;
      }
    }

    return false;
  } 

  // User input a month as an int 
  try {
    month = stoi(inputMonth);
  // User did not input an integer
  } catch ( invalid_argument& ){
    return false;
  }

  if ( month > 12 || month < 1 ){
    return false;
  }

  return true;

}

/**
 * Checks if a show has a valid date by checking the current time
 * and making sure it is not before that or in the past.
 */
bool Planner::dateIsValid( Show * ourShow ){

  time_t theTime = time(NULL);
  struct tm *currentTime = localtime(&theTime);
  int currentMonth = currentTime->tm_mon+1;
  int currentYear = currentTime->tm_year-100;
  int currentDay = currentTime->tm_mday +1;
  
  if ( ourShow->getYear() < currentYear ){
    return false;
  } 
  else if ( ourShow->getYear() == currentYear){
    if ( ourShow->getMonth() > currentMonth ){
      return true;
    } else if ( ourShow->getMonth() < currentMonth ){
      return false;
    } else {
      if ( ourShow->getDay() < currentDay ){
        return false;
      } else return true;
    }
  } else return true;

}
