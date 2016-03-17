//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: Lab3 Exercise 2

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char *input;
    input = new char[200];
    char firstHalve[100] = {0}, secondHalve[100] = {0};
    cout << "Please enter your text:" << endl;
    cin.getline(input, 200);
    cout << "You typed: " << input <<endl;
    int n = strlen(input)/2;
    for (int i = 0; i < n; i++)
    {
       firstHalve[i] = input[i];
       if (strlen(input)%2 == 0)          //if the length of input is even, simply swap two halves
       {
    	   secondHalve[i] = input[i+n];
       }

       else
       {
    	   for (int j = 0; j <= n; j++)  //if the length of input is odd, then put the middle to the last halve
    	   secondHalve[j] = input[j+n];  //then swap
       }
    }
    strcpy(input, secondHalve);
    strcat(input, firstHalve);
    cout << "New text is£º " << input << endl;
    delete []input;
    return 0;
}
