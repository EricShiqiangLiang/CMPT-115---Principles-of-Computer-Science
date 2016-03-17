//
// Iterator.cc
// Iterator implementation file
//

#include "Iterator.h"
#include <cstdlib>


// This function creates a Iterator for a given List.
//   Pre: rList is a reference to a list
//   Post: memory is allocated to store the Iterator
//   Return: a reference to the Iterator record
Iterator *createIterator(List *rList) 
{
  Iterator *rTrav = new Iterator;
  rTrav -> nextNode = rList->head;
  return rTrav;
}


// This function determines if there are more elements in the list to visit
//   Pre: rTrav is a reference to a List Iterator
//   Post: nothing
//   Return: true, if there are more elements to visit, and false otherwise
bool hasNext(Iterator *rTrav)
{
  return rTrav -> nextNode != NULL;
}

// This function returns the next element in the list to visit
//   Pre: rTrav is a reference to a List Iterator
//        This function should only be called if hasNext() is true!
//   Post: nothing
//   Return: an Element 
Element next(Iterator *rTrav) 
{
  // first, remember the Element we want to return
  Element it = rTrav -> nextNode -> data;
  // but also walk over one step to the next Node.
  rTrav -> nextNode = rTrav -> nextNode -> next;
  // return the Element
  return it;
}

// This function deallocates the memory associated with the given Iterator
//  Pre: rTrav is a reference to a Iterator
//  Post: rTrav no longer points to valid Iterator
//  Return: Nothing
void destroyIterator(Iterator *rTrav)
{
  delete rTrav;
}

// End of file
