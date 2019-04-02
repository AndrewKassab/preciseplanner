#ifndef SHOW_HPP
#define SHOW_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/**
 * Stores a show object.
 */
class Show{

private:
  string name;
  unsigned int month;
  unsigned int day;
  // TODO: unsigned int year;

public:
  Show();
  Show( string n, unsigned int m, unsigned int d);
  void setName( string n );
  string getName();
  bool setMonth( string m );
  unsigned int getMonth();
  bool setDay( string d ); 
  unsigned int getDay();

  /**
   * Prints out a show and all its contents in the following format:
   * Month - Day - Year: Show_name
   */
  void printShow();

  /**
   * Prints a show with all the details / information
   */
  void printAll();

  /**
   * Compares the date of a show to the date of another show. 
   *
   * Returns: true if 'this' is before otherShow or the same date.
   */
  static bool compareDates(Show * showOne, Show * showTwo);

};

#endif   
