#include <stdio.h>

#define DEBUG  // Define DEBUG to enable debug messages

#ifdef DEBUG
    #define DEBUG_PRINT(msg, value) printf("Debug: " msg " %d\n", value)
#else
    #define DEBUG_PRINT(msg, value)
#endif

int main() {
    int num;

    // Read an integer from standard input
    scanf("%d", &num);

    // Debug message for input value
    DEBUG_PRINT("Input value is", num);

    // Check if the number is even or odd
    if (num % 2 == 0) {
        printf("The number is even\n");
    } else {
        printf("The number is odd\n");
    }

    return 0;
}
