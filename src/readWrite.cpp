#include "Planner.hpp"

/**
 * Reads in formatted text from an input file and 
 * uses it to load in our schedule of shows. 
 * 
 * Returns: Schedule of shows
 * 
 * TODO: archive shows that have already passed to a specific file
 */
Schedule * Planner::readSchedule(){
  
  Schedule * newSchedule = new Schedule();

  ifstream inputFile;

  // Open file
  inputFile.open( SCH_FILE_PATH , ios::binary);
  
  if (!inputFile){
    cout << "File not found, new file created...\n" << endl;
    return newSchedule;
  }

  time_t theTime = time(NULL);
  struct tm *currentTime = localtime(&theTime);

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
    // filter out the events that have already passed
    if (month >= (currentTime->tm_mon+1) && (day >= (currentTime->tm_mday + 1))){
      Show * newShow = new Show(name,month,day);
      newSchedule->add(newShow);
    } else {
      // TODO: Archive show to a different file
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
  }

  outputFile << "\n";

  // free memory
  outputFile.close();
}