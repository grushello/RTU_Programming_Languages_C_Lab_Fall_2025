// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;
  char filename[100];
  char line[256];

  printf("Please, enter the file name\n");
  scanf("%s.txt", &filename);
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error opening the file.");
    return 1;
  }
  fprintf(fp, "gagagagaga\nahahahhahahaha\nXDXDXDXDXD\n");
  fclose(fp);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening the file.");
    return 1;
  }  
  int lineNumber = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf(line);
    lineNumber++;
  }
  printf("number of lines: %d\n", lineNumber);
  fclose(fp);
  // TODO: 5. Open file again for reading (mode = "r")
  // TODO: 6. Use fgets() in a loop to read and print each line to the console
  // TODO: 7. Close the file

  // BONUS: ask user for filename instead of using default "data.txt"
  // BONUS: count number of lines read

  return 0;
}
