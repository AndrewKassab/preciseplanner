#include "Schedule.hpp"

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
    while ( !schedule->empty()) {
        delete schedule->back();
        schedule->pop_back();
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
 * TODO: Finish method
 */
void Schedule::add( Show * newShow ){
    schedule->push_back(newShow);
    // sort the schedule by show times
    isize++;
}

// TODO:
void Schedule::printSchedule(){

}

// TODO:
void Schedule::printSchedule( string & month ){

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