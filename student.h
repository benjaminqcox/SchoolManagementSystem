#ifndef STUDENT_H
#define STUDENT_H

#include "subject.h"
#include <stdbool.h>
typedef struct Grade
{
    char gradeAchieved;
    Subject_t * subject;

} Grade_t;

typedef struct Student
{
    unsigned short int id;
    char * name;
    Grade_t ** grades;
} Student_t;


Grade_t * createStudentSubject(Subject_t * subject);

Grade_t ** createStudentSubjects(Subject_t ** subjects);

Student_t * createStudent(char * name, Subject_t ** subjects);

Grade_t * findStudentSubject(Student_t ** student, Subject_t * subject);

bool updateStudentGrade(Student_t ** student, Subject_t * subject, char grade);

#endif