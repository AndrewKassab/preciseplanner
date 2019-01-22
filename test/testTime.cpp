#include "../src/Show.hpp"

void testTime(){
    
    Show showOne;
    string result;
    string time;
    
    // Test one
    time = "10:00";
    cout << "Running test: " << time << endl;
    cout << "Testing setTime()..." << endl;
    cout.setstate(ios_base::failbit);
    if ( showOne.setTime(time) && showOne.getTime() == 10 ){
        cout.clear();
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout.clear();
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }
    cout << "Testing timetoString()..." << endl;
    if ( (result = showOne.timetoString()) == "10:00PM" ){
        cout.clear();
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout.clear();
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
        cout << "Your output: " << result << endl;
        cout << "Desired output: 10:00PM" << endl;
    }

    // Test two 
    time = "213434";
    cout << endl;
    cout << "Running test: " << time << endl;
    cout << "Testing setTime()... " << endl;
    cout.setstate(ios_base::failbit);
    if ( showOne.setTime(time) ){
        cout.clear();
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }
    else {
        cout.clear();
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }

    // Test three
    time = "4:00:";
    cout << endl;
    cout << "Running test: " << time << endl;
    cout << "Testing setTime()... " << endl;
    cout.setstate(ios_base::failbit);
    if ( showOne.setTime(time) ){
        cout.clear();
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }
    else {
        cout.clear();
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }

    // Test four 
    time = "3:00";
    cout << endl;
    cout << "Running test: " << time << endl;
    cout << "Testing setTime()... " << endl;
    cout.setstate(ios_base::failbit);
    if ( showOne.setTime(time) && showOne.getTime() == 3 ){
        cout.clear();
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout.clear();
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }
    cout << "Testing timetoString()..." << endl;
    if ( ( result = showOne.timetoString() ) == "3:00PM" ){
        cout.clear();
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout.clear();
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
        cout << "Your output: " << result << endl;
        cout << "Desired output: 3:00PM" << endl;
    }

    // Test five
    time = "12:30";
    cout << endl;
    cout << "Running test: " << time << endl;
    cout << "Testing setTime()... " << endl;
    cout.setstate(ios_base::failbit);
    if ( showOne.setTime(time) && showOne.getTime() == .5 ){
        cout.clear();
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout.clear();
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
    }
    cout << "Testing timetoString()..." << endl;
    if ( (result = showOne.timetoString()) == "12:30PM" ){
        cout.clear();
        cout << "\033[1;32m----PASS----\033[0m" << endl;
    }
    else {
        cout.clear();
        cout << "\033[1;31m----FAIL----\033[0m" << endl;
        cout << "Your output: " << result << endl;
        cout << "Desired output: 12:30PM" << endl;
    }

}

int main(){

    cout << "Beginning tests." << endl;
    cout << endl;
    testTime();
    cout << "Tests complete." << endl;

    return 0;

}


