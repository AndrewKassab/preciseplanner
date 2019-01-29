#include <cerrno>
#include <locale>
#include <algorithm>
#include <cstring>
#include "Show.hpp"

#define INVALID_MSG "Invalid input, please try again."
#define MAX_DAYS 31
#define TIME_LENGTH 5
#define COLON ':'
#define BASE 10
#define MAX_HOURS 12
#define MAX_MIN 59
#define MIN_PER_HOUR 60

// default constructor
Show::Show(){}

// paramaterized constructor used when reading in from binary file
Show::Show( string & n, string & m, int & d, int & start, bool & t ){
    name = n;
    month = m;
    day = d;
    startTime = start;
    ticket = t;
}

/**
 * Makes sure the user is sure about the show name they entered
 * 
 * Returns: true if the user responds yes 
 */
bool Show::setName( string & n ){
    string response;
    cout << "Is this correct?: " << n <<  " (y,n): ";
    cin >> response;
    if ( response == "y" || response == "Y" ){
        name = n;
        return true;
    }
    else if ( response == "n" || response == "N" ){
        return false;
    }
    else {
        cout << INVALID_MSG << endl;
        setName( n );
    }
}

/**
 * Makes sure a valid month is entered
 *
 * Returns: True if valid and successful, false otherwise
 */
bool Show::setMonth( string & inputMonth ){
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

/**
 * Makes sure the day is a valid day within range.
 *
 * Returns: True if valid and successful, false otherwise
 */
bool Show::setDay( int & d ){

    if ( !(d <= MAX_DAYS) && !(d >= 0) ){
        cout << INVALID_MSG << endl;
        return false;
    }

    day = d;
    return true;
}

bool Show::setTime( string & time ){
   if ( timeFilter( time ) ){
       return true;
   }
   else return false;
}

/**
 * Makes sure the formatting is correct for the time string 
 * and then converts it accordingly. 
 */
bool Show::timeFilter( string & time ){
   
    // Time isn't formatted correctly because length is incorrect
    if ( time.length() != TIME_LENGTH && time.length() != TIME_LENGTH - 1 ){
        cout << INVALID_MSG << endl;
        return false;
    }

    char * ptr = &(time.at(0));
    unsigned int colonCount = 0;
    
    // Count the amount of colons
    while( *ptr != '\0' ){
        if (*ptr == ':'){
            colonCount++;
        }
        ptr++;
    }
    
    // Time is not formatted correctly
    if (colonCount != 1){
        cout << INVALID_MSG << endl;
        return false;
    }

    ptr = &(time.at(0)); // reset back to beginning

    unsigned int hours;
    float minutes;
    
    // points to the occurance of the colon character
    char* colonPtr = strchr( ptr, COLON );

    // turn the occurance into a null character
    *colonPtr = '\0';

    // convert the first number (hours) to a long
    char * endPtr;
    errno = 0;
    hours = strtol( ptr, &endPtr, BASE);
    
    // 12PM treated as 0
    if ( hours == MAX_HOURS ){
        hours = 0;
    }
    
    /* error checks */
    
    // invalid number / error converting
    if ( errno != 0 || *endPtr != '\0' ){
        cout << INVALID_MSG << endl;
        return false;
    }
    // hours too large
    if ( hours > MAX_HOURS ){
        cout << INVALID_MSG << endl;
        return false;
    }

    ptr = ++colonPtr;

    // converting second number (minutes) to a long
    errno = 0;
    minutes = strtol(ptr, &endPtr, BASE);

    /* error checks */ 

    // invalid number / error converting
    if ( errno != 0 || *endPtr != '\0' ){
        cout << INVALID_MSG << endl;
        return false;
    }
    // minutes too large
    if ( minutes > MAX_MIN ){
        cout << INVALID_MSG << endl;
        return false;
    }
 
    // set start time field 
    minutes = minutes / 60;
    startTime = ( hours + minutes );
    return true;
}

/** TODO: Fix this function, use testTime for help
 * Separates the hours and minutes of startTime, turns
 * them into a string and concatenates them to form a time string
 * of proper format 10:00PM.
 *
 * Returns: The string format for startTime
 */
string Show::timetoString(){

    int tempHours = ( int ) startTime;
    if ( tempHours == 0 ){
        tempHours = 12;
    }
    string hours = to_string(tempHours);

    float tempMinutes = startTime - tempHours;
    tempMinutes = tempMinutes * MIN_PER_HOUR;
    string minutes = to_string(tempMinutes);

    string time = hours + ":" + minutes + "PM";

    return time;

}

/**
 * Determines whether a user has a ticket to an event or not
 * based on their response. Sets ticket boolean appropriately.
 * 
 * Returns: true if the response was valid and the ticket field was
 * successfully set.
 */
bool Show::setTicket( string & response ){
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

// TODO: Overload operator to check if a show comes before another Show
bool Show::operator>(Show * otherShow){

}

