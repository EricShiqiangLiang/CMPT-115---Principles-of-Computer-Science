// file: warningDemo.cc
// author: CMPT115.2015.T2
// This program contains a few common problems that the compiler
// can warn you about, but are not strictly errors.
// Compile this twice, and note the differences!
//   g++ warningDemo.cc
//   g++ -Wall warningDemo.cc
// Now study the code, and see whether you agree with asking for warnings!
//============================================================================
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : lab2
//============================================================================
#include <iostream>
using namespace std;


// this function represents all those functions that have complicated
// conditionals.  Every path through a function should have a return value,
// but this one doesn't.  What happens when b=-30 or b=3?
bool noReturnForSomeCases (int b)
{
  if (b < 0 && b > -10)
  {
    return true;
  }
  else if (b > 10)
  {
    return false;
  }
  else
  {
	return false;
  }
}

int main() {

  double x = 3.14;
  double y = 6.28;
  double zl = y/x;  // in perfect math, this should be exactly 2.0


  if (zl == 2.0)
  {
    cout << "Floating point equality test success!" << endl;
  }
  else
  {
    cout << "Remember: floating point arithmetic is not exact!" << endl;
  }

  double z1 = y/x;  // l looks like 1 in most fonts; is this a typo or not?
  if (z1 == 2.0)
  {
    cout << "Whoops, an assignment!  What's *true* about assignment?" << endl;
  }


  // test a case that "works"
  if (noReturnForSomeCases(-3))
  {
    cout << "A value was returned for -3" << endl;
  }

  // but what does this do?
  if (noReturnForSomeCases(-30))
  {
    cout << "A value was returned for -30" << endl;
  }
  else
  {
    cout << "No value was returned, but treated as false.  Is that really what I wanted?" << endl;
  }

}
