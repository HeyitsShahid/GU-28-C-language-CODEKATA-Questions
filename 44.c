//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Read the size of the array
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read elements into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of even-indexed elements
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += arr[i];
    }

    // Store the sum in the first element of the array
    *arr = sum;

    // Print the modified array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
