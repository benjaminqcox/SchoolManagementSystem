#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "subject.h"

int main()
{
    Student_t ** allStudents = NULL;
    Subject_t ** allSubjects = (Subject_t **)malloc(2*sizeof(Subject_t*));
    Subject_t * sub1 = createSubject("Maths", createTeacher("Smith"));
    Subject_t * sub2 = createSubject("English", createTeacher("Johnson"));
    allSubjects[0] = sub1;
    allSubjects[1] = sub2;

    //Subject_t * found = findSubject(allSubjects, "English");
    
    printf("Found subject = %s\n", allSubjects[1]->name);
    //printf("Found subject = %s\n", sub2->name);
    return 0;
}