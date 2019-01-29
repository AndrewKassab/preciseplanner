#include "../src/Planner.hpp"

int main(){

    Schedule * newSchedule = new Schedule();

    // TODO: Adjust to read in schedule from a file

    Planner::addShows( newSchedule );

    // save back to file in binary

    // free memory
    delete newSchedule;

    return 0;
}