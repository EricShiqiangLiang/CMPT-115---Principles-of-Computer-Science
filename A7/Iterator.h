//
// Iterator.h
// Iterator header file
//

#include "List.h"

#ifndef _Iterator_
#define _Iterator_


struct Iterator {
	Node *nextNode;
};


// The interface (function prototypes for operations)

// This function creates a Iterator for a given List.
//   Pre: rList is a reference to a list
//   Post: memory is allocated to store the Iterator
//   Return: a reference to the Iterator record
Iterator *createIterator(List *rList);

// This function determines if there are more elements in the list to visit
//   Pre: rTrav is a reference to a List Iterator
//   Post: nothing
//   Return: true, if there are more elements to visit, and false otherwise
bool hasNext(Iterator *rTrav);

// This function returns the next element in the list to visit
//   Pre: rTrav is a reference to a List Iterator
//        This function should only be called if hasNext() is true!
//   Post: nothing
//   Return: an Element 
Element next(Iterator *rTrav);

// This function deallocates the memory associated with the given Iterator
//  Pre: rTrav is a reference to a Iterator
//  Post: rTrav no longer points to valid Iterator
//  Return: Nothing
void destroyIterator(Iterator *rTrav);

#endif
