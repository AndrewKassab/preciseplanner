#include "../src/Planner.hpp"
#include <fstream>

// TODO: Adjust to read in schedule from a file
int main(){

    Schedule * newSchedule = new Schedule();

    //ifstream inputFile;

    // Open file
    //inputFile.open("../data/schedule.txt", ios::binary);

    // If a file wasn't opened, create a new file.
    if (!inputFile.is_open()) {
        cout << "Error opening file... exiting... " << endl;
        return -1;
    }

    // Check if file is new / empty
    //inputFile.seekg(0, ios_base::end);
    //unsigned int len = inputFile.tellg();
    //if (len == 0){
    //    cout << "No file found, New schedule file created." << endl;
    //}

    // reset file back to beginning
    //inputFile.seekg(0, ios_base::beg);

    //string line; 
    //string name;
    //string month;
    //unsigned int day;
    //float startTime;
    //int ticket;

    //TODO: Finish!
    //while ( !inputFile.eof() ){
      //  getline(inputFile, line);
     //   name = line;
    //}


    Planner::addShows( newSchedule );

    // save back to file in binary

    // free memory
    delete newSchedule;
    //inputFile.close();

    return 0;
}