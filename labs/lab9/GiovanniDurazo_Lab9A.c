#include <stdio.h> // print and scan

/*
Pseudocode

create struct with student name, number, gpa
ask for input
scan input
print input
*/

int main(void)
{
    typedef struct // structure to store student info
    {
        char firstName[30]; // student 1st name
        char lastName[30]; // student last name
        int studNum; // student number
        float gpa; // gpa
    } studentInfo;

    studentInfo student; // student info variable

    printf("Please enter the student's first name: ");
    scanf("%s", student.firstName);
    printf("Please enter the student's last name: ");
    scanf("%s", student.lastName);
    printf("Please enter the student's student number: ");
    scanf("%d", &student.studNum);
    printf("Please enter the student's GPA: ");
    scanf("%f", &student.gpa);

    printf("%s %s, student number: %d, GPA: %.3f", student.firstName, student.lastName, student.studNum, student.gpa);


    return 0;
}