#ifndef SHOW_HPP
#define SHOW_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/**
 * Stores a show object.
 * 
 * TODO: Function to search google for a show 
 * and open the results in a webpage
 */
class Show{

private:
    string name;
    string month;
    unsigned int day;
    bool ticket;

public:
    Show();
    Show( string n, string m, int d, bool t );
    void setName( string n );
    string getName();
    bool setMonth( string m );
    string getMonth();
    bool setDay( int d ); 
    unsigned int getDay();
    bool setTicket( string response );

    /**
     * Prints out a show and all its contents in the following format:
     * Month - Day - Year: Show_name
     * 
     */
    void printShow();

    /**
     * Returns: true if the user has a ticket to the event.
     */
    bool hasTicket();
    
    /**
     * Compares the date of a show to the date of another show. 
     *
     * Returns: true if 'this' is before otherShow or the same date.
     */
    static bool compareDates(Show * showOne, Show * showTwo);

    /**
     * Returns an int value representation of a show's month.
     * Used for comparing months to see which comes first.
     * 
     * Returns: int representation of month, (1-12)
     */
    unsigned int monthToInt();

};

#endif   
