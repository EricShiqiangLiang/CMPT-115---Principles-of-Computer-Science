//=============================================================
// Name        : student.cc
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : Lab5 Exercise 3
// ***********************************************************
// ************************************************************************
//Lab 5 Exercise 3
//************************************************************************
#include <iostream>
#include <fstream>
using namespace std;
int main(){
ifstream fin1;
// open the file named filetoread.txt so we can get data from it
fin1.open("input.txt", ios::in);
// check that the file opened correctly
char target;
int count = 0;
if (fin1.is_open()){
fin1.get(target);         //access the file before using eof
while (!fin1.eof()) {
       cout << target;
 if (target == 'e'){
       count = count + 1;
    }
fin1.get(target);
}
cout << endl;
cout << "The number of 'e' is: ";
cout << count;
}// assuming that there is an integer at the start of the file
else
cout << "file is not available for opening" << endl;
//close the stream
fin1.close();
}