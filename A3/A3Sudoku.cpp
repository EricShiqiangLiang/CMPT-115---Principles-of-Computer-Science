//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: Assignment3 Exercise 2


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



// Algorithm 2.1: swapRows(square)
//   Pre: given a 9x9 latin square
//   Post: a new square whose one random pair of rows
//        has been exchanged according to the limitations.
//   Return: Nothing
//
//  1. Generate three random numbers from 0 to 2
//  2. Use two numbers as index of row
//  3. Use another number as index of blocks (row 1-3 is block 1, row 4-6 is block 2, row 7-9 is block //        3)
//  4. Exchange those two rows within the same block.
//

void swapRows(int square[9][9])
{
	int i;
	int temp[9];
	int a = rand()%3;
	int b = rand()%3;
	do
		{
			b = rand()%3;
		} while(a == b);
	int c = rand()%3;
	for (i = 0; i < 9; i++)
	{
		temp[i] = square[a+3*c][i];               //swap two Columns with the same block
		square[a+3*c][i] = square[b+3*c][i];      //(Row 1-3, Row 4-6, Row 7-9)
		square[b+3*c][i] = temp[i];
	}
}


// Algorithm 2.2: swapColumns(square)
//   Pre: given a 9x9 latin square
//   Post: a new square whose one random pair of columns
//        has been exchanged according to the limitations.
//   Return: Nothing
//
//  1. Generate three random numbers from 0 to 2
//  2. Use two numbers as index of column
//  3. Use another number as index of blocks (column 1-3 is block 1, column 4-6 is block 2, column
//        7-9 is block 3)
//  4. Exchange those two columns within the same block.
//
void swapColumns(int square[9][9])
{
	int i;
	int temp[9];
	int a = rand()%3;
	int b = rand()%3;
	do
	{
		b = rand()%3;
	} while(a == b);
	int c = rand()%3;
	for (i = 0; i < 9; i++)
	{
		temp[i] = square[i][a+3*c];            //swap two Columns with the same block
		square[i][a+3*c] = square[i][b+3*c];   //(Column 1-3, Column 4-6, Column 7-9)
		square[i][b+3*c] = temp[i];
	}
}

//Algorithm 2: Rand(square, n)
//   Pre: given a 9x9 latin square and an integer n, n stands for
//       the times of swaps
//   Post: a new square whose pairs of rows and pairs of columns have
//        been randomly swapped n times.
//   Return: Nothing
//
//   1. Call procedure swapRows(square)
//   2. Call procedure swapColumns(square)
//   3. Repeat step 1 and step 2 n times.
//
void Rand(int square[9][9], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		swapRows(square);            //call swapRows to swap one pair or rows
		swapColumns(square);         //call swapColumns to swap one pair or Columns
	}                                //repeat this procedure for n times
}

//Algorithm 3: Blank(square, k)
//   Pre: given a 9x9 latin square and an integer k, k stands for
//       the number of blanks
//   Post: a new square whose k elements have been replaced with blanks
//   Return: Nothing
//
//   1. generate k pairs of random numbers 0-8, use this as index.
//   2. replace the corresponding element (if it's not a "0") in the square with 0
//   3. if the corresponding element has been replaced, then generate one more pair random numbers
void Blank(int square[9][9], int k)
{
	int a, b, s;
	for (s = 0; s < k; s++)
	{
		a = rand()%9;
		b = rand()%9;
	    if (square[a][b] !=0)           //make sure the program doesn't assign a 0 to a position which's already been replaced
	    {
	    	square[a][b] = 0;
	    }
	    else
	    {
	    	s--;                        //thus the loop will generate "0" at k different positions.
	    }
	}
}

///////////////////////////////////////////////////////////
// Algorithm 1: main()
//   Pre: nothing
//   Post: nothing
//   Return: 0
//
//   1. Randomize a 9x9 latin square for n times
//      call function Rand(square, n)
//   2. Replace 25 elements with blanks
//      call function Blank(square,k)
//   3. Display the square
//

int main() {
	srand(time(NULL));
	int square[9][9] = {{1,2,3,4,5,6,7,8,9},       //input the original square
	                    {4,5,6,7,8,9,1,2,3},
	                    {7,8,9,1,2,3,4,5,6},
	                    {2,3,4,5,6,7,8,9,1},
	                    {5,6,7,8,9,1,2,3,4},
	                    {8,9,1,2,3,4,5,6,7},
	                    {3,4,5,6,7,8,9,1,2},
	                    {6,7,8,9,1,2,3,4,5},
	                    {9,1,2,3,4,5,6,7,8}};
	    Rand(square, 50);                        //call function Rand to randomnaize it for 50 times
	    Blank(square, 25);
	    int i, j;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (square[i][j] != 0)
				{
			    	cout << square[i][j] << " ";
				}
				else
				{
			        cout << " " << " ";        //replace 0 with blank
				}
				if (j == 8)
				{
				  cout << endl;
				}
			}
		}
	return 0;
}
