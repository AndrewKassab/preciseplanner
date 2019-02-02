#include "../src/Planner.hpp"
#include <fstream>

// TODO: Move to a loadSchedule() method
int main(){

    Schedule * newSchedule = new Schedule();

    ifstream inputFile;

    // Open file
    inputFile.open("data/schedule.txt", ios::binary);

    // If a file wasn't opened, create a new file.
    if (!inputFile.is_open()) {
        cout << "Error opening file... exiting... " << endl;
        return -1;
    }

    // Check if file is new / empty
    inputFile.seekg(0, ios_base::end);
    unsigned int len = inputFile.tellg();
    if (len == 0){
        cout << "No file found, New schedule file created." << endl;
    }

    // reset file back to beginning
    inputFile.seekg(0, ios_base::beg);

    string line; 
    string name;
    string month;
    unsigned int day;
    float startTime;
    string hasTicket;
    bool ticket;

    // Read in shows from input file and add them into our schedule
    //TODO: Account for file formatting error ( when stoi fails, catch exception )
    while ( !inputFile.eof() ){
        getline(inputFile, line);
        name = line;   
        getline(inputFile, line);
        month = line;
        getline(inputFile, line);
        day = stoi(line);
        getline(inputFile, line);
        string hasTicket = line;
        if ( line == "True" ){
            ticket = true;
        } else ticket = false;
        getline(inputFile, line);
        Show newShow(name,month,day,ticket);
        newSchedule->add(&newShow);
    }

    // close input file
    inputFile.close();

    // re-open for output

    Planner::addShows( newSchedule );

    // TODO: Make sure newSchedule was sorted properly in ordered dates

    ofstream outputFile;
    outputFile.open("data/schedule.txt", ios::binary);

    // TODO: write new schedule to output file 
    for ( int i = 0; i < newSchedule->size(); i++){
        outputFile << newSchedule->get(i)->getName();
        outputFile << newSchedule->get(i)->getMonth();
        outputFile << newSchedule->get(i)->getDay();
        if ( newSchedule->get(i)->hasTicket()){
            outputFile << "True";
        } else outputFile << "False";
    }


    // free memory
    outputFile.close();
    // TODO: fix bugs with deleting schedule
    //delete newSchedule;

    return 0;
}