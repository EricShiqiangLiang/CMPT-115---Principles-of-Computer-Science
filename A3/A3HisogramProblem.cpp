
//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: Assignment3 Exercise 4
//============================================
//////////////////////////////////////////////////////////
// Hisogram problem
// Design Document
//
// 1. Application's Purpose:
//   to produce a histogram from a user specified list of integers.
//   Here is an example of the proper usage:
//   UNIX$ ./histogram
//   How many data values? 10
//   Enter integer data
//   1 2 3 4 5 4 3 2 3 4
//   ----------- Histogram ----------------
//   1: *
//   2: **
//   3: ***
//   4: ***
//   5: *
//
//////////////////////////////////////////////////////////



#include <iostream>
using namespace std;

// /////////////////////////////////////////////////////////
// Algorithm 1.1: getData(size, array)
//   Pre: given an array and its size to obtain integers from console
//   Post: obtains 9 numbers from the console, storing them in the
//         given array
//   Return: Nothing
//
//   1. Display a friendly prompt
//   2. Obtain size integers from the console


void getData (int size, int Arr[]){

  cout << "\n\nEnter integer data one line at a time\n" << endl ;

  for (int i=0; i < size; i++){
    cin >> Arr[i];                        //stores numbers from console in the destination array
  }
}

// /////////////////////////////////////////////////////////
// Algorithm 1.2: findMinAndMax(array, size, *min, *max)
//   Pre: given an array and its size, two pointers *min and *max
//   Post: obtains the minimum and maximum values in the array, pointed by *min and *max
//   Return: Nothing

void findMinAndMax(int array[], int size, int *min, int *max)
{
  int smallest = array[0];
  int largest = array[0];
  *min = smallest;
  *max = largest;
  for (int i = 1; i < size; i++)
  {
    if (array[i] > *max){              //find the maximum and minimum values in array
      *max = array[i];                 //use pointers as parameters so any change will be saved
    }
    if (array[i] < *min){
      *min = array[i];
    }
  }
}

// /////////////////////////////////////////////////////////
// Algorithm 1.3: *makeFrequency (data, dSize, *minDataValue,*maxDataValue)
//   Pre: given an array data and its size dSize, two pointers *minDataValue and *maxDataValue
//   Post: stores the frequencies of each number in data in an array called frequency
//         the size of such an array is exactly the range of numbers in data
//
//   Return: NULL if there is no data at all
//           frequency if the data is a valid sequence of number
int *makeFrequency (int data[], int dSize, int *minDataValue, int *maxDataValue)
{

  findMinAndMax(data, dSize, minDataValue, maxDataValue);

  int fSize = *maxDataValue - *minDataValue + 1;  //use the range of data as the size
  int *frequency;
  frequency = new int[fSize];                     //requesting dynamic memory

  if (frequency == NULL)                          //return NULL is data is empty
  {
    return NULL;
  }

  for (int i = 0; i < fSize; i++)                 //if data is valid, initialize frequency with 0
  {
    frequency[i] = 0;
  }


  for (int i = 0; i < dSize; i++)                //for each number from the input
  {
    int j = data[i] - *minDataValue;             //calculate the distance from minimum value to acquire the position in frequency
    frequency[j] = frequency[j] + 1;             //count the times of this number's occurrences, store this in frequency array
  }

  return frequency;
}


void makeHistogram ( int *freq, int min, int max ){

   cout << "\n\n\n ----------- Histogram ----------------\n" << endl;

  int size = max - min + 1;                       //the range of numbers(there could be positions for
  for (int i = 0; i < size; i++){                 //numbers that never showed up if the input is not consecutive)
    if (freq[i] > 0){                             //if a number shows up in the input
      cout << "\n" << min + i << ": ";            //mark this number(min + i is the value of this number)
      for (int j = 0; j < freq[i]; j++) {         //then print * to represent the frequency of its occurrence.
         cout << '*';
       }
    }
  }
  cout << endl << endl;
}

///////////////////////////////////////////////////////////
// Algorithm 1: main()
//   Pre: nothing
//   Post: nothing
//   Return: 0
//
//   1. Ask for the number of data values and then the sequence of numbers
//      call procedure getData()
//
//   2. Calculate the frequency of each number
//      call procedure makeFrequency()
//
//   3. Display "*" to indicate frequency
//      call procedure makeHistogram()


int main() {
//testing
  int test1[5], j=0;                     //Test code for getData
  cout << "Input 1,2,3,4,5 to test fuction getData" << endl;
  getData(5, test1);
  for (int i=0; i < 5; i++)
	{
	  if (test1[i] == i + 1)
	  {
       j++;
	  }
    }
  if (j == 5)
  {
  cout << "getData test: Passed!" <<endl;  //check if the array is as same as the input
  }
  else
  {
  cout << "getData test: Failed!" << endl;
  }

  int test2[7] = {0,1,2,3,4,5,6};         //Test code for findMinAndMax
  	int minimum, maximum;
  	findMinAndMax(test2, 7, &minimum, &maximum);
  	if (minimum == 0 && maximum == 6)          //check if the function give us correct result
  	{
  	cout << "findMinAndMax test: Passed!" << endl;
  	}
  	else
  	{
  	cout << "findMinAndMax test: Failed!" << endl;
  	}

  int test3[4] = {1,2,3,4};      //Test code for MakeFrequency
  int test4[4] = {-1,0,0,2};
  int mintest1, maxtest1, mintest2, maxtest2, *result1, *result2;
  result1 = makeFrequency (test3, 4, &mintest1, &maxtest1);
  result2 = makeFrequency (test4, 4, &mintest2, &maxtest2);
  if (result1[0] == 1 && result1[1] == 1 && result1[2] == 1 && result1[3] == 1
      && result2[0] == 1 && result2[1] == 2 && result2[2] == 0 && result2[3] == 1)
  {
	  cout << "makeFrequency test: Passed!" << endl;   //result1 should be {1,1,1,1}, representing the frequency of 1,2,3,4
  }                                                    //result2 should be {1,2,0,1], representing the frequency of -1,0,1,2
  else
  {
	  cout << "makeFrequency test: Failed!" << endl;
  }
  cout << "If '-1:* 0:** 2:*'  shows up, then makeHistogram test Passed! " << endl;
  makeHistogram (result2, mintest2, maxtest2);           //correct display should be:
                                                         //-1: *
                                                         // 0: **
                                                         // 2: *

 //end of testing

  int dSize;
  int *ArrayOfInts;

  cout << "How many data values? ";
  cin >> dSize;

  ArrayOfInts = new int [dSize];               //requesting dynamic memory from heap for input array

  getData (dSize, ArrayOfInts);                //stores dSize numbers in ArrayOfInts

  int *frequency,min,max;

  frequency = makeFrequency (ArrayOfInts, dSize, &min, &max); //call function makeFrequency to calculate the frequency of each number

  if (frequency == NULL) return -1;

  makeHistogram (frequency, min, max);              //call function makeHistogram to use * to represent frequency of each number

  delete [] frequency;                         //release memory

  return 0;
}


