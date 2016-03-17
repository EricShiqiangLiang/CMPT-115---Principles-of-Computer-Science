// file: referenceDemo.cc
// author: CMPT115.2015.T2
// A demonstration of references and pointers.

#include <iostream>
#include <cstdlib> 
using namespace std;


// Multiply the parameter by two
void doubleThis(int x) {
  x = 2 * x;
}

// Multiply the parameter by two
void doubleThat(int *x) {
  *x = 2 * *x;
}


int main() {

  int aVariable = 3;
  cout << "Before doubling: " << aVariable << endl;
  doubleThis(aVariable);
  cout << "After first doubling: " << aVariable << endl;
  doubleThat(&aVariable);
  cout << "After second doubling: " << aVariable << endl;
  
  cout << "Wanted: Pithy remark.  Inquire within." << endl;
  return EXIT_SUCCESS;
}
