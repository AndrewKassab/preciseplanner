#include "Schedule.hpp"
#include "Planner.hpp"

// Constructor used for creating a brand new schedule
Schedule::Schedule(){
  schedule = new vector<Show*>();
}

// Constructor used when reading existing schedule from file
Schedule::Schedule( vector<Show*>* showVector ){
  schedule = showVector;
  isize = showVector->size();
}

// Destructor, deletes all allocated memory
Schedule::~Schedule(){
  auto it = schedule->begin();
  auto end = schedule->end();
  while ( it != end ){
    delete (*it);
    it++;
  }
  delete schedule;
}

// Returns the amount of shows in our schedule
unsigned int Schedule::size(){
  return isize;
}

// Checks if schedule is empty
bool Schedule::empty(){
  if (isize == 0){
    return true;
  } else return false;
}

/**
*  Add a show to the schedule. Adjust size accordingly
*/
void Schedule::add( Show * newShow ){
  schedule->push_back(newShow);
  isize++;
}

/**
 * Removes a show at the specific index
 */
void Schedule::remove( int & index ){
  schedule->erase(schedule->begin() + index);
  isize--;
}

/**
* Prints out the entire schedule, using the printShow method
* for each show.
*/
void Schedule::printSchedule(){

  auto it = schedule->begin();
  auto end = schedule->end();
  int index = 1;

  cout << "----------------Schedule----------------" << endl;

  if ( schedule->size() == 0 ){
    cout << STR_NO_SHOWS << endl;
    return;
  }

  while ( it != end ){
    cout << index << ": ";
    (*it)->printShow();
    it++;
    index++;
  }

}

/**
* Prints out the shows in the schedule that take place
* during the specified month, using the printShow method
* for each show.
*/
void Schedule::printSchedule( int & month ){

  Show * currentShow;
  int index = 0;

  auto it = schedule->begin();
  auto end = schedule->end();

  // search schedule till we find the first show in the given month
  while ( ( it != end ) && ( (*it)->getMonth() != month ) ){
    it++;
  }

  if ( it == end ){
    cout << STR_NO_SHOWS << " in " << Planner::monthToString(month) << endl;
    return;
  }

  cout << "-----------Shows in " << Planner::monthToString(month) << "-----------\n"; 

  while ( ( it != end ) && ( (*it)->getMonth() == month ) ){
    (*it)->printShow();
    it++;
  }

}

/**
* Prints the very next upcoming show (the first in our schedule)
*/
void Schedule::printNext(){
  cout << "---------------Next Show---------------" << endl;
  if (schedule->size() > 0){
    schedule->at(0)->printShow();
  } else {
    cout << STR_NO_SHOWS << endl;
  }
}

// Returns a Show* object from our schedule at the specified index.
Show* Schedule::get( int & index )
{
  return (*schedule)[index];
}

// Returns an iterator pointing at the first element of our schedule
vector<Show*>::iterator Schedule::begin(){
  return schedule->begin();
}

// Returns an iterator pointing past the last element of our schedule 
vector<Show*>::iterator Schedule::end(){
  return schedule->end();
}
