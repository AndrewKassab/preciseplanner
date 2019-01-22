#ifndef MUSICPLANNER_SHOW_H
#define MUSICPLANNER_SHOW_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Show{

private:
    string name;
    string month;
    unsigned int day;
    float startTime; // 0 - 11
    bool ticket;

public:
    Show();
    Show( string n, string m, int d, int start, bool t );
    string getName();
    bool setName( string n );
    string getMonth();
    bool setMonth( string m );
    unsigned int getDay();
    bool setDay( int d ); 
    float getTime();
    bool setTime( string t );

    /**
     * Helper method for setTime, filters a time in the form of
     * a string and turns it into a float representation.
     *
     * Returns: true if the transformation was successful, false otherwise
     */
    bool timeFilter( string t );

    /**
     * Turns startTime into a string representation.
     *
     * Returns: string version of startTime
     */
    string timetoString();

    /**
     * Returns: true if the user has a ticket to the event.
     */
    bool hasTicket();
    
    /**
     * Compares the time of a show to the time of another show. 
     *
     * Returns: true if 'this' is before otherShow
     */
    bool operator>(Show * otherShow);

};

#endif  // MUSICPLANNER_SHOW_H
