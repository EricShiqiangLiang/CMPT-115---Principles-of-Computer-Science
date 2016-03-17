//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: 7
//Exercise: 2
#include <iostream>
using namespace std;
//Algorithm marioCount(a, b)
//pre: Integer a, b, which are the width and length of the room respectively
//post: start at the left bottom of the room, count the number of paths that
//      can lead mario to the right top of the room, obeying the rules.
//return: number of paths
int marioCount(int a, int b){
	if(a == 1 && b == 1){
		return 1;                      //base case: start in a 1*1 room
	}
    int up = 0;       //at one point there are at maximum two choices: go up or go right
    int right = 0;
    if(a > 1){
    	up = marioCount(a-1, b); //recursive case1: count the path to end if mario goes up
    }                            //going up is same as starting in an (a-1)*b room
    if(b > 1){
    	right = marioCount(a, b-1);  //recursive case2: count the path to end if mario goes right
    }                                //going right is same as starting in an a*(b-1) room
    return up + right;
}
int main(){
	cout << "Number of paths for 3x3: " << marioCount(3,3) << endl;
	cout << "Number of paths for 4x4: " << marioCount(4,4) << endl;
	cout << "Number of paths for 10x12: " << marioCount(10,12) << endl;
	return 0;
}