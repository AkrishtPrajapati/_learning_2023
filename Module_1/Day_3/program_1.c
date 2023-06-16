#include <stdio.h>

void print_numbers(int n) {
  for (int i = 1; i <= n; i++) {
    printf("%d", i);
  }
}

void print_spaces(int n) {
  for (int i = 1; i <= n; i++) {
    printf(" ");
  }
}

void print_pattern(int n) {
  for (int i = 1; i <= n; i++) {
    print_numbers(i);
    print_spaces(n - i);
    print_numbers(n - i);
    printf("\n");
  }
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  print_pattern(n);

  return 0;
}