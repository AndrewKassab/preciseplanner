#include "Planner.hpp"

/**
 * Reads in formatted text from an input file and 
 * uses it to load in our schedule of shows. 
 * 
 * Returns: Schedule of shows
 * 
 * TODO: Filter out or archive shows that have already passed,
 * output them to an archive file
 */
Schedule * Planner::readSchedule(){
    
    Schedule * newSchedule = new Schedule();

    ifstream inputFile;

    // Open file
    inputFile.open( FILE_PATH , ios::binary);
    
    if (!inputFile){
        cout << "File not found, new file created...\n" << endl;
        return newSchedule;
    }

    string line = "."; 
    string name;
    unsigned int month;
    unsigned int day;
    float startTime;
    string hasTicket;
    bool ticket;

    // Read in shows from input file and add them into our schedule
    while ( 1 ){
        getline(inputFile, line);
        if ( line == "" ){
            break;
        }
        name = line;
        getline(inputFile, line);
        month = stoi(line);
        getline(inputFile, line);
        day = stoi(line);
        Show * newShow = new Show(name,month,day);
        newSchedule->add(newShow);
    }

    // close input file
    inputFile.close();

    return newSchedule;
}