#include <cerrno>
#include <locale>
#include <algorithm>
#include <cstring>
#include "Show.hpp"

#define INVALID_MSG "Invalid input, please try again."
#define MAX_DAYS 31
#define BASE 10

// default constructor
Show::Show(){}

// paramaterized constructor used when reading in from binary file
Show::Show( string n, string m, int d, bool t ){
    name = n;
    month = m;
    day = d;
    ticket = t;
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
 * TODO: Adjust to accept numbers as valid input ( 1 - 12 ), 
 * change to store the month as an integer instead.
 */
bool Show::setMonth( string inputMonth ){

    // convert to lowercase
    transform( inputMonth.begin(), inputMonth.end(), inputMonth.begin(), ::tolower);
    string months[12] = {"january","february","march","april","may","june","july",
                            "august", "september", "october", "november", "december" };
    for ( string i : months ){
        if (inputMonth == i ){
            month = inputMonth;
            return true;
        }
    }
    
    cout << INVALID_MSG  << endl;
    return false;

}

string Show::getMonth(){
    return month;
}

/**
 * Makes sure the day is a valid day within range.
 *
 * Returns: True if valid and successful, false otherwise
 */
bool Show::setDay( int d ){

    if ( !(d <= MAX_DAYS) && !(d >= 0) ){
        cout << INVALID_MSG << endl;
        return false;
    }

    day = d;
    return true;
}

unsigned int Show::getDay(){
    return day;
}

/**
 * Determines whether a user has a ticket to an event or not
 * based on their response. Sets ticket boolean appropriately.
 * 
 * Returns: true if the response was valid and the ticket field was
 * successfully set.
 */
bool Show::setTicket( string response ){
    if ( response == "y" || response == "Y" ){
        ticket = true;
        return true;
    }
    else if (response == "n" || response == "N" ){
        ticket = false;
        return true;
    }
    else {
        return false;
    }
}

bool Show::hasTicket(){
    return ticket;
}

/**
 * Checks if a show comes before another show by 
 * comparing their months and dates.
 * 
 * Returns: true if firstShow comes first or is on the same day
 * 
 */
bool Show::compareDates(Show * firstShow, Show * secondShow){
    if (firstShow->monthToInt() < secondShow->monthToInt()){
        return true;
    }
    else if (firstShow->monthToInt() == secondShow->monthToInt()){
        if ( firstShow->getDay() <= secondShow->getDay() ){
            return true;
        }
        else return false;
    }
    else return false;
}

/**
 * Returns the month as an int by examining which 
 * month it is.
 * 
 * TODO: Pass in the system time, check the month, and adjust
 * the int value accordingly by adding 12 if it is the next year 
 * from now, so that if we are march, and a show is next year's january, 
 * it doesn't appear to come before one in the rest of the year.
 */
unsigned int Show::monthToInt(){
    unsigned int monthAsInt = 0;
    if ( month == "january"){
        monthAsInt = 1; 
    }
    else if ( month == "february"){
        monthAsInt = 2; 
    }
    else if ( month == "march"){
        monthAsInt = 3; 
    }
    else if ( month == "april"){
        monthAsInt = 4; 
    }
    else if ( month == "may"){
        monthAsInt = 5; 
    }
    else if ( month == "june"){
        monthAsInt = 6; 
    }
    else if ( month == "july"){
        monthAsInt = 7; 
    }
    else if ( month == "august"){
        monthAsInt = 8; 
    }
    else if ( month == "september"){
        monthAsInt = 9; 
    }
    else if ( month == "october"){
        monthAsInt = 10; 
    }
    else if ( month == "november"){
        monthAsInt = 11; 
    }
    else if ( month == "december"){
        monthAsInt = 12; 
    }

    return monthAsInt;
}

/**
 * Print a show and its contents to the screen. Lines
 * up values properly.
 */ 
void Show::printShow(){
    if ( day < 10 ){
        if ( monthToInt() < 10 ){
            cout << "0" << monthToInt() << "-0" << day << ": " << name << endl;
        }
        else {
            cout << monthToInt() << "-0" << day << ": " << name << endl;
        }
    } else {
        if ( monthToInt() < 10 ){
            cout << "0" << monthToInt() << "-" << day << ": " << name << endl;
        }
        else {
            cout << monthToInt() << "-" << day << ": " << name << endl;
        }
    }
}

/**
 * TODO: Print the show + other important information
 */
void Show::printAll(){

}