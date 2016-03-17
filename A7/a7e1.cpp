//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: 7
//Exercise: 1
#include <iostream>
#include <cstring>
using namespace std;

//Algorithm Fibonacii(n)
//pre: Interger n
//post: generate the nth Fibonacci number using recurcive algorithm
//return: the nth Fibonacci number
int Fibonacii(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	else{
		return Fibonacii(n-1) + Fibonacii(n-2);
	}
}
//Algorithm Moosonacci(n)
//pre: Interger n
//post: generate the nth Moosonacci number using recurcive algorithm
//return: the nth Moosonacci number
int Moosonacci(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	if(n == 2){
		return 1;
	}
	else{
		return Moosonacci(n-3) + Moosonacci(n-2) + Moosonacci(n-1);
	}
}
//Algorithm CharacterCount(s, c, i)
//pre: RefToC-string s, Character c, Integer i
//post: count the number of times that c occurs in s starting at index i
//return: the times that c occurs in s starting at index i
int CharacterCount(char s[], char c, int i){
	if(i > strlen(s)){
		return 0;                              //base case: the end has been reached and no match is found
	}
	else if(s[i] == c){
		return 1 + CharacterCount(s, c, i + 1); //recursive case: a match found at index i
	}
	else{
		return CharacterCount(s,c,i + 1);       //recursive case: no match found at index i
	}

}

int main(){
	cout << Fibonacii(0) << endl;   //0
	cout << Fibonacii(1) << endl;   //1
	cout << Fibonacii(2) << endl;   //1
	cout << Fibonacii(3) << endl;   //2
	cout << Fibonacii(4) << endl;   //3
	cout << Fibonacii(5) << endl;   //5
	cout << Fibonacii(15) << endl;  //610
	cout << Moosonacci(0) << endl;  //0
	cout << Moosonacci(1) << endl;  //1
	cout << Moosonacci(2) << endl;  //1
	cout << Moosonacci(3) << endl;  //2
	cout << Moosonacci(4) << endl;  //4
	cout << Moosonacci(5) << endl;  //7
	cout << Moosonacci(6) << endl;  //13
	cout << Moosonacci(7) << endl;  //24
	cout << Moosonacci(8) << endl;  //44
	cout << Moosonacci(9) << endl;  //81
    char s1[12] = "Hello World";
    char s2[] = "aaabbbcccaaa";
    cout << CharacterCount(s1, 'l', 3) << endl; // 2 'l's starting at index 3
    cout << CharacterCount(s2, 'a', 0) << endl; // 6 'a's starting at 0
    cout << CharacterCount(s2, 'a', 2) << endl; // 4 'a's starting at 2
    cout << CharacterCount(s2, 'a', 12) << endl; // 0 because index is out of range

}