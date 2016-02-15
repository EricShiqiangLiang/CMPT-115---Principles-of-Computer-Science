//=============================================================
// Name        : student.cc
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : 5 Exercise 3
// ***********************************************************
// ************************************************************************
//Assignment 5 Exercise 3
//************************************************************************
#include <iostream>
#include <cstring>
#include "trainCar.h"
using namespace std;
//test code:
/* main()
Pre:	nothing
Post:	creat 5 traincars using createTrainCar function: 111 222 333 444 555
        connect all of them then display
        disconnect train 333 then display the second newly created train from split
Return:	0
*/
int main(){
	TrainCar *train1 = createTrainCar("cargo", 6000, 111);    //test code for createTrainCar function
	TrainCar *train2 = createTrainCar("cargo", 6000, 222);
	TrainCar *train3 = createTrainCar("cargo", 6000, 333);
	TrainCar *train4 = createTrainCar("cargo", 7000, 444);
	TrainCar *train5 = createTrainCar("cargo", 7000, 555);
	connectTrains(train1, train2);                           //test code for connectTrains function
	connectTrains(train1, train3);
	connectTrains(train1, train4);
	connectTrains(train1, train5);
	cout << "You just created a train:" << endl;         
	printTrain(train1);                                      //test code for printTrain function
    cout << "The second train from split is:" << endl;       //test code for disconnectCars function
	printTrain(disconnectCars(train1, 333));
    destroy(train1);
    destroy(train2);
    destroy(train3);
    destroy(train4);
    destroy(train5);
	return 0;
}