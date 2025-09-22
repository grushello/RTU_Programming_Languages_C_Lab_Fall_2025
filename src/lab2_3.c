#include <math.h>
#include <stdio.h>

/*
    Task:
    Write a function `int is_prime(int n)` that returns 1 if n is prime,
    0 otherwise.

    In main():
      - Ask user for an integer n (>= 2)
      - If invalid, print an error
      - Otherwise, print all prime numbers up to n
*/

int is_prime(int n) {
  // Put n/2 instead of sqrt(n), because sqrt(n) won't work
  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main(void) {
  int n;

  printf("Enter an integer n (>= 2): ");
  scanf("%d", &n);
  if (n < 2) {
    printf("Error: User entered value '%d', that is < 2\n", n);
    return 1;
  }

  printf("Prime numbers up to %d:\n", n);
  for (int i = 2; i <= n; ++i) {
    if (is_prime(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}
