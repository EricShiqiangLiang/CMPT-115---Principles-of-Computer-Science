//=============================================================
// Name        : student.cc
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : Lab5 Exercise 4
// ***********************************************************
// ************************************************************************
//Lab 5 Exercise 4
//************************************************************************
#include <iostream>
#include <fstream>
using namespace std;
int main(){
ifstream fin1;
// open the file named filetoread.txt so we can get data from it
fin1.open("infile.txt", ios::in);
// check that the file opened correctly
if (fin1.is_open()){
// getting data from the file is just like getting data from the console
int x;
float y;
char z;
float t;
fin1 >> x;
cout << x << endl; 
fin1 >> y;
cout << y << endl;
fin1 >> z;
cout << z << endl;
fin1 >> t;
cout << t << endl;
}// assuming that there is an integer at the start of the file
else
cout << "file is not available for opening" << endl;
//close the stream
fin1.close();
}