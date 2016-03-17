// Assignment 8 lab8
//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: 8
//lab: 8
#include <iostream>
#include <cstring>
#include "Queue.h"
using namespace std;

int main(){
	Queue* lineup = createQueue(10);
	while (true){
		char choice;
		cout << "enter t to take a number, c to call a number or q to quit:" << endl;
		cin >> choice;
		if (choice == 't'){
			if (!queueFull(lineup)){
				Element num1 ;
				cin >> num1;
				enqueue(lineup, num1);
				cout << "You have number "<< num1 << endl;
			}
			else{
				cout <<"The line is full." << endl;
			}
		}
		else if(choice == 'c'){
			if (!queueEmpty(lineup)){
				Element num2;
				dequeue(lineup, &num2);
				cout << "The number " << num2 << " should leave the line.";
			}
			else{
				cout << "The line is empty." << endl;
			}
		}
		else if(choice == 'q'){
			break;
		}
	}
	return 0;
}
