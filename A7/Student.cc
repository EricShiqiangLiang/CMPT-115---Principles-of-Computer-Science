// file Student.cc
// CMPT 115
// Assignment 7 Exercise 3
//Name: Shiqiang Liang
//NSID: shl083
//Student#: 11208088
//Course: CMPT 115-04 1:00 pm-2:20 Tuesday and Thursday
//Assignment: 7
//Exercise: 3

#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;



//////////////////////////////////////////////////////////////////
//Algorithm createStudentRecord()
//Pre: none
//Post: student record created
//Return: reference to newly created student record

Student *createStudentRecord() {
  Student * s = new Student;
  s->firstName = NULL;
  s->lastName = NULL;
  s->NSID = NULL;
  s->studentNumber = -1;  
  s->midterm = -1;  
  s->finalg = -1;  
  for (int i = 0; i < 10; i++) {
    s->assignments[i] = -1;
  }
  return s;
}


//////////////////////////////////////////////////////////////////
//Algorithm destroyStudentRecord(s)
//Pre:	s :: refToStudent
//Post:	Student record s and fields deallocated
//Return:	nothing
//
void destroyStudentRecord(Student *s) {
  if (s != NULL) {
    if (s->firstName != NULL) delete [] s->firstName;
    if (s->lastName != NULL) delete [] s-> lastName;
    if (s->NSID != NULL) delete [] s-> NSID;
    delete s;
  }
  else {
    cout << "You tried to destroy a NULL record!" 
         << "  Do.  Or do not.  There is no try."  << endl;
  }
}


//////////////////////////////////////////////////////////////////
//Algorithm displayCString(s)
//Pre:  s :: refToChar
//Post:  s displayed to console, unless s is NULL
//Return: nothing
void displayCString(const char *s) {
  if (s == NULL) {
    cout << "null string.  We never talk any more.";
  }
  else {
    cout << s;
  }
}


//---
//////////////////////////////////////////////////////////////////
//Algorithm displayStudentRecord(s)
//Pre:  s :: refToStudent
//Post:  fields in s displayed to console
//Return: nothing

void displayStudentRecord(Student *s) {
  if (s != NULL) {
    cout << "Name: ";
    displayCString(s->firstName);
    cout << " ";
    displayCString(s->lastName);
    cout << endl;
    cout << "Student Number: " << s->studentNumber << endl;
    cout << "NSID: ";
    displayCString(s->NSID);
    cout << endl;

    cout << "Assignments: " << endl;
    for (int i = 0; i < 10; i++) {
      cout << "A" << i << ": " << s->assignments[i] << endl;
    }
  
    cout << "Midterm: " << s->midterm << endl;
    cout << "Final: " << s->finalg << endl;
  }
  else {
    cout << "Displaying a NULL Student reference.  "
         << "Ain't nobody got time for that." << endl;
  }
}


//////////////////////////////////////////////////////////////////
//Algorithm copyString(s)
//This is a helper function, to ensure that we never make a 
//mistake copying a C-string.  It's not part of the Student ADT Interface
//Pre:  s is a reference to a CString
//Post:   allocates new memory for a copy of s
//Return: reference to the new copy
char *copyString(const char *s) {
    char * copy = new char[strlen(s) + 1];
    strcpy(copy, s);
    return copy;
}


//////////////////////////////////////////////////////////////////
//Algorithm readStudentRecordFromConsole()
//Pre:  nothing
//Post:  creates new student record and populates fields from console
//Return: refToStudent -- newly created student record
//
Student *readStudentRecordFromConsole() {
  char temp[100];

  Student *newStudent = createStudentRecord();  // 2016/02/09 error correction 

  if (newStudent == NULL) {
    cout << "heap returned NULL.  I've got a bad feeling about this." << endl;
  }

  cin >> temp;
  newStudent->firstName = copyString(temp);

  cin >> temp;
  newStudent->lastName = copyString(temp);

  cin >> newStudent->studentNumber;

  cin >> temp; 
  newStudent->NSID = copyString(temp);

  for (int i = 0; i < 10; i++) {
    cin >> newStudent->assignments[i];
  }
  
  cin >> newStudent->midterm;
  cin >> newStudent->finalg;

  return newStudent;
}


//////////////////////////////////////////////////////////////////
//Algorithm changeAssignmentGradeForStudent(s, a, g)
//Pre:  s :: refToStudent
//    a :: Integer -- assignment number
//    g :: Integer -- amount to add to grade
//Post:  adds g marks to assignment number a for student s
//Return: nothing
void changeAssignmentGradeForStudent(Student *s, int a, int g) {

  if (s == NULL) {
    cout << "Asked to change assignment for NULL student."
         << "  Seriously?" << endl;
  }
  else {
    s->assignments[a] = s->assignments[a] + g;
  }
}

//////////////////////////////////////////////////////////////////
//Algorithm changeExamGradeForStudent(s, x, e)
//Pre:  s :: refToStudent
//    x :: Char -- 'M' if midterm, 'F' if final
//    e :: Integer -- amount to add to exam grade
//Post:  adds e marks to exam (Midterm or Final) for student s
//Return: nothing
//
void changeExamGradeForStudent(Student *s, char x, int e) {
  if (s == NULL) {
    cout << "Asked to change exam for NULL student"
         << "  Who you gonna call?"  << endl;
  }
  else if (x == 'M') {
      s->midterm = s->midterm + e;
  }
  else if (x == 'F') {
      s->finalg = s->finalg + e;
  }
  else {
    cout << "Invalid exam specifier: " << x 
         << ".  Would you like to buy a vowel?"  << endl;
  }
}


//////////////////////////////////////////////////////////////////
//Algorithm calculateCourseGrade(s)
//Pre:  s :: refToStudent
//Post:  calculates student average final grade, store grade in finalLetter
//      and finalNumeric field
//Return:  Float -- final average grade for student
//
///////////////Assignment 7 Exercise 3 changes here/////////////////////////
///////////////Assignment 7 Exercise 3 changes here/////////////////////////
float  calculateCourseGrade(Student *s) {
  if (s == NULL) {
    cout << "Asked to calculate course grade for NULL student." 
         << "  No, you can't do that."  << endl;
    return 0;
  }
  else {
    float midterm = s->midterm * 25;
    float finalg = s->finalg * 45;
    float assignmentTotal = 0;
    float grade;
  
    for (int i = 0; i < 10; i++) {
      assignmentTotal = assignmentTotal + s->assignments[i];
    }
  
    assignmentTotal = assignmentTotal * 3;
    grade = (midterm + finalg + assignmentTotal)/100;
    s->finalNumeric = grade;
    if (grade >= 80){
      s->finalLetter = 'A';
    }
    else if (grade >= 70){
      s->finalLetter = 'B';
    }
    else if (grade >= 60){
      s->finalLetter = 'C';
    }
    else if (grade >= 50){
      s->finalLetter = 'D';
    }
    else{
      s->finalLetter = 'F';
    }
  
    return grade;
  }
}

//////////////////////////////////////////////////////////////////
//Algorithm displayFinalGrade(s)
//Pre:  s :: refToStudent
//Post:  print student and final grade
//Return: nothing
///////////////Assignment 7 Exercise 3 changes here/////////////////////////
///////////////Assignment 7 Exercise 3 changes here/////////////////////////
void displayFinalGrade(Student *s) {
  if(s == NULL){
    cout << "The record is empty." << endl;
  }
  else {
    cout << "Student Number: " << s->studentNumber << endl;
    cout << "Final Numeric Grade: " << s->finalNumeric<< endl;
    cout << "Final Letter Grade: " << s->finalLetter << endl;
  }
}

//////////////////////////////////////////////////////////////////
//Algorithm key(s)
//Pre: s :: refToStudent
//Return: returns the student number
///////////////Assignment 7 Exercise 3 changes here/////////////////////////
///////////////Assignment 7 Exercise 3 changes here/////////////////////////
int key(Student *s){
  if(s == NULL){
    cout << "There is no student number in empty record. " << endl;
    return 0;
  }
  else {
    return s->studentNumber;
  }
}