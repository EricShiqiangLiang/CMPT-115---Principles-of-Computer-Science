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

/*
---
Algorithm createTrainCar(kind, cargo, serial)
Pre:	kind   :: refToChar -- cstring describing type of train
		cargo  :: Integer -- weight capacity of train, in Kg
		serial :: Integer -- unique serial number to identify TrainCar
Post:	new train allocated with provided fields
Return:	refToTrainCar -- newly created train
*/
TrainCar *createTrainCar(const char* kind, int cargo, int serial){ //use const to avoid warning
	TrainCar *newTrain;
	newTrain = new TrainCar;                               //allocating heap for TrainCar
	newTrain->type = new char[strlen(kind) + 1];           //allocating heap for typr field
	strcpy(newTrain->type, kind);
	newTrain->capacity = cargo;
	newTrain->serial = serial;
    return newTrain;
}

/*	
---
Algorithm connectTrains(front, back)
Pre:	front :: refToTrainCar -- pointer to first TrainCar in first train
		back  :: refToTrainCar -- pointer to first TrainCar in second train
Post:	last car in front now points to first car in back
Return:	nothing
*/
void connectTrains(TrainCar *front, TrainCar *back){
	TrainCar *trainWalker;
	TrainCar *tempCar;
	trainWalker = front;
	if (front == NULL){
		return;
	}
	while (trainWalker != NULL){
		tempCar = trainWalker;
		trainWalker = trainWalker->next;
	}
	tempCar->next = back;
}
/*
---
Algorithm disconnectCars(train, serial)
Pre:	train  :: refToTrainCar -- pointer to first TrainCar in train to be disconnected
		serial :: Integer -- serial number of car to be disconnected after
Post:	train is disconnected after TrainCar with serial number
Return:	refToTrainCar -- second newly created train from split
*/
TrainCar *disconnectCars(TrainCar *train, int serial){
	TrainCar *trainWalker;
	TrainCar *tempCar;
	trainWalker = train;
	while(trainWalker != NULL && trainWalker->serial != serial){
		trainWalker = trainWalker->next;
	}
    if (trainWalker == NULL){
    	return NULL;
    }
    tempCar = trainWalker->next;
    trainWalker->next = NULL;
    return tempCar;
}

/*	
---
Algorithm printTrain(train)
Pre:	train :: refToTrainCar -- train to be printed
Post:	all TrainCars in train are printed
Return: nothing
*/
void printTrain(TrainCar *train){
	TrainCar *luke = train;
	while (luke !=NULL){
		cout << luke->type << endl;
		cout << luke->capacity << endl;
		cout << luke->serial << endl;
		luke = luke->next;
	}
}

/*	
---
Algorithm distroy(train)
Pre:	train :: refToTrainCar -- train to be printed
Post:	dealloacte heap requested for trian
Return: nothing
*/
void destroy(TrainCar *train){
   if (train != NULL){
        delete train->type;
          // deallocate all pointers fields before deallocate the whole record
        delete train;
    }
}
