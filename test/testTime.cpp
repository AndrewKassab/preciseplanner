#include "../src/Show.hpp"

/**
 * Tests the set time and time conversion methods of the Show class
 */
void testTime(){
    
    Show showOne;
    string result;
    string time;
    
    // Test one
    time = "10:00";
    cout << "Running test: " << time << endl;
    cout << "Testing setTime()..." << endl;
    if ( showOne.setTime(time) && showOne.getTime() == 10 ){
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }
    cout << "Testing timetoString()..." << endl;
    if ( (result = showOne.timetoString()) == "10:00PM" ){
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
        cout << "Your output: " << result << endl;
        cout << "Desired output: 10:00PM" << endl;
    }

    // Test two 
    time = "213434";
    cout << endl;
    cout << "Running test: " << time << endl;
    cout << "Testing setTime()... " << endl;
    if ( showOne.setTime(time) ){
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }
    else {
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }

    // Test three
    time = "4:00:";
    cout << endl;
    cout << "Running test: " << time << endl;
    cout << "Testing setTime()... " << endl;
    if ( showOne.setTime(time) ){
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }
    else {
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }

    // Test four 
    time = "3:00";
    cout << endl;
    cout << "Running test: " << time << endl;
    cout << "Testing setTime()... " << endl;
    if ( showOne.setTime(time) && showOne.getTime() == 3 ){
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }
    cout << "Testing timetoString()..." << endl;
    if ( ( result = showOne.timetoString() ) == "3:00PM" ){
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
        cout << "Your output: " << result << endl;
        cout << "Desired output: 3:00PM" << endl;
    }

    // Test five
    time = "12:30";
    cout << endl;
    cout << "Running test: " << time << endl;
    cout << "Testing setTime()... " << endl;
    if ( showOne.setTime(time) && showOne.getTime() == .5 ){
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }
    cout << "Testing timetoString()..." << endl;
    if ( (result = showOne.timetoString()) == "12:30PM" ){
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
        cout << "Your output: " << result << endl;
        cout << "Desired output: 12:30PM" << endl;
    }

}

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
    if ( secondShow <= firstShow ){
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
    if ( firstShow <= secondShow ){
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
    if ( firstShow <= secondShow ){
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    } 
    else {
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }

    /* TODO: write more tests */
    

}

int main(){

    /* TODO: COMMENT OUT WHEN TESTING AS NECESSARY */
    
    cout << "Beginning time tests..." << endl;
    cout << endl;
    testTime();
    cout << "Tests complete." << endl;

    cout << "------------------------------------" << endl;

    cout << "Beginning comparison tests..." << endl;
    cout << endl;
    testComparisons();
    cout << "Tests complete." << endl;
    

    return 0;

}


