//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Read the size of the array
    scanf("%d", &n);

    // Dynamically allocate memory for the original array
    int *original_array = (int *)malloc(n * sizeof(int));
    if (original_array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read elements into the original array
    for (int i = 0; i < n; i++) {
        scanf("%d", &original_array[i]);
    }

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", original_array[i]);
    }
    printf("\n");

    // Create a new array with double the size of the original array
    int new_size = 2 * n;
    int *copied_array = (int *)malloc(new_size * sizeof(int));
    if (copied_array == NULL) {
        fprintf(stderr, "Memory allocation failed for copied array.\n");
        free(original_array);  // Free the original array before exiting
        return 1;
    }

    // Copy the contents of the original array into the new array
    for (int i = 0; i < n; i++) {
        copied_array[i] = original_array[i];
    }
    // Set the additional elements in the copied array to 0
    for (int i = n; i < new_size; i++) {
        copied_array[i] = 0;
    }

    // Print the copied array
    printf("Copied array: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", copied_array[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(original_array);
    free(copied_array);

    return 0;
}
