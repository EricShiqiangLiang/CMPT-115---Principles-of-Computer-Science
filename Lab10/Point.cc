//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Lab: 10
/*
 *  Point.cpp
 *  
 *
 *  Created by Ian McQuillan on 19/03/07.
 *  Modified by MCH.
 *
 */

#include <iostream> 
#include "Point.h"
#include <cmath>

using namespace std;

// Constructor
Point::Point(float xCoord, float yCoord){ 
  x = xCoord; 
  y = yCoord; 
} 

// destructor
Point::~Point(){ 
  //do nothing 
  cout << "about to destroy";
} 


// mutators
void Point::setX(float newX){ 
  x = newX; 
} 


void Point::setY(float newY){ 
  y = newY; 
} 


// accessors

float Point::getX(){ 
  return x; 
} 



float Point::getY(){ 
  return y; 
} 

float Point::displacement(){
  return sqrt(x*x+y*y);
}