#include "Planner.hpp"
#include <cstring>
#include <algorithm>

/**
 * Returns the month as an int by examining which 
 * month it is. Assume we pass in a valid month or integer string
 * between 1-12.
 * 
 * TODO: Pass in the system time, check the month, and adjust
 * the int value accordingly by adding 12 if it is the next year 
 * from now, so that if we are march, and a show is next year's january, 
 * it doesn't appear to come before one in the rest of the year.
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
 * 
 * TODO: Pass in the system time, check the month, and adjust
 * the int value accordingly by adding 12 if it is the next year 
 * from now, so that if we are march, and a show is next year's january, 
 * it doesn't appear to come before one in the rest of the year.
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
