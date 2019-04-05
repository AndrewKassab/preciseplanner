#include <iostream>
#include <string>
#include <algorithm>

#include "Planner.hpp"

using namespace std;

/**
* Handles the '-a' parameter where a user is prompted
* to add new shows to the schedule. The user will continue
* being prompted until they decide to quit. 
* TODO: filter out duplicates(?)
*/
void Planner::addShows( Schedule * showSchedule ){

  string response;
  string showName;
  string showMonth;
  string showDay;
  string showYear;

  Show * newShow = new Show();
  
  // TODO: Fix response bugs...
  cout << "Enter show name: ";
  getline(cin,showName);
  newShow->setName(showName);

  do {
    cout << "Enter the month for this show: ";
    cin >> showMonth;
  } while ( !(newShow->setMonth(showMonth)));

  do { 
    cout << "Enter the day for this show: ";
    cin >> showDay;
  } while ( !(newShow->setDay(showDay)) );

  do { 
    cout << "Enter the year for this show (last 2 digits): ";
    cin >> showYear;
  } while ( !(newShow->setYear(showYear)) );

  // date entered has passed
  if ( !dateIsValid( newShow ) ){
    cout << STR_PAST << endl;
    addShows(showSchedule);
    return;
  }

  cout << "The show you are adding is as follows: " << endl;
  newShow->printShow();

  cout << "Add this show? (y/n): ";
  cin >> response;

  if ( response == "y" || response == "Y" || response == "" ){
    showSchedule->add(newShow);
    cout << "Show added!" << endl;
  }
  else{
    cout << "Canceling addition..." << endl;
  }

  response = "";
  cout << "Would you like to continue adding shows? (y/n): ";
  cin >> response;

  // call method again if user wishes to continue
  if (response == "y" || response == "Y" ){
    // clear newline character
    getchar();
    addShows(showSchedule);
    return;
  }

  // sort the schedule by dates and exit the method
  sort(showSchedule->begin(), showSchedule->end(), Show::compareDates );

  Planner::writeSchedule( showSchedule );

  cout << "Finished adding! Exiting... " << endl;

}
