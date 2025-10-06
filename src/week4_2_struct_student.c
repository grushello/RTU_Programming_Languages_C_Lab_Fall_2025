/*
 * week4_2_struct_student.c
 * Author: [Your Name]
 * Student ID: 241ADB183
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and grade.
 *   Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

// TODO: Define struct Student with fields: name (char[]), id (int), grade (float)
// Example:
struct Student {
    char name[50];
    int id;
    float grade;
};
int main(void) {
    struct Student s1;
    strcpy(s1.name, "Dan"), s1.id = 322, s1.grade = 5;
    struct Student s2;
    strcpy(s2.name, "Andrew"), s2.id = 52, s2.grade = 2;
    struct Student s3;
    strcpy(s3.name, "Kate"), s3.id = 420, s3.grade = 4.5;
    
    printf("Student 1 info: name: %1s, id: %2d, grade: %3.2f\n", s1.name, s1.id, s1.grade);
    printf("Student 2 info: name: %1s, id: %2d, grade: %3.2f\n", s2.name, s2.id, s2.grade);
    printf("Student 3 info: name: %1s, id: %2d, grade: %3.2f\n", s3.name, s3.id, s3.grade);
    return 0;
}
