// week5_task2_struct_save_load.c
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming
// TODO: Complete function implementations and file handling logic.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.txt";

    save_student(s1, filename);
    load_student(filename);
    printf("%s\n%d\n%f\n", s1.name, s1.age, s1.gpa);

    return 0;
}

// TODO: Implement save_student()
// Open file for writing, check errors, write fields, then close file
void save_student(Student s, const char *filename) {
    FILE* fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("error opening file for writing");
        return;
    }
    fprintf(fp, "%s\n%d\n%f", s.name, s.age, s.gpa);
}

// TODO: Implement load_student()
// Open file for reading, check errors, read fields, then close file
Student load_student(const char *filename) {
    Student s;
    FILE* fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("error opening file for reading");
        return;
    }
    fscanf("%s\n%d%f", &s.name, &s.age, &s.gpa);
    return s;
}
