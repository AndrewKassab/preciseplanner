#include "Planner.hpp"

/**
 * Reads in formatted text from an input file and 
 * uses it to load in our schedule of shows. 
 * 
 * Returns: Schedule of shows
 */
Schedule * Planner::readSchedule(){
    
    Schedule * newSchedule = new Schedule();

    ifstream inputFile;

    // Open file
    inputFile.open( FILE_PATH , ios::binary);

    string line; 
    string name;
    string month;
    unsigned int day;
    float startTime;
    string hasTicket;
    bool ticket;

    // Read in shows from input file and add them into our schedule
    while ( inputFile ){
        getline(inputFile, line);
        name = line;   
        getline(inputFile, line);
        month = line;
        if ( inputFile.eof()){
            break;
        }
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

    return newSchedule;
}