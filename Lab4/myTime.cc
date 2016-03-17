// file: myTime.cc
// Implementation file for the myTime ADT
//
//============================================================================
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : lab4 exercise 2
//============================================================================
#include <iostream>
using namespace std;

#include <cstdlib>
#include <iomanip>

#include "myTime.h"



// Algorithm createTime()
//   Post: a newly allocated myTime element is created
//         and initialized to be 0 hours and 0 minutes
//   Return: a pointer to the newly allocated myTime element.
myTime *createTime() {
  myTime *t;
  t = new myTime;
  t->hour = 0;
  t->minute = 0;
  return t;
}


// Algorithm destroyTime(t)
// this will deallocate the myTime data structure from the heap
//   Pre: t is a pointer to a myTime
//   Post: the space consumed by t is released
void destroyTime(myTime *t) {
  delete(t);
}


// Algorithm addHour(t)
// this will add one hour to the myTime pointed to by t.
//   Pre: t is a pointer to a myTime
//   Post: the myTime variable has had the hour increased by one,
//         unless it was 23, in which case, it is reset to 0.
void addHour(myTime *t) {
  (*t).hour = ((*t).hour + 1) % 24;//modulo 24 since there is 24 before reset
}

// Algorithm printTime(t)
// this will display the time to the scree in a friendly format
//   Pre:  t is a pointer to a myTime
//   Post: output the value of *t to console
//   Return: none
void printTime (myTime *t) {
  cout << "The current time is:" << endl;
  cout << setfill('0') << setw(2) << (*t).hour << ":"  << setfill('0')
       << setw(2) << (*t).minute;
}

// Algorithm addMinute(t)
// this will add one minute to the myTime pointed to by t.
//   Pre: t is a pointer to a myTime
//   Post: the myTime variable has had the minute increased by one,
//         unless it was 59, in which case, it is reset to 0.
void addMinute(myTime *t) {
  if ((*t).minute == 59)
  {
  	(*t).hour = ((*t).hour + 1) % 24;//reaching 60 minutes changes the hour
  }
  (*t).minute = ((*t).minute + 1) % 60;//modulo 60 since there is 60 before reset
}

// end of file
