//============================================================================
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : lab4 exercise 2
//============================================================================
using namespace std;

#include <cstdlib>
#include "myTime.h"

int main(){
  myTime *t;
  t = createTime();
  addHour(t);
  addMinute(t);
  printTime(t);
  destroyTime(t);
  return EXIT_SUCCESS;
}
