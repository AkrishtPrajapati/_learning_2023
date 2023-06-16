#include <stdio.h>

void find_smallest_and_largest_digits(int n, int *numbers, int *smallest_digit, int *largest_digit) {
  int max_digit = INT_MIN;
  int min_digit = INT_MAX;

  for (int i = 0; i < n; i++) {
    int digit = numbers[i];
    if (digit > max_digit) {
      max_digit = digit;
    }
    if (digit < min_digit) {
      min_digit = digit;
    }
  }

  *smallest_digit = min_digit;
  *largest_digit = max_digit;
}

int main() {
  int n;
  printf("Enter the number of numbers: ");
  scanf("%d", &n);

  int numbers[n];
  for (int i = 0; i < n; i++) {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &numbers[i]);
  }

  int smallest_digit, largest_digit;
  find_smallest_and_largest_digits(n, numbers, &smallest_digit, &largest_digit);

  if (smallest_digit == INT_MAX) {
    printf("Not Valid\n");
  } else {
    printf("Smallest digit: %d\n", smallest_digit);
    printf("Largest digit: %d\n", largest_digit);
  }

  return 0;
}