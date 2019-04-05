#include "Planner.hpp"

/**
 * Reads in formatted text from an input file and 
 * uses it to load in our schedule of shows. 
 * 
 * Returns: Schedule of shows
 * 
 */
Schedule * Planner::readSchedule(){
  
  Schedule * newSchedule = new Schedule();

  ifstream inputFile;
  ofstream archiveFile;

  string homeDir = HOME_DIR;
  string schedulePath = homeDir + SCH_FILE_PATH;
  string archivePath = homeDir + ARCH_FILE_PATH;

  inputFile.open( schedulePath , ios::binary);
  archiveFile.open( archivePath , ios::binary);
  
  if (!inputFile){
    return newSchedule;
  }

  string line = "."; 
  string name;
  unsigned int month;
  unsigned int day;
  unsigned int year;
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
    getline(inputFile, line);
    year = stoi(line);
    Show * newShow = new Show(name,month,day,year);
    // filter out the events that have already passed
    if ( dateIsValid( newShow ) ){
      newSchedule->add(newShow);
    } else {
      archiveFile << month << "-" << day << "-" << year << ": " << name << "\n";
    }
  }

  // close input file
  inputFile.close();

  return newSchedule;

}

/**
 * Writes the showSchedule's contents to the output file
 */
void Planner::writeSchedule( Schedule * showSchedule ){

  ofstream outputFile;

  string homeDir = HOME_DIR;
  string schedulePath = homeDir + SCH_FILE_PATH;

  outputFile.open( schedulePath, ios::binary);

  // output schedule into file
  for ( int i = 0; i < showSchedule->size(); i++){
    Show currentShow = *(showSchedule->get(i));
    outputFile << currentShow.getName() << "\n";
    outputFile << currentShow.getMonth() << "\n";
    outputFile << currentShow.getDay() << "\n";
    outputFile << currentShow.getYear() << "\n";
  }

  outputFile << "\n";

  // free memory
  outputFile.close();
}