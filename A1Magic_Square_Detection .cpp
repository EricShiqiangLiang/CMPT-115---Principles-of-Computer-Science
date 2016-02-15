

//============================================================================
// Name        : a1.cpp
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : Assignment1 Exercise 1
// Description : This program checks whether a 3*3 array is a magic square
//               or not. Magic Square contains the integers 1 through 9
//               inclusively. Every integer in the range 1 through 9 appears
//               exactly once. Every row, column, and diagonal sums to 15.
//               This program should display the message ¡°Yes!¡± if it¡¯s magic,
//               or ¡°No!¡± if it¡¯s not.
//============================================================================

#include <iostream>
using namespace std;

// /////////////////////////////////////////////////////////
// Algorithm 2: checkSum(array, N, sum)
//   Pre: given an array of N integers, and a value in sum
//   Post: nothing
//   Return: true if the values in the array add up to sum
//           false otherwise
//

bool checkSum(int array[], int N, int sum)
{
    int SUM = 0;
    int j;
	for (j = 0; j < N; j++)
		{
			SUM = SUM + array[j];
		}
		if (SUM == sum)
		{
			return true;
		}
		else
		{
		return false;
		}
}
// /////////////////////////////////////////////////////////
// Algorithm 1.2.2: checkRows(square)
//   Pre: given a 3x3 array of integers
//   Post: nothing
//   Return: true if all the rows sum to 15
//           false otherwise

bool checkRow(int square[3][3])
{
	 int r1[3] = {square[0][0],  square[0][1], square[0][2]};
     int r2[3] = {square[1][0],  square[1][1], square[1][2]};
     int r3[3] = {square[2][0],  square[2][1], square[2][2]};
     return checkSum(r1, 3, 15) && checkSum(r2, 3, 15) && checkSum(r3, 3, 15);
}

// /////////////////////////////////////////////////////////
// Algorithm 1.2.3: checkColumns(square)
//   Pre: given a 3x3 array of integers
//   Post: nothing
//   Return: true if all the columns sum to 15
//           false otherwise

bool checkColumns(int square[3][3])
{
	int c1[3] = {square[0][0],  square[1][0], square[2][0]};
	int c2[3] = {square[0][1],  square[1][1], square[2][1]};
	int c3[3] = {square[0][2],  square[1][2], square[2][2]};
	return checkSum(c1, 3, 15) && checkSum(c2, 3, 15) && checkSum(c3, 3, 15);
}

// /////////////////////////////////////////////////////////
// Algorithm 1.2.4: checkDiagonals(square)
//   Pre: given a 3x3 array of integers
//   Post: nothing
//   Return: true if all the diagonals sum to 15
//           false otherwise

bool checkDiagonals(int square[3][3])
{
	int d1[3] = {square[2][0],  square[1][1], square[0][2]};
	int d2[3] = {square[0][0],  square[1][1], square[2][2]};
	return checkSum(d1, 3, 15) && checkSum(d2, 3, 15);
}


// /////////////////////////////////////////////////////////
// Algorithm 1.2.1: checkRange(square)
//   Pre: given a 3x3 array of integers
//   Post: nothing
//   Return: true if the square contains all the integers 1 .. 9
//           false otherwise

bool checkRange(int square[3][3]) {
	bool seen[9] = {false, false, false, false, false, false, false, false, false};
	int i, j, index, k;
	bool flag = true;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j <3; j++)
		{
			  for (k = 0; k < 9; k++)
			  {                                                   //Fixing the "known bug":
			    if (square[i][j] <= 9 && square[i][j] > 0)        //Make sure that it does not a
			    {                                                 //"true" to an address that's not
			       seen[square[i][j]-1] = true;                   //within the range of the seen array,
			    }                                                 //so it won't fail when the square contains
			  }                                                   //numbers that are out of range.
		}
	}
	for (index = 0; index < 9; index++)
	{
	 flag = (flag && seen[index]);
	}
	if (flag == true)
	{
		return true;
	}
	else
	{
	    return false;
	}
}

// /////////////////////////////////////////////////////////
// Algorithm 1.2: checkSquare(square)
//   Pre: given a 3x3 array of integers
//   Post: nothing
//   Return: true if the square has all the properties of a magic
//           square; false otherwise
bool checkSquare (int square[3][3])
{

	return checkRow(square) && checkColumns(square) && checkDiagonals(square) && checkRange(square);
}

// /////////////////////////////////////////////////////////
// Algorithm 1.1: getSquare(square)
//   Pre: given a 3x3 array to contain integers
//   Post: obtains 9 numbers from the console, storing them in the
//         given array
//   Return: Nothing
//
void getSquare(int square[3][3])
{
	int i, j;
	cout << "Enter 9 integers to construct a 3 by 3 square, please notice that the sequence is important." << endl;
	cout << "Now please enter all 9 elements of this array:" << endl;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
	 {
		cin >> square[i][j];
	 }
	}
}
///////////////////////////////////////////////////////////
// Algorithm 1: main()
//   Pre: nothing
//   Post: nothing
//   Return: 0
//
//

int main()                        //This section actually contains all the test codes
{
	int testSum[3] = {1, 2, 3};
	int test1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int test2[3][3] = {8, 1, 6, 3, 5, 7, 4, 9, 2};
	if ((checkSum(testSum, 3, 6) == true) && (checkSum(testSum, 3, 7) == false))   //test code for Algorithm 2:checkSum
	{
     	cout << "checkSum test:Passed!" << endl;
    }
    else
    {
		cout << "checkSum test:Failed!" << endl;
    }
	if ((checkRow(test1) == false) && (checkRow(test2) == true))                  //test code for Algorithm 1.2.2:checkRows
	{
     	cout << "checkRow test:Passed!" << endl;
	}
    else
    {
		cout << "checkRow test:Failed!" << endl;
    }
	if ((checkColumns(test1) == false) && (checkColumns(test2) == true))          //test code for Algorithm 1.2.3:checkColumns
	{
     	cout << "checkColumns test:Passed!" << endl;
	}
    else
    {
		cout << "checkColumns test:Failed!" << endl;
    }
	int test3[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};                                //test code for Algorithm 1.2.4:checkDiagonals
	if ((checkDiagonals(test1) == true)
		 && (checkDiagonals(test2) == true)
		 && (checkDiagonals(test3) == false))
	{
     	cout << "checkDiagonals test:Passed!" << endl;
	}
    else
    {
		cout << "checkDiagonals test:Failed!" << endl;
    }
	int test4[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 8};                                //test code for Algorithm 1.2.1:checkRange
	int test5[3][3] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	if ((checkRange(test1) == true)
		 && (checkRange(test2) == true)
		 && (checkRange(test3) == false)
		 && (checkRange(test4) == false)
		 && (checkRange(test5) == false))
	{
	    cout << "checkRange test:Passed!" << endl;
	}
    else
    {
		cout << "checkRange test:Failed!" << endl;
    }
    int test6[3][3] = {5, 5, 5, 5, 5, 5, 5, 5, 5};
    int test7[3][3] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
    if ((checkSquare(test1) == false)
    	 && (checkSquare(test2) == true)
		 && (checkSquare(test3) == false)
		 && (checkSquare(test4) == false)
		 && (checkSquare(test5) == false)
		 && (checkSquare(test6) == false)
		 && (checkSquare(test7) == false))
	{
	    cout << "checkSquare test:Passed!" << endl;
	}
    else
    {
		cout << "checkSquare test:Failed!" << endl;
    }


  char choice;                                                                    //This allows the user to decide if he/she wants to exit the program

  while (true)                                                                    //The while loop contains Algorithm 1
  {
	int square[3][3];
	getSquare(square);
	cout << "Your square is:" << endl;                                            //test code for Algorithm 1.1:getSquare
	int i;                                                                        //this is done by displaying the square user just entered,
	for (i = 0; i < 3; i++)                                                       //if the output and the input are the same, then getSquare works fine.
	{
		cout << square[i][0] << " " << square[i][1] << " " << square[i][2] << endl;
	}
	if (checkRange(square) == false)
	{
		cout << "Oops! Your numbers are out of range! So the answer is: " << endl;
	}
	else
	{
		cout << "Great! Let's see if your sequence of numbers is a magic square. The answer is: " << endl;
	}
	if (checkSquare(square) == true)
	{
		cout << "YES!" << endl;
	}
	else
   {
		cout << "NO!" << endl;
   }
	cout << "Press any key to check another square or press N to exit:" <<endl;
	cin >> choice;
	cout << choice << endl;
	if (choice == 'N' || choice == 'n')                                           //If the user types in 'N' or 'n', codes stop running.
		break;
  }
  return 0;
}






