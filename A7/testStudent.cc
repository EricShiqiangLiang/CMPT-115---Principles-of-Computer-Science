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

int main(){
Student *student;
student = createStudentRecord();
displayStudentRecord(student);
student = readStudentRecordFromConsole(); //input assignment grade:0 100 100 100 100 100 100 100 100 100
displayStudentRecord(student);            //input midterm grade:0  final exam grade:100
calculateCourseGrade(student);            //final grade should be 72 B
displayFinalGrade(student);
cout << key(student) << endl;
changeAssignmentGradeForStudent(student, 0, 100);
changeExamGradeForStudent(student, 'M', 100);
calculateCourseGrade(student);            //update finalNumeric and finalLetter
displayFinalGrade(student);               //final grade should be 100 A
}
