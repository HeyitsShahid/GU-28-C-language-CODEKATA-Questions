//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_every_third_char(char *str) {
    int length = strlen(str);
    char *src = str;     // Pointer to traverse the original string
    char *dest = str;    // Pointer to build the modified string
    int count = 0;       // Position counter to track every third character

    for (int i = 0; i < length; i++) {
        count++;
        if (count % 3 != 0) {
            *dest = *src;  // Copy character if not in a "third" position
            dest++;
        }
        src++;             // Move to the next character in the original string
    }

    *dest = '\0';          // Null-terminate the modified string
}

int main() {
    char *str = (char *)malloc(101 * sizeof(char)); // Allocate memory for the string
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read the input string
    scanf("%100s", str);

    // Remove every third character
    remove_every_third_char(str);

    // Print the modified string
    printf("%s\n", str);

    // Free allocated memory
    free(str);

    return 0;
}
