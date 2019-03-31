#include "../src/Planner.hpp"
#include <fstream>

int main(){

  Schedule * newSchedule = Planner::readSchedule();

  newSchedule->printSchedule();

  // TODO: test other print methods
  //newSchedule.printSchedule("april");

  newSchedule->printNext();

}