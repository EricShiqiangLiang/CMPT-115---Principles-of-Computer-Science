// Array-based stack implementation
// CMPT 115/117
//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: lab7

#include <cstdlib>
#include <iostream>
#include "Stack.h"
using namespace std;


///////////////////////////////////////////////
// READ THIS PART AT LEAST
// Note: Complete all of the functions below!
// Each function has a trivial "do-nothing" implementation
// called a "stub".  This file should compile, but it will do nothing
// until you replace the do nothing code with working code.
///////////////////////////////////////////////


// CreateStack (cap)
// Creates a new stack of size cap
// Pre: cap is an int between 0 and 1000
// Post: A new stack is created in dynamic memory
// Return: A pointer to the new stack in Dynamic memory
Stack *CreateStack(int cap) {
  Stack *newStack = new Stack;
  newStack->numElements = 0;
  newStack->arr = new Element[cap];
  if (newStack->arr == NULL){
  	newStack->capacity = 0;
  }
  else{
  	newStack->capacity = cap;
  }
  return newStack;
}



// DestroyStack (stack)
// Deletes the stack from dynamic memory
// Pre: Stack is a pointer to a stack in memory
// Post: Stack is destroyed and removed from dynamic memory
// Return: none
void DestroyStack(Stack *stack) {
  delete stack->arr;
  delete stack;
}


// PrintStack(stack)
// Prints the stack from the top to bottom (from last element
// inserted to first element inserted)
// Pre: Stack is a pointer to a stack in memory
// Post: Stack is unchanged
// Return: none
void PrintStack(Stack *stack) {
  if(stack->numElements != 0){
  	for(int i = stack->numElements -1; i >= 0; i--){
  		cout << stack->arr[i] << endl;
  	}
  }
  else{
  	cout << "stack is empty" << endl;
  }
}


// ReadFromStack(stack, el)
// Reads the element from the end of the stack (last inserted
//      element).
// Pre: stack is a reference to a stack in memory
//      el is a reference to an integer
// Post: stack is unchanged
//       el is updated to contain a COPY of the element from 
//       the stack
// Return: True if successful, false if the stack is empty
bool ReadFromStack(Stack *stack, Element *el) {
  if(stack->numElements > 0){
  	*el = stack->arr[stack->numElements - 1];
  	return true;
  }	
  else{
  	return false;
  }
}



// StackIsEmpty(stack)
// Checks to see if the stack is empty or not
// Pre: stack is a reference to a stack
// Post: stack is unchanged
// Return: true if the stack is empty, false otherwise
bool StackIsEmpty(Stack *stack) {
  if(stack->numElements == 0){
  	return true;
  }
  else{
  	return false;
  }
}


// StackCount(stack)
// Counts the number of elements in the stack
// Pre: stack is a reference to a stack
// Post: stack is unchanged
// Return: an integer displaying the number of elements in the stack
int StackCount(Stack *stack) {
   return stack->numElements;
}


// PushOntoStack(stack, el)
// Pushes a copy of the given element onto the stack
// Pre: stack is a reference to the stack
//      el is a integer (not a reference) to be added to the stack
// Return: true if successful, false if the stack is full
bool PushOntoStack(Stack *stack, Element el) {
  if(stack->numElements < stack->capacity){
  	stack->arr[stack->numElements] = el;
  	stack->numElements = stack->numElements + 1;
  	return true;
  }
  else{
  	return false;
  }
}


// PopFromStack(stack, el)
// Pops an element off of the end of the stack
// Pre: stack is a reference to the stack
//      el is a reference to an integers with space already
//          designated in memory to store the result of the pop
// Post: stack is updated to contain one less element
//       el is updated with the element removed from the stack
// Return: true if successful, false if the stack is empty
bool PopFromStack(Stack *stack, Element *el) {
  if(stack->numElements > 0){
  	*el = stack->arr[stack->numElements - 1];
  	stack->numElements = stack->numElements - 1;
  	return true;
  }
  else{
  	return false;
  }
}


// end of file

