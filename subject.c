#include <stdlib.h>
#include <stdio.h>
#include "subject.h"
#include "student.h"

Teacher_t * createTeacher(char * name)
{
    // Unique id per teacher
    static unsigned short int id = 0;
    // Allocate memory equal to the size of Teacher_t and store a pointer to it
    Teacher_t * teacher = (Teacher_t *)malloc(sizeof(Teacher_t));
    // Verify memory was allocated correctly
    if (teacher == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory\n");
        exit(EXIT_FAILURE);
    }
    // Assign the id to the teacher then increment it
    teacher->id = id++;
    teacher->name = name;
    return teacher;
}

Subject_t * createSubject(char * name, Teacher_t * teacher)
{
    // Unique id per subject
    static unsigned int id = 0;
    // Allocate memory equal to the size of Subject_t and store a pointer to it
    Subject_t * subject = (Subject_t *)malloc(sizeof(Subject_t));
    // Verify memory was allocated correctly
    if (teacher == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory\n");
        exit(EXIT_FAILURE);
    }
    // Assign the id to the subject then increment it
    subject->id = id++;
    subject->name = name;
    subject->teacher = teacher;
    // Set the subjects' students memory location as opposed to a random location
    // Cannot initialise it as it is unknown how many students study this subject
    subject->students = NULL;
    return subject;
}
