//=============================================================
// Name        : student.h
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

//Definition of StudentRecord ADT
struct Student{
    char *firstName;
    char *lastName;
    int studentNumber;
    char *NSID;
    float *assignments;
    float midterm;
    float final;
};
/*
Algorithm createStudentRecord()
Pre: none
Post: student record created
Return: reference to newly created student record

    refToStudent s <- allocate new Student
    return s
*/
Student *createStudentRecord();

/*
---
Algorithm destroyStudentRecord(s)
Pre:    s :: refToStudent
Post:   Student record s and fields deallocated
Return: nothing
---
*/
void destroyStudentRecord(Student*);
/*
Algorithm displayStudentRecord(s)
Pre:    s :: refToStudent
Post:   fields in s displayed to console
Return: nothing
*/
void displayStudentRecord(Student*);
/*
---
Algorithm copyString(s)
This is a helper function, to ensure that we never make a
mistake copying a C-string.  It's not part of the Student ADT Interface
Pre:    s is a reference to a CString
Post:   allocates new memory for a copy of s
Return: reference to the new copy

*/
char *copyString(char*);
/*
---
Algorithm readStudentRecordFromConsole()
Pre:    nothing
Post:   creates new student record and populates fields from console
Return: refToStudent -- newly created student record
*/
Student *readStudentRecordFromConsole();
/*
---
Algorithm ChangeAssignmentGradeForStudent(s, a, g)
Pre:    s :: refToStudent
        a :: Integer -- assignment number
        g :: Integer -- amount to add to grade
Post:   adds g marks to assignment number a for student s
Return: nothing
*/
void ChangeAssignmentGradeForStudent(Student*, int, float);
/*
---
Algorithm ChangeExamGradeForStudent(s, x, e)
Pre:    s :: refToStudent
        x :: Char -- 'M' if midterm, 'F' if final
        e :: Integer -- amount to add to exam grade
Post:   adds e marks to exam (Midterm or Final) for student s
Return: nothing
*/
void ChangeExamGradeForStudent(Student*, char, int);
/*
---
Algorithm calculateAverageGrade(s)
Pre:    s :: refToStudent
Post:   calculates student average final grade
Return: Float -- final average grade for student

*/
float calculateAverageGrade(Student*);


