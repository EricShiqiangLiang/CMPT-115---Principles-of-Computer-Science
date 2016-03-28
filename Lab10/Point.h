//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Lab: 10
/*
 *  Point.h
 *  
 *
 *  Created by Ian McQuillan on 19/03/07.
 *  Modified by MCH.
 *
 */


class Point { 

private: 
  float x; // stores the x coordinate
  float y; // stores the y coordinate 

public: 
  Point(float xCoord, float yCoord); //the constructor 
  void setX(float newX); 
  void setY(float newY); 
  float getX(); 
  float getY();
  float displacement();
  ~Point(); //the destructor 
}; 

