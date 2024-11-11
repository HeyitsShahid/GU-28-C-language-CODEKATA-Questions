//Let's Code--Shahid
#include <stdio.h>

#define CALC(a, b, c, d) ({ \
    int product = (a) * (b); \
    int sum = product + (c); \
    int result = sum / (d); \
    printf("Intermediate result of a * b: %d\n", product); \
    printf("Intermediate result of a * b + c: %d\n", sum); \
    printf("Final result of (a * b + c) / d: %d\n", result); \
    result; \
})

int main() {
    int a, b, c, d;

    // Expecting input values for a, b, c, and d without prompts
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (d == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 1;
    }

    CALC(a, b, c, d);

    return 0;
}
