//Let's Code--Shahid
#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
} ComplexNumber;

// Function to add two complex numbers
ComplexNumber add(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

// Function to subtract two complex numbers
ComplexNumber subtract(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    result.real = num1.real - num2.real;
    result.imaginary = num1.imaginary - num2.imaginary;
    return result;
}

// Function to multiply two complex numbers
ComplexNumber multiply(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    result.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
    result.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
    return result;
}

// Function to divide two complex numbers
ComplexNumber divide(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    float denominator = num2.real * num2.real + num2.imaginary * num2.imaginary;
    
    if (denominator == 0) {
        printf("Division by zero error.\n");
        result.real = 0;
        result.imaginary = 0;
        return result;
    }
    
    result.real = (num1.real * num2.real + num1.imaginary * num2.imaginary) / denominator;
    result.imaginary = (num1.imaginary * num2.real - num1.real * num2.imaginary) / denominator;
    
    return result;
}

// Function to print a complex number
void printComplexNumber(ComplexNumber num) {
    if (num.imaginary >= 0) {
        printf("%.2f + %.2fi\n", num.real, num.imaginary);
    } else {
        printf("%.2f - %.2fi\n", num.real, -num.imaginary);
    }
}

int main() {
    ComplexNumber num1, num2;
    
    // Input the first complex number
    scanf("%f %f", &num1.real, &num1.imaginary);
    
    // Input the second complex number
    scanf("%f %f", &num2.real, &num2.imaginary);
    
    // Perform and print addition
    ComplexNumber resultAdd = add(num1, num2);
    printf("Addition: ");
    printComplexNumber(resultAdd);
    
    // Perform and print subtraction
    ComplexNumber resultSub = subtract(num1, num2);
    printf("Subtraction: ");
    printComplexNumber(resultSub);
    
    // Perform and print multiplication
    ComplexNumber resultMul = multiply(num1, num2);
    printf("Multiplication: ");
    printComplexNumber(resultMul);
    
    // Perform and print division
    ComplexNumber resultDiv = divide(num1, num2);
    printf("Division: ");
    printComplexNumber(resultDiv);
    
    return 0;
}
