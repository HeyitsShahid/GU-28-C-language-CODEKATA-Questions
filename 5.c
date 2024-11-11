//Let's Code--Shahid
#include <stdio.h>

// Custom function to calculate square root using the Babylonian method
float calculate_sqrt(float number) {
    float guess = number / 2.0;
    float tolerance = 0.00001; // Define a small tolerance level for approximation

    while ((guess * guess - number) > tolerance || (number - guess * guess) > tolerance) {
        guess = (guess + number / guess) / 2.0;
    }

    return guess;
}

// Function to analyze the array (calculate average, max, min, standard deviation)
void analyze_array(int n, float arr[]) {
    float sum = 0, max = arr[0], min = arr[0];

    // Calculate sum, max, and min
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    float average = sum / n;

    // Calculate variance for standard deviation
    float variance = 0;
    for (int i = 0; i < n; i++) {
        variance += (arr[i] - average) * (arr[i] - average);
    }
    float stddev = calculate_sqrt(variance / n);

    // Output results with two decimal precision
    printf("Average: %.2f\n", average);
    printf("Maximum: %.2f\n", max);
    printf("Minimum: %.2f\n", min);
    printf("Standard Deviation: %.2f\n", stddev);
}

int main() {
    int n;

    // Input: size of the array
    scanf("%d", &n);

    // Ensure the size is within the specified range
    if (n < 1 || n > 100) {
        printf("Error: Array size must be between 1 and 100.\n");
        return 1;
    }

    // Declare the array to hold n floating-point numbers
    float arr[n];

    // Input: the floating-point numbers to populate the array
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        
        // Ensure each number is within the specified range
        if (arr[i] < -1e6 || arr[i] > 1e6) {
            printf("Error: Each number must be in the range of -1e6 to 1e6.\n");
            return 1;
        }
    }

    // Analyze the array and display the results
    analyze_array(n, arr);

    return 0;
}
