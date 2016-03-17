//=============================================================
// Name        : a1.cpp
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : Lab 4 Exercise 1


#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
void outputAbsoluteValue(float);
float absoluteValue(float value);


// This source file will not compile properly, because the functions are 
// defined in human-order, not C++ order.
// Don't reorder the functions!  Add function prototypes to help C++ use 
// human-ordering.

int main(void) {
	float testValue;
	
	cout << "Enter a float value: \n";
	cin >> testValue;
	
	outputAbsoluteValue(testValue);
	
	return EXIT_SUCCESS;
}


// Algorithm absoluteValue(value)
// Pre:  a float value
// Return: the absolute (float) value of the input float 
// Post: nothing
float absoluteValue(float value)
{
	if (value < 0)
	{
		return -value;
	}
	else
	{
		return value;
	}
}

// Algorithm  outputAbsoluteValue(value)
// Pre:  a float value
// Post: the absolute (float) value of the input float is sent to the console
// Return: nothing
void outputAbsoluteValue(float value)
{
									// apply fancy formatting
	cout << setw(10)   				// this creates a field of 10 characters
	     << setprecision(4) 		// this puts 4 digits after the decimal point
	     << absoluteValue(value)   	// this calls the absolutevalue function
	     << endl;					// this sends a newline to the console
}
