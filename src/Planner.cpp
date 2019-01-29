#include <iostream>
#include <string>

#include "Planner.hpp"

using namespace std;

/**
 * Handles the '-a' parameter where a user is prompted
 * to add new shows to the show database. The user will continue
 * being prompted until they decide to quit.
 * TODO: Finish method 
 */
void Planner::addShows( Schedule * showSchedule ){

    string response;
    string showName;
    string showMonth;
    int showDay;
    string showTime;
    bool hasTicket;

    // loop as long as user wishes to continue adding shows
    do {

        Show * newShow = new Show();
        
        do {
            cout << "Enter show name: ";
            getline(cin,showName);
        } while ( !(newShow->setName(showName)) );

        do {
            cout << "Enter the month for this show: ";
            cin >> showMonth;
        } while ( !(newShow->setMonth(showMonth)));

        // TODO: make sure user enters an int 
        do { 
            cout << "Enter the date for this show: ";
            cin >> showDay;
        } while ( !(newShow->setDay(showDay)) );

        do {
            cout << "Enter the start time of this show in the format (8:00): ";
            cin >> showTime;
        } while ( !(newShow->setTime(showTime)) );

        do {
            cout << "Do you have a ticket to this event? (y/n): ";
            cin >> response;
        } while ( !(newShow->setTicket(response)) );

        response = " ";

        // Ask user if they are sure
        // if they are sure
            // showSchedule.add( newShow );
            // show had been added
        // else
            // don't add show
            // please try again...

        // prompt user if they want to continue adding shows

    } while ( response == "y" || response == "Y" );
}