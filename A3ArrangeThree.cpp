//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: Assignment3 Exercise 1
//============================================

#include <iostream>
using namespace std;
//Algorithm 1.0 arrangeThree(x, y, z)
//Pre: x::refToInteger
//     y::refToInteger
//     z::refToInteger
//    x, y, z contain valid references to three intergers
//Post: These references will have values in increasing order.
//Return: none
//
void arrangeThree(int *x, int *y, int *z){
	if (*x >= *y){
		swap(*x, *y);               //call function swap to make sure that
	}                               //each element is no smaller than
	if (*x >= *z){                  //the previous element
		swap(*x, *z);
	}
	if (*y >= *z){
		swap(*y, *z);
	}
}
//Algorithm 1.1 swap(x, y)
//Pre:x::refToInteger
//    y::refToInteger
//    x,y contain valid references
//Post:the contents of *x and *y are exchanged
//Return: none

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;                  //exchange the two values of these two references
	*y = temp;
}

//Algorithm 2 arrangeFour(w, x, y, z)
//Pre:w::refToInteger
//    x::refToInteger
//    y::refToInteger
//    z::refToInteger
//    w,x,y,z contain valid references
//Post:These references will have values in increasing order.
//Return: none

void arrangeFour(int *w, int *x, int *y, int *z){
	arrangeThree(w, x, y);     //sort the first three references into increasing order
	arrangeThree(x, y, z);     //sort the last three references into increasing order
	                           //by now, we can say for sure that the last three references are in increasing order, but we still
	                           //but the second number could be smaller than the first one after the seconding sorting
	arrangeThree(w, x, y);     //sort the first three again so all four numbers will be in increasing order
}



int main() {
	int a = 1, b = 3, c = 2;      //test1 for arrangeThree
	arrangeThree(&a, &b, &c);     //using references as parameters
	cout << a << b << c << endl;  //prints test result
	int a1 = 1, b1 = 2, c1 = 3;   //test2 for arrangeThree
	arrangeThree(&a1, &b1, &c1);
	cout << a1 << b1 << c1 << endl;
	int a2 = 2, b2 = 1, c2 = 3;   //test3 for arrangeThree
	arrangeThree(&a2, &b2, &c2);
	cout << a2 << b2 << c2 << endl;
	int a3 = 2, b3 = 3, c3 = 1;   //test4 for arrangeThree
	arrangeThree(&a3, &b3, &c3);
	cout << a3 << b3 << c3 << endl;
	int a4 = 3, b4 = 1, c4 = 2;   //test5 for arrangeThree
	arrangeThree(&a4, &b4, &c4);
	cout << a4 << b4 << c4 << endl;
	int a5 = 3, b5 = 2, c5 = 1;   //test6 for arrangeThree
	arrangeThree(&a5, &b5, &c5);
	cout << a5 << b5 << c5 << endl;
	int a6 = 2, b6 = 2, c6 = 1;   //test7 for arrangeThree
	arrangeThree(&a6, &b6, &c6);
	cout << a6 << b6 << c6 << endl;
	int w=1, x = 2, y = 4, z = 3;      //test1 for arrangeFour
	arrangeFour(&w, &x, &y, &z);
	cout << w << x << y << z << endl;
	int w1=1, x1 = 4, y1 = 3, z1 = 2;      //test2 for arrangeFour
	arrangeFour(&w1, &x1, &y1, &z1);
	cout << w1 << x1 << y1 << z1 << endl;
	int w2= 3, x2 = 1, y2 = 4, z2 = 2;      //test3 for arrangeFour
	arrangeFour(&w2, &x2, &y2, &z2);
	cout << w2 << x2 << y2 << z2 << endl;
	int w3= 4, x3 = 3, y3 = 2, z3 = 1;      //test4 for arrangeFour
	arrangeFour(&w3, &x3, &y3, &z3);
	cout << w3 << x3 << y3 << z3 << endl;
	int w4= 2, x4 = 3, y4 = 2, z4 = 1;      //test5 for arrangeFour
	arrangeFour(&w4, &x4, &y4, &z4);
	cout << w4 << x4 << y4 << z4 << endl;
	return 0;
}
