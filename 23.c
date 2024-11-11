//Let's Code--Shahid
#include <stdio.h>

int transformArray(int arr[], int n, int x, int y) {
    // Step 1: Element Replacement
    for (int i = 0; i < n; i++) {
        if (arr[i] % x == 0) {
            arr[i] = y;
        }
    }

    // Step 2: Incremental Sum Update
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i] + arr[i + 1];
    }

    // Step 3: Find Maximum Value
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    return max_value;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x, y;
    scanf("%d %d", &x, &y);

    int result = transformArray(arr, n, x, y);
    printf("%d\n", result);

    return 0;
}
