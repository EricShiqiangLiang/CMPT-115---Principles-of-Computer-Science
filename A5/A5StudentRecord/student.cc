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
#include <iostream>
#include <cstdio>
#include <cstring>
#include "student.h"
using namespace std;

/*
Algorithm createStudentRecord()
Pre: none
Post: student record created
Return: reference to newly created student record

    refToStudent s <- allocate new Student
    return s
*/
Student *createStudentRecord(){
    Student *s;
    s = new Student;     //allocate dynamic memory for s
    return s;
}

/*
---
Algorithm destroyStudentRecord(s)
Pre:    s :: refToStudent
Post:   Student record s and fields deallocated
Return: nothing
---
*/
void destroyStudentRecord(Student *s){
    if (s != NULL){
        delete (*s).firstName;
        delete (*s).lastName;
        delete (*s).NSID;
        delete (*s).assignments;     // deallocate all pointers fields before deallocate the whole record
        delete s;
    }

}
/*
Algorithm displayStudentRecord(s)
Pre:    s :: refToStudent
Post:   fields in s displayed to console
Return: nothing
*/
void displayStudentRecord(Student *s){
    if (s != NULL){                          //make sure the record is not empty
        cout << (*s).firstName << " " << (*s).lastName << endl;
        cout << "Student Number: " << (*s).studentNumber << endl;
        cout << "NSID: " << (*s).NSID << endl;
        cout << "assignments: " << endl;
        int i;
        for (i = 0; i < 10; i++){            //the assignments fied actually contains an array, so I have to use index
            cout << i + 1 << ": " << (*s).assignments[i] << endl;
        }
        cout << "Midterm: " << (*s).midterm << endl;
        cout << "Final:" << (*s).final << endl;
    }
}
/*
---
Algorithm copyString(s)
This is a helper function, to ensure that we never make a
mistake copying a C-string.  It's not part of the Student ADT Interface
Pre:    s is a reference to a CString
Post:   allocates new memory for a copy of s
Return: reference to the new copy

*/
char *copyString(char *s){
    char *copy;
    copy = new char[strlen(s) + 1];
    strcpy (copy, s); //in strcpy, two parameters are both pointers
    return copy;
}
/*
---
Algorithm readStudentRecordFromConsole()
Pre:    nothing
Post:   creates new student record and populates fields from console
Return: refToStudent -- newly created student record
*/
Student *readStudentRecordFromConsole(){
    char firstName[100];                       //use temporary variables to store information
    char lastName[100];
    char NSID[100];
    float midterm;
    float final;
    Student *newStudent = createStudentRecord();
    if (newStudent != NULL){
        cout << "Enter fisrtName: " << endl;
        cin.getline(firstName, 100);
        (*newStudent).firstName = copyString(firstName);  //call the copyString function to store char array into record
        cout << "Enter lastName: " << endl;
        cin.getline(lastName, 100);
        (*newStudent).lastName = copyString(lastName);

        cout << "Enter student number: " << endl;
        cin >> (*newStudent).studentNumber;
        cin.ignore();                    // use cin.ignore to make sure cin does not interfere with cin.getline
        cout << "Enter NSID: " << endl;
        cin.getline(NSID, 100);
        (*newStudent).NSID = copyString(NSID);
        cout << "Enter 10 grades for assignemnts: " << endl;
        (*newStudent).assignments = new float[10];
        int i = 0;
        for (i = 0; i < 10; i++){
            cin >> (*newStudent).assignments[i];
        }
        cout << "Enter mideterm grade: " << endl;
        cin >> midterm;
        (*newStudent).midterm = midterm;
        cout << "Enter final grade: " << endl;
        cin >> final;
        cin.ignore();                //make sure the last cin does not interfere with the firrt cin.getline in the next loop
        (*newStudent).final = final;
    }
    return newStudent;
}
/*
---
Algorithm ChangeAssignmentGradeForStudent(s, a, g)
Pre:    s :: refToStudent
        a :: Integer -- assignment number
        g :: Integer -- amount to add to grade
Post:   adds g marks to assignment number a for student s
Return: nothing
*/
void ChangeAssignmentGradeForStudent(Student *s, int a, float g){
    if (s != NULL){
        (*s).assignments[a-1] = (*s).assignments[a-1] + g;     //assign the grade to the correct position in the correct field
    }
}
/*
---
Algorithm ChangeExamGradeForStudent(s, x, e)
Pre:    s :: refToStudent
        x :: Char -- 'M' if midterm, 'F' if final
        e :: Integer -- amount to add to exam grade
Post:   adds e marks to exam (Midterm or Final) for student s
Return: nothing
*/
void ChangeExamGradeForStudent(Student *s, char x, int g){
        if (s != NULL){
            if (x == 'M'){                       //check the exam type
                (*s).midterm = (*s).midterm + g; //change the corresponding grade
            }
            else if (x == 'F'){
                (*s).final = (*s).final + g;
            }
        }
    }

/*
---
Algorithm calculateAverageGrade(s)
Pre:    s :: refToStudent
Post:   calculates student average final grade
Return: Float -- final average grade for student

*/
float calculateAverageGrade(Student *s){
    if (s != NULL){
        float midterm = (*s).midterm;    //need to multiply with weight
        float final = (*s).final;
        float assignmentTotal = 0;
        for (int i = 0; i < 10; i++){
            assignmentTotal = assignmentTotal + (*s).assignments[i]; //calculate the sum of all assignments
        }
        assignmentTotal = assignmentTotal / 10;
        return midterm * 0.25 + final * 0.45 + assignmentTotal * 0.3;  //return the average grade
    }
    else{
        return 0;
    }
}

/*
---
Algorithm main()
Pre:    nothing
Post:   create 10 students, get info from console, print students, calculate class average
Return: nothing
*/



