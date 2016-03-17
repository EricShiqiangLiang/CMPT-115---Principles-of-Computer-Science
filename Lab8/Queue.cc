// file: Queue.cc
// CMPT 115
//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: lab8

#include "Element.h"
#include "Queue.h"
#include <iostream>
using namespace std;


// Algorithm createQueue(cap)
// Pre: cap :: integer, the capacity of the new Queue
// Post: allocates space for the Queue, total of cap Elements
// Return: a reference to the new Queue
Queue *createQueue(int capacity) {
  Queue *rNewQueue = new Queue;
  rNewQueue->elts = new Element[capacity];
  rNewQueue->head = 0;
  rNewQueue->numElements = 0;
  rNewQueue->capacity = capacity;
  return rNewQueue;
}

// Algorithm destroyQueue()
// Post: deallocates space used by the Queue
void destroyQueue(Queue *q) {
  delete q->elts;
  delete q;
}

// Algorithm enqueue(q,e)
// Pre: q :: reference to a Queue
//      e :: Element
// Post: Stores e in q
// Return: true if successful, false if queue is already full

bool enqueue(Queue *q, Element e) {
  if (q->capacity > q->numElements){
  	q->elts[(q->head+q->numElements)%q->capacity] = e;
  }
  else{
  	cout << "The queue is full." << endl;
  	return false;
  }
  q->numElements = q->numElements + 1;
  return true;
}

// Algorithm dequeue(q,e)
// Pre: q :: reference to Queue
//      e :: reference to Element
// Post: copies data to *e, and removes it from queue
// Return: true if successful, false if queue is already empty

bool dequeue(Queue *q, Element *e) {
	if(q->numElements > 0){
		*e = q->elts[q->head];
		q->head = (q->head + 1) % q->capacity;
		q->numElements = q->numElements - 1;
		return true;
	}
	else{
		cout << "The queue is empty." << endl;
		return false;
	}

}

// Algorithm queueSize(q)
// Pre: q :: reference to a Queue
// Return: the number of elements in the queue
int queueSize(Queue *q) {
  return q->numElements;
}

// Algorithm queueEmpty(q)
// Pre: q :: reference to a Queue
// Return: true if the queue is empty, false otherwise
bool queueEmpty(Queue *q) {
	if(queueSize(q) == 0){
		return true;
	}
  	else{
  		return false;
  	}
}


// Algorithm queueFull(q)
// Pre: q :: reference to a Queue
// Return: true if the queue is full, false otherwise
bool queueFull(Queue *q) {
 	if(queueSize(q) == q->capacity ){
 		return true;
 	}
 	else{
 		return false;
 	}
}


// end of file

