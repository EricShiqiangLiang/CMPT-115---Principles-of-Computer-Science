// file: useFunctions.cc
// author: CMPT115.2015.T2
// Write a bit of code to practice references and pointers.
//============================================================================
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : lab2
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;


// a simple function that uses pointers
void midpoint(float *a, float *b, float *mp) {
    *mp = (*a + *b)/2.0;;
}

int main() {

  float x, y;
  cout << "Please enter 2 numbers: ";
  cin >> x >> y;

  // Compute and display the midpoint

  cout << "Example 1: " << endl;
  // this is a correct use of midpoint(); there are others
  float middle;
  midpoint(&x, &y, &middle);
  cout << "The midpoint between " << x << " and " << y
       << " is: " << middle << endl;


  cout << "Example 2: " << endl;
  // this is an incorrect use of midpoint(); fix it!
  float *xPtr1 = &x;
  float *yPtr1 = &y;
  midpoint(xPtr1, yPtr1, &middle);
  cout << "The midpoint between " << x << " and " << y
       << " is: " << middle << endl;


  cout << "Example 3: " << endl;
  // this is an incorrect use of midpoint(); fix it!
  float middle2;
  float *mid2 = &middle2;
  midpoint(&x, &y, mid2);
  cout << "The midpoint between " << x << " and " << y
       << " is: " << *mid2 << endl;


  cout << "Example 4: " << endl;
  // this is an incorrect use of midpoint(); fix it!
  // The problem in this example is very subtle.
  float *xPtr = &x;
  float *yPtr = &y;
  float mid3;
  midpoint(xPtr, yPtr, &mid3);
  cout << "The midpoint between " << *xPtr << " and " << *yPtr
       << " is: " << mid3 << endl;


  cout << "Example 5: " << endl;
  // this is an incorrect use of midpoint(); fix it!
  // The problem in this example is very subtle.
  float middle4;
  float *mid4 = &middle4;
  midpoint(&x, &y, mid4);
  cout << "The midpoint between " << x << " and " << y
       << " is: " << *mid4 << endl;



  cout << "Wanted: Pithy remark.  Inquire within." << endl;
  return EXIT_SUCCESS;
}
