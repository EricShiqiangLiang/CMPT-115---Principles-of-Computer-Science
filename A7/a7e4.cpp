// file Student.cc
// CMPT 115
// Assignment 7 Exercise 3
//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: 7
//Exercise: 4
#include <iostream>
#include <cstring>
#include "Student.h"
#include "List.h"
#include "Iterator.h"
using namespace std;

float calculateClassAverage(List *s){
	float sum = 0;
	float classAverage = 0;
	Iterator *iter = createIterator(s);
	while(hasNext(iter)){
		sum = sum + calculateCourseGrade(next(iter));
	}
	classAverage = sum / lengthList(s);
	destroyIterator(iter);	
	cout << "Class average is: " << classAverage << endl;
	return classAverage;
}



int main(){
//1.Crate a new List
	List *stuList;
	stuList = createList();  
//2.Read student records from a file and put them in the list    
	int n;                       //number of student records in input.txt
	cin >> n;                    //input.txt starts with a integer which is the number of records
	for(int i = 1; i <= n; i++){
		Element el = readStudentRecordFromConsole();
		calculateCourseGrade(el);     //update finalNumeric and finalLetter
		insertTail(stuList, el);
	}
//3.Use an Iterator to display each student record
	Iterator *iter1 = createIterator(stuList);
	while(hasNext(iter1)){
		displayStudentRecord(next(iter1));
	}
	destroyIterator(iter1);
//4.Use an Iterator to display final grades of each student
	Iterator *iter2 = createIterator(stuList);
	while(hasNext(iter2)){
		displayFinalGrade(next(iter2));
	}
	destroyIterator(iter2);	
//5.Use an Iterator to calculate class average and display the result.
	calculateClassAverage(stuList);

//6. Use an Iterator to find a student by student number and 
//   make one change to that student's assignment grade.
	Iterator *iter4 = createIterator(stuList);       
	while(hasNext(iter4)){
		Element e1 = next(iter4);
    	if( 333333 == key(e1) ){             //use 333333 as key
    		changeAssignmentGradeForStudent(e1, 0, 20);
    		calculateCourseGrade(e1);
//7. Display the student record that changed.
            displayStudentRecord(e1);
    	} 
	}
	destroyIterator(iter4);

//8. Use an Iterator to find a student by student number and
//   make one change to that student's final exam grade.
	Iterator *iter5 = createIterator(stuList);       
	while(hasNext(iter5)){
		Element e2 = next(iter5);
    	if( 222222 == key(e2) ){              //use 222222 as key
    		changeExamGradeForStudent(e2, 'F', 10);
    		calculateCourseGrade(e2);
//9. Display the student record that changed.
            displayStudentRecord(e2);
    	} 
	}
	destroyIterator(iter5);
//10. Use an Iterator to calculate class average and display the result.
	calculateClassAverage(stuList);

//11. Use an Iterator to give every student 5 more marks on Assignment 5.
	Iterator *iter6 = createIterator(stuList);
	while(hasNext(iter6)){
		Element e3 = next(iter6);
		changeAssignmentGradeForStudent(e3, 5, 5);
		calculateCourseGrade(e3);
	}
	destroyIterator(iter6);

//12. Use an Iterator to calculate class average and display the result.
	calculateClassAverage(stuList);	

//test. display final grades after all changes.
	Iterator *iter7 = createIterator(stuList);
	while(hasNext(iter7)){
		displayFinalGrade(next(iter7));
	}
	destroyIterator(iter7);

	return 0;
}