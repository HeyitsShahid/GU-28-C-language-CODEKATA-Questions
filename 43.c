//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>

int main() {
    int original_int;        // Declare the original integer variable
    int *ptr;                // Declare a pointer to an integer

    // Read the initial value for the original integer
    scanf("%d", &original_int);

    // Assign the address of the original integer to the pointer
    ptr = &original_int;

    // Modify the original integer value through the pointer
    *ptr += 5; // Adds 5 to the original integer's value

    // Print the modified value of the original integer
    printf("Original Integer: %d\n", original_int);

    // Dynamically allocate memory for another integer in the heap
    int *heap_int = (int *)malloc(sizeof(int));
    if (heap_int == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read the value to be assigned to the dynamically allocated integer
    scanf("%d", heap_int);

    // Print the value stored in the dynamically allocated memory
    printf("Heap Integer: %d\n", *heap_int);

    // Free the dynamically allocated memory
    free(heap_int);

    return 0;
}
