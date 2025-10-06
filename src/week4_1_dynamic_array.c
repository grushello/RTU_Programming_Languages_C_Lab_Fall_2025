/*
 * week4_1_dynamic_array.c
 * Author: Viacheslav Pototskyi
 * Student ID: 241ADB183
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Students should allocate memory for an integer array, fill it with data,
 *   compute something (e.g., average), and then free the memory.
 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n;
    int *arr = NULL;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    arr = malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("memory allocation failed");
        return 1;
    }
    
    printf("now enter %d numbers to be stored\n", n);
    int sum = 0;
    double avg;
    for(int i = 0; i < n; ++i)
    {
        int number;
        scanf("%d", &number);
        arr[i] = number;
        sum += number;
    }
    avg = (double)sum / (double)n;
    printf("the sum of your numbers is: %1d, average is: %2f\n", sum, avg);
    free(arr);
    return 0;
}
