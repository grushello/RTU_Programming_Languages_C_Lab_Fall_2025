// week5_task3_student_management_system.c
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming
// TODO: Implement functions to load, save, add, and list students.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
  char name[NAME_LEN];
  int id;
  float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int* count);
void list_students(Student arr[], int count);

int main(void) {
  Student students[MAX_STUDENTS];
  int count = 0;
  int choice;

  count = load_students(students);

  do {
    printf("\n=== Student Management System ===\n");
    printf("1. List students\n");
    printf("2. Add student\n");
    printf("3. Save and Exit\n");
    printf("Select an option: ");
    scanf("%d", &choice);
    getchar();  // clear newline

    switch (choice) {
      case 1:
        list_students(students, count);
        break;
      case 2:
        add_student(students, &count);
        break;
      case 3:
        save_students(students, count);
        break;
      default:
        printf("Invalid option. Try again.\n");
    }
  } while (choice != 3);

  return 0;
}

// TODO: Implement load_students()
// Open DATA_FILE, read records until EOF, return number of records loaded
int load_students(Student arr[]) {
  FILE* fp = fopen(DATA_FILE, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 0;
  }
  int i = 0;
  while (fscanf(fp, "%s\n%d\n%f\n", arr[i].name, &arr[i].id, &arr[i].gpa) == 3) {
    ++i;
  }
  fclose(fp);
  return i;
}

// TODO: Implement save_students()
// Write all students to DATA_FILE
void save_students(Student arr[], int count) {
  FILE* fp = fopen(DATA_FILE, "w");
  if (fp == NULL) {
    perror("Error opening file");
    return 0;
  }
  size_t i = 0;
  while (i < count) {
    fprintf(fp, "%s\n%d\n%f\n", arr[i].name, arr[i].id, arr[i].gpa);
    ++i;
  }
  fclose(fp);
}

// TODO: Implement add_student()
// Read input from user and append to array
void add_student(Student arr[], int* count) {
  printf("Enter new student name\n");
  scanf("%s", &arr[*count].name);

  printf("Enter new student id\n");
  scanf("%d", &arr[*count].id);

  printf("Enter new student GPA\n");
  scanf("%f", &arr[*count].gpa);
  (*count)++;
}

// TODO: Implement list_students()
// Print all students in readable format
void list_students(Student arr[], int count) {
  for (int i = 0; i < count; ++i) {
    printf("\nStudent %d info:\nname:%s\nid: %d\ngpa: %f\n\n", i+1, arr[i].name,
           arr[i].id, arr[i].gpa);
  }
}
