//=============================================================
// Name        : student.h
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : 5 Exercise 2
// ***********************************************************
// ************************************************************************
//Assignment 5 Exercise 2
//************************************************************************
/*
************************************************************************
Assignment 4 Exercise 6
************************************************************************
*/
struct TrainCar{
	char *type;
	float capacity;
	int serial;
	TrainCar *next;
};
/*
---
Algorithm createTrainCar(kind, cargo, serial)
Pre:	kind   :: refToChar -- cstring describing type of train
		cargo  :: Integer -- weight capacity of train, in Kg
		serial :: Integer -- unique serial number to identify TrainCar
Post:	new train allocated with provided fields
Return:	refToTrainCar -- newly created train
*/
TrainCar *createTrainCar(const char*, int, int);
/*
---
Algorithm connectTrains(front, back)
Pre:	front :: refToTrainCar -- pointer to first TrainCar in first train
		back  :: refToTrainCar -- pointer to first TrainCar in second train
Post:	last car in front now points to first car in back
Return:	nothing
*/
void connectTrains(TrainCar*, TrainCar*);	
/*
---
Algorithm disconnectCars(train, serial)
Pre:	train  :: refToTrainCar -- pointer to first TrainCar in train to be disconnected
		serial :: Integer -- serial number of car to be disconnected after
Post:	train is disconnected after TrainCar with serial number
Return:	refToTrainCar -- second newly created train from split
*/
TrainCar *disconnectCars(TrainCar*, int);
/*
---
Algorithm printTrain(train)
Pre:	train :: refToTrainCar -- train to be printed
Post:	all TrainCars in train are printed
Return: nothing
*/
void printTrain(TrainCar*);
/*	
---
Algorithm distroy(train)
Pre:	train :: refToTrainCar -- train to be printed
Post:	dealloacte heap requested for trian
Return: nothing
*/
void destroy(TrainCar *train);