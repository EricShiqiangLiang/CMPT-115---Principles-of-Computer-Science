//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Lab: 10
/*
 *  test.cpp
 *  
 *
 *  Created by Ian McQuillan on 19/03/07.
 *  Modified by MCH.
 *
 */

#include <iostream> 
#include "Point.h"

using namespace std;


int main() { 
  float x;
  float y;

  cout << "Starting the exciting testPoint application!" << endl; 


  // delete p;

  cout << "Enter new x coordinate: "; 
  cin >> x;

  cout << "Enter new y coordinate: "; 
  cin >> y;

  Point p(x,y);
  
  cout << "So, your point is this: "  
       << p.getX() << ", " << p.getY() << endl;
  cout << "Its displacement is: " << p.displacement() << endl;

  cout << "Allocating a new point on the heap!" << endl;
  float x1;
  float y1;
  cout << "Enter new x coordinate: ";
  cin >> x1;
  cout << "Enter new y coordinate: "; 
  cin >> y1;
  Point* np = new Point(x1,y1);
  cout << "The point on the heap is: "
       << np->getX() << ", " << np->getY() << endl;
  cout << "Its displacement is: " << np->displacement() << endl;
  delete np;

  cout << "Completed the exciting testPoint application!" << endl; 

  return 0; 
} 
