#include "../src/Show.hpp"

/**
 * Tests the operator overload and comparisons between the 
 * time and dates of two different shows.
 * 
 * TODO: Change to account for system time, so if a show is the
 * next year it wont appear to come before one in the current year.
 */
void testComparisons(){

    Show firstShow; 
    Show secondShow;

    /*  Test One (general case) */

    firstShow.setMonth("September");
    firstShow.setDay(12);
    secondShow.setMonth("June");
    secondShow.setDay(20);

    cout << "Running test: June 20th < September 12th" << endl;
    if ( Show::compareDates(&secondShow, &firstShow) ){
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    } 
    else {
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }

    /*  Test Two  (same month) */

    firstShow.setMonth("January");
    firstShow.setDay(12);
    secondShow.setMonth("January");
    secondShow.setDay(21);

    cout << "Running test: January 12th < January 21st" << endl;
    if ( Show::compareDates(&firstShow, &secondShow) ){
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    } 
    else {
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }

    /* Test Three (same date) */

    firstShow.setMonth("December");
    firstShow.setDay(12);
    secondShow.setMonth("December");
    secondShow.setDay(12);

    cout << "Running test: December 12th < December 12st" << endl;
    if ( Show::compareDates(&firstShow, &secondShow) ){
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    } 
    else {
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }

    /* TODO: write more tests */
    

}

int main(){

    /* TODO: COMMENT OUT WHEN TESTING AS NECESSARY */
    
    cout << "Beginning comparison tests..." << endl;
    cout << endl;
    testComparisons();
    cout << "Tests complete." << endl;
    
    return 0;

}


