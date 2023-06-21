#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

void readComplexNumber(struct Complex* number) {
    printf("Enter the real part: ");
    scanf("%f", &(number->real));
    
    printf("Enter the imaginary part: ");
    scanf("%f", &(number->imaginary));
}

void writeComplexNumber(struct Complex number) {
    printf("The complex number is: %.2f + %.2fi\n", number.real, number.imaginary);
}

struct Complex addComplexNumbers(struct Complex number1, struct Complex number2) {
    struct Complex sum;
    
    sum.real = number1.real + number2.real;
    sum.imaginary = number1.imaginary + number2.imaginary;
    
    return sum;
}

struct Complex multiplyComplexNumbers(struct Complex number1, struct Complex number2) {
    struct Complex product;
    
    product.real = number1.real * number2.real - number1.imaginary * number2.imaginary;
    product.imaginary = number1.real * number2.imaginary + number1.imaginary * number2.real;
    
    return product;
}

int main() {
    struct Complex number1, number2, sum, product;
    
    printf("Enter the first complex number:\n");
    readComplexNumber(&number1);
    
    printf("Enter the second complex number:\n");
    readComplexNumber(&number2);
    
    sum = addComplexNumbers(number1, number2);
    product = multiplyComplexNumbers(number1, number2);
    
    printf("\n");
    writeComplexNumber(number1);
    writeComplexNumber(number2);
    writeComplexNumber(sum);
    writeComplexNumber(product);
    
    return 0;
}
