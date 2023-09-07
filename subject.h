#ifndef SUBJECT_H
#define SUBJECT_H

typedef struct Teacher
{
    unsigned short int id;
    char * name;
} Teacher_t;

typedef struct Subject
{
    unsigned short int id;
    char * name;
    Teacher_t * teacher;
    Student_t ** students;
} Subject_t;


Teacher_t * createTeacher(char * name);

Subject_t * createSubject(char * name, Teacher_t * teacher);

#endif