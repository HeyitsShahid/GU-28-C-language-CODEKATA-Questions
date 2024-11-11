//Let's Code--Shahid
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int a;
        float b;
        char op;
        double c, result;

        scanf("%d %f %c %lf", &a, &b, &op, &c);

        // Perform the operation based on op
        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b != 0) {
                    result = a / b;
                } else {
                    result = c;  // Set result to c directly when division by zero
                    printf("%.2lf\n", result);
                    continue;  // Skip the addition step
                }
                break;
            default:
                continue;  // Skip this iteration if invalid operator
        }
        
        // Add the result to c
        result += c;

        // Print the result with two decimal places
        printf("%.2lf\n", result);
    }

    return 0;
}
