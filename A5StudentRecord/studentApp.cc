//=============================================================
// Name        : student.cc
// Author      : Shiqiang Liang
// Version     : 1.0
// NSID        : shl083
// Student #   : 11208088
// Course      : CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
// Assignment  : 5 Exercise 1
// ***********************************************************
// ************************************************************************
//Assignment 5 Exercise 1
//************************************************************************
#include <cstdlib>
#include <iostream>
#include "student.h"
using namespace std;
/*
---
Algorithm classAverage(cla, n)
Pre:    cla :: reference to student records of a class, type:Student *
        n :: Integer -- number of studenets in that class
Post:   claculates the average grade of this class
Return: class average
*/
float classAverage(Student *cla[], int n){
    float classTotal = 0;
    float classAverage = 0;
    for (int i = 0; i < n; i++){
    classTotal = classTotal + calculateAverageGrade(cla[i]);
    }
    classAverage = classTotal / n;
    return classAverage;
}
int main(){
    Student **students;            //type: reference to reference of Student
    students = new Student* [10];  //the data type we allocate on heap should be Student*, it's an array of pointers
    for (int i = 0; i < 10; i++){
        students[i] = readStudentRecordFromConsole(); //students[i] dereferences to number i pointer in the array
    }                                                 //which would be a pointer to number i student record
    for (int i = 0; i < 10; i++){                     //type of student[i] is Student*, which is same as what the function returns
        displayStudentRecord(students[i]);
    }
    cout << "The class average is: " << classAverage(students, 10) << endl;
    ChangeAssignmentGradeForStudent(students[0],1,-100);
    ChangeExamGradeForStudent(students[1], 'M', -90);
    ChangeExamGradeForStudent(students[2], 'F', -80);
    cout << "The following student records have been changed: " << endl;
    displayStudentRecord(students[0]);
    displayStudentRecord(students[1]);
    displayStudentRecord(students[2]);
    cout << "The new class average is: " << classAverage(students, 10) << endl;
    for (int i = 0; i < 10; i++){                     
        ChangeAssignmentGradeForStudent(students[i], 5, 5);
    }
    cout << "The new class average is: " << classAverage(students, 10) << endl;
    for (int i = 0; i < 10; i++){
    destroyStudentRecord(students[i]);
    }
    return EXIT_SUCCESS;


}