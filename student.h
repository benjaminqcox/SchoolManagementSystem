#ifndef STUDENT_H
#define STUDENT_H

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

Student_t * createStudent(char * name, Grade_t ** subjects);

#endif