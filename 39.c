//Let's Code--Shahid
#include <stdio.h>

void manipulate_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            // Last element remains unchanged
            continue;
        }
        
        if (*(arr + i) % 2 == 0) {
            // Even element: multiply by the next element
            *(arr + i) *= *(arr + i + 1);
        } else if (i > 0) {
            // Odd element: divide by the previous element, if it's not the first element
            *(arr + i) /= *(arr + i - 1);
        }
    }
}

int main() {
    int n;
    
    // Read the number of elements in the array
    scanf("%d", &n);
    
    int arr[n];
    
    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Manipulate the array as per the rules
    manipulate_array(arr, n);
    
    // Print the modified array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
