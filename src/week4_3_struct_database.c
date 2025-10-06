/*
 * week4_3_struct_database.c
 * Author: Viacheslav Pototskyi
 * Student ID: 241ADB183
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Define struct Student with fields name, id, grade
struct Student {
    char name[50];
    int id;
    float grade;
};
int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }
    students = malloc(n*sizeof(struct Student));

    for(int i = 0; i < n ;++i)
    {
        printf("Enter student %d name\n", i + 1);
        scanf("%s", &students[i].name);
        printf("Enter student %d id\n", i + 1);
        scanf("%d", &students[i].id);
        printf("Enter student %d grade\n", i + 1);
        scanf("%f", &students[i].grade);
    }
    float sum = 0;
    float avg = 0;
    struct Student * topStudent = &students;
    for(int i = 0; i < n; ++i)
    {
        printf("Student %1d info: name: %2s, id: %3d, grade: %4.2f\n",
             i + 1, students[i].name, students[i].id, students[i].grade);
        sum += students[i].grade;
        if(topStudent->grade < students[i].grade)
        {
            topStudent = &students[i];
        }
    }
    avg = (float)sum/(float)n;
    printf("Average grade: %.2f\n", avg);
    printf("Top student info: name: %1s, id: %2d, grade: %3.2f\n",
             topStudent->name, topStudent->id, topStudent->grade);
    free(students);

    return 0;
}
