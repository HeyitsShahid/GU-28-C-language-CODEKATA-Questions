//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>

// Function to modify the array as per the requirements
void modify_array(int *arr, int n) {
    // Increase each element by the value of the next element, except for the last element
    for (int i = 0; i < n - 1; i++) {
        *(arr + i) += *(arr + i + 1);
    }

    // Swap the first and last elements
    int temp = *arr;
    *(arr) = *(arr + n - 1);
    *(arr + n - 1) = temp;
}

int main() {
    int n;

    // Read the number of elements in the array
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Initialize the array: each element is the square of its index
    for (int i = 0; i < n; i++) {
        *(arr + i) = i * i;
    }

    // Call the modify_array function to modify the array
    modify_array(arr, n);

    // Print the modified array
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
