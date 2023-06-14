#include <stdio.h>

// Function to find the biggest of two numbers using if-else statements
int findBiggestIfElse(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

// Function to find the biggest of two numbers using ternary operator
int findBiggestTernary(int num1, int num2) {
    int biggest = (num1 > num2) ? num1 : num2;
    return biggest;
}
int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Using if-else
    int biggestIfElse = findBiggestIfElse(num1, num2);
    printf("Using if-else, the biggest number is: %d\n", biggestIfElse);

    // Using ternary operator
    int biggestTernary = findBiggestTernary(num1, num2);
    printf("Using ternary operator, the biggest number is: %d\n", biggestTernary);

    return 0;
}