#include "../src/Planner.hpp"
#include <fstream>


int main(){

    Schedule * newSchedule = Planner::readSchedule();

    Planner::addShows( newSchedule );

    // TODO: fix bugs with deleting schedule
    //delete showSchedule;

    return 0;
}