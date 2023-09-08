#include <stdlib.h>
#include <stdio.h>
#include "student.h"
#include "subject.h"

Grade_t * createStudentSubject(Subject_t * subject)
{
    // Set pointer to a memory address with a dynamically allocated size equal to the size of Grade_t
    Grade_t * addSubject = (Grade_t *)malloc(sizeof(Grade_t));
    // Check memory was allocated correctly
    if (addSubject == NULL)
    {
        fprintf(stderr, "Could allocate enough memory\n");
        exit(EXIT_FAILURE);
    }
    // Set the subject name
    addSubject->subject = subject;
    // Set the grade achieved to -1 as this will be treated as ungraded
    // Any positive number will be the grade achieved after being set
    addSubject->gradeAchieved = -1;
    return addSubject;
}

Grade_t ** createStudentSubjects(Subject_t ** subjects)
{
    // Find the number of pointers being pointed to by subjects
    unsigned short int numSubjects = sizeof(*subjects)/sizeof(Subject_t);
    // Allocate memory for that number of subjects pointers
    Grade_t ** addSubjects = (Grade_t **)malloc(numSubjects*sizeof(Grade_t *));
    // Check memory was allocated correctly
    if (addSubjects == NULL)
    {
        fprintf(stderr, "Could allocate enough memory\n");
        exit(EXIT_FAILURE);
    }
    // For each subject, create a student subject pointer and add it to add subjects
    for (int i = 0; i < numSubjects; i++)
    {
        addSubjects[i] = createStudentSubject(&(*subjects)[i]);
    }
    return addSubjects;
}

Student_t * createStudent(char * name, Subject_t ** subjects)
{
    // Keep track of the ids assigned to students (not changeable by the user)
    static unsigned short int id = 0;
    // Allocate memory equal to the size of student_t and point to it
    Student_t * newStudent = (Student_t *)malloc(sizeof(Student_t));
    // Add the current id to the student then increment it
    newStudent->id = id++;
    newStudent->name = name;
    // Add all subjects entered to the students grade
    newStudent->grades = createStudentSubjects(subjects);
    return newStudent;
}

Grade_t * findStudentSubject(Student_t ** student, Subject_t * subject)
{
    // Calculate the number of subjects a student is studying = students grades / size of grade_t
    unsigned short int numSubjects = sizeof((*student)->grades)/sizeof(Grade_t);
    // Loop through all subjects studied by student
    
    for (int i = 0; i < numSubjects; i++)
    {
        // If chosen subject found, update stored grade and return the subject
        if ((*student)->grades[i]->subject == subject)
        {
            return (*student)->grades[i];
        }
    }
    // If no subject found, return NULL
    return NULL;
}

bool updateStudentGrade(Student_t ** student, Subject_t * subject, char grade)
{
    // Find if the subject is studied by student
    Grade_t * foundSubject = findStudentSubject(student, subject);
    if (foundSubject == NULL)
    {
        // Could not update, false means did not update
        printf("Subject not found in students subjects. Could not add grade.");
        return false;
    }
    // Update grade with chosen value
    foundSubject->gradeAchieved = grade;
    // True means grade was updated
    return true;
}