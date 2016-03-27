//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: lab7
#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
	Stack *s = CreateStack(5);
	PushOntoStack(s, 1);
	PushOntoStack(s, 2);
	PushOntoStack(s, 3);
	PushOntoStack(s, 4);
	PushOntoStack(s, 5);
	PrintStack(s);
	int aa = 6;
	Element *a;
	a = & aa;
	PopFromStack(s, a);
	PopFromStack(s, a);
	PopFromStack(s, a);
	PopFromStack(s, a);
	PopFromStack(s, a);
	PrintStack(s);
	cout << StackCount(s) << StackIsEmpty(s) << *a << PopFromStack(s, a) << endl;
	return 0;
}