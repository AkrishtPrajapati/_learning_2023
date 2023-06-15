#include <stdio.h>

void printExponent(double num) {
    // Convert the double number to an integer pointer
    int* ptr = (int*)&num;

    // Get the bits representation of the double number
    int bits = *ptr;

    // Extract the exponent bits using bit manipulation
    int exponent = (bits >> 20) & 0x7FF;

    // Print the exponent in hexadecimal and binary format
    printf("Exponent in hexadecimal: 0x%X\n", exponent);
    printf("Exponent in binary: 0b");
    for (int i = 10; i >= 0; i--) {
        int bit = (exponent >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}
