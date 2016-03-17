// file: writeFunctions.cc
// author: CMPT115.2015.T2

//============================================================================
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : lab2
//============================================================================

// Write a bit of code to practice references and pointers.

#include <iostream>
#include <cstdlib>
using namespace std;


// minimum()
// write the function matching the function call in part 1
// -- see main() below


// returns the average of *x, *y
// see part 2, in main() below
float average(float *x, float *y) {
    return (*x + *y)/2.0;;
}

float *minimum(float *x, float *y){
	if (*x < *y)
	{
		return x;
	}
	else
	{
		return y;
	}
}


int main() {

  float x, y, z;
  float *xPtr, *yPtr, *zPtr;
  float *min;

  xPtr = &x; // initializing pointers
  yPtr = &y;
  zPtr = &z;

  *xPtr = 5.0;  // initiializing x and y indirectly
  *yPtr = 2.0;

  // Part 1: read the following code, then write minimum()
  cout << "The minimum of " << x << " and " << y << " is ";
  min = minimum(xPtr, yPtr); // write minimum()
  cout << *min << endl;


  // Part 2: read the following code, study the function average()
  //         then use average() as indicated
  *zPtr = average(xPtr, yPtr);
  cout << "The average of " << x << " and " << y << " is ";
  // call average() here so that *zPtr contains the average of x, y
  cout << *zPtr << endl;


  cout << "Wanted: Pithy remark.  Inquire within." << endl;
  return EXIT_SUCCESS;
}
