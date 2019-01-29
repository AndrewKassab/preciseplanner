#ifndef SHOW_HPP
#define SHOW_HPP
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
    Show( string & n, string & m, int & d, int & start, bool & t );
    bool setName( string & n );
    bool setMonth( string & m );
    bool setDay( int & d ); 
    bool setTime( string & t );
    bool setTicket( string & response );

    /**
     * Helper method for setTime, filters a time in the form of
     * a string and turns it into a float representation.
     *
     * Returns: true if the transformation was successful, false otherwise
     */
    bool timeFilter( string & t );

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
     * Compares the date of a show to the date of another show. 
     *
     * Returns: true if 'this' is before otherShow
     */
    bool operator>(Show * otherShow);

    // TODO: REMOVE, FOR TESTING PURPOSES ONLY (testTime)
    float getTime(){
        return startTime;
    }

};

#endif  // MUSICPLANNER_SHOW_H
