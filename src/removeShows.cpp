#include "Planner.hpp"

/**
 * Prompts the user to pick shows from the schedule
 * to remove and updates the schedule accordingly.
 */
void Planner::removeShows( Schedule * showSchedule ){

  string input = "";
  string response = "";
  int index;

  while ( 1 ){
    showSchedule->printSchedule();
    cout << "Input index of show to remove (or 0 to quit): ";
    cin >> input;
    try {
      index = stoi(input);
    } catch ( invalid_argument& ){
      cout << INVALID_INPUT << endl;
      continue;
    }
    if ( index == 0 ) {
      cout << "Exiting..." << endl;
      break;
    }
    else if ( index >= showSchedule->size() ){
      cout << INVALID_INPUT << endl;
      continue;
    }    

    index--; 
    showSchedule->get(index)->printShow();
    cout << "Are you sure you want to remove this show? (y/n): ";
    cin >> response;

    if ( response == "Y" || response == "y" ){
      showSchedule->remove(index);
      cout << "Show successfully removed. Continue? (y/n): ";
      cin >> response;
      if ( response == "Y" || response == "y" ){
        continue;
      } else break;
    } else {
      cout << "Removal canceled, exiting..." << endl;
      break;
    }

  }

  Planner::writeSchedule( showSchedule );

}