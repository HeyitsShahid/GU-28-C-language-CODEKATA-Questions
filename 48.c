//Let's Code--Shahid
#include <stdio.h>

// Function to modify the array using pointer arithmetic
void modify_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        *(arr + i) += 4;  // Modify each element by adding 4 to it
    }
}

int main() {
    int n;

    // Read the size of the array
    scanf("%d", &n);

    // Declare the array of integers
    int arr[n];

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the array before modification
    printf("Array before modification:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Modify the array using a pointer
    modify_array(arr, n);

    // Print the array after modification
    printf("Array after modification:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
