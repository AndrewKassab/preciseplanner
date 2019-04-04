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

  inputFile.open( SCH_FILE_PATH , ios::binary);
  archiveFile.open( ARCH_FILE_PATH, ios::binary);
  
  if (!inputFile){
    return newSchedule;
  }

  time_t theTime = time(NULL);
  struct tm *currentTime = localtime(&theTime);
  int currentMonth = currentTime->tm_mon+1;
  int currentYear = currentTime->tm_year-100;
  int currentDay = currentTime->tm_mday +1;

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
    // filter out the events that have already passed
    if ( ( year > currentYear ) || 
        ( ( month >= currentMonth ) && ( day >= currentDay ) ) ){
      Show * newShow = new Show(name,month,day,year);
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
  outputFile.open( SCH_FILE_PATH, ios::binary);

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