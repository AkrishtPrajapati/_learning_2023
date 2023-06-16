#include <stdio.h>

void find_largest_number(int n) {
  int max_digit = n % 10;
  for (int i = n / 10; i > 0; i /= 10) {
    int digit = i % 10;
    if (digit > max_digit) {
      max_digit = digit;
    }
  }

  printf("%d\n", n - max_digit);
}

int main() {
  int n;
  printf("Enter a 4 digit number: ");
  scanf("%d", &n);

  find_largest_number(n);

  return 0;
}