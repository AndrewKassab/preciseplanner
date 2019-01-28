#include <iostream>
#include <string>

#include "Planner.hpp"

using namespace std;

/**
 * Handles the '-a' parameter where a user is prompted
 * to add new shows to the show database. The user will continue
 * being prompted until they decide to quit.
 */
void Planner::addShows(){

    string response;
    string showName;
    string showMonth;
    int showDay;
    string showTime;
    bool hasTicket;

    do {

        Show * newShow = new Show();
        
        do {
            cout << "Enter show name: ";
            cin >> showName;
        } while ( !(newShow->setName(showName)) );

        do {
            cout << "Enter the month for this show: ";
            cin >> showMonth;
        } while ( !(newShow->setMonth(showMonth)));


    } while ( response == "y" || response == "Y" );
}