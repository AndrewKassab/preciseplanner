#include <iostream>
#include <string>
#include <algorithm>

#include "Planner.hpp"

using namespace std;

/**
 * Handles the '-a' parameter where a user is prompted
 * to add new shows to the schedule. The user will continue
 * being prompted until they decide to quit. 
 * TODO: Filter out duplicates 
 */
void Planner::addShows( Schedule * showSchedule ){

    string response;
    string showName;
    string showMonth;
    string showDay;
    string showTime;

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
        cout << "Enter the date for this show: ";
        cin >> showDay;
    } while ( !(newShow->setDay(showDay)) );

    cout << "The show you are adding is as follows: " << endl;
    newShow->printShow();

    cout << "Add this show? (y/n): ";
    cin >> response;

    // Make sure user wants to add the show as inputted
    if ( response == "y" || response == "Y" ){
        showSchedule->add(newShow);
        cout << "Show added!" << endl;
    }
    else{
        cout << "Canceling addition..." << endl;
    }

    // prompt user if they want to continue adding shows
    response = "";
    cout << "Would you like to continue adding shows? (y/n): ";
    cin >> response;

    // call method again if user wishes to continue
    if (response == "y" || response == "Y"){
        // clear newline character
        getchar();
        addShows(showSchedule);
        return;
    }

    // sort the schedule by dates and exit the method
    sort(showSchedule->begin(), showSchedule->end(), Show::compareDates );

    ofstream outputFile;
    outputFile.open("data/schedule.txt", ios::binary);

    // output schedule into file
    for ( int i = 0; i < showSchedule->size(); i++){
        Show currentShow = *(showSchedule->get(i));
        outputFile << currentShow.getName() << "\n";
        outputFile << currentShow.getMonth() << "\n";
        outputFile << currentShow.getDay() << "\n";
    }

    outputFile << "\n";

    // free memory
    outputFile.close();

    cout << "Finished adding! Exiting... " << endl;

}