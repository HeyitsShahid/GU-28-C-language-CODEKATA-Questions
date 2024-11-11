//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a single string
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Function to swap the first and last strings in an array of strings
void swap_strings(char **str_list, int n) {
    if (n > 1) {
        char *temp = str_list[0];
        str_list[0] = str_list[n - 1];
        str_list[n - 1] = temp;
    }
}

int main() {
    int n;

    // Read the number of strings without any prompt
    scanf("%d", &n);

    // Allocate memory for the list of strings (pointer-to-pointer)
    char **str_list = (char **)malloc(n * sizeof(char *));
    if (str_list == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read each string and allocate memory for each one without prompts
    for (int i = 0; i < n; i++) {
        char buffer[101];  // Temporary buffer to hold the string
        scanf("%s", buffer);

        // Allocate memory for each individual string
        str_list[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (str_list[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for string %d.\n", i + 1);
            return 1;
        }
        strcpy(str_list[i], buffer);  // Copy the string to the allocated space
    }

    // Reverse each string in the list
    for (int i = 0; i < n; i++) {
        reverse_string(str_list[i]);
    }

    // Swap the first and last strings in the list
    swap_strings(str_list, n);

    // Print the modified list of strings
    for (int i = 0; i < n; i++) {
        printf("%s\n", str_list[i]);
        free(str_list[i]);  // Free the memory allocated for each string
    }

    // Free the memory allocated for the list of strings
    free(str_list);

    return 0;
}
