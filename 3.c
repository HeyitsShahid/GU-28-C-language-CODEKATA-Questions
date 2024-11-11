//Let's Code--Shahid
#include <stdio.h>

int main() {
    short a;
    long long b;

    // Read input for short and long long integers
    scanf("%hd", &a);
    scanf("%lld", &b);

    // Calculating and displaying results
    // Sum
    long long sum = a + b;
    printf("Sum: %lld\n", sum);

    // Difference
    long long difference = b - a;
    printf("Difference: %lld\n", difference);

    // Product
    long long product = a * b;
    printf("Product: %lld\n", product);

    // Division (only if 'a' is not zero)
    if (a != 0) {
        long long division = b / a;
        printf("Division: %lld\n", division);
    }

    return 0;
}
