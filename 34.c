//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void countVowels(char **strings, int n, int *vowelCount) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < strlen(strings[i]); j++) {
            char ch = tolower(strings[i][j]);
            switch (ch) {
                case 'a': vowelCount[0]++; break;
                case 'e': vowelCount[1]++; break;
                case 'i': vowelCount[2]++; break;
                case 'o': vowelCount[3]++; break;
                case 'u': vowelCount[4]++; break;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();  // Consume newline after integer input

    // Allocate memory for an array of string pointers
    char **strings = (char **)malloc(n * sizeof(char *));
    if (strings == NULL) {
        perror("Unable to allocate memory");
        return 1;
    }

    // Read each string and store it in dynamically allocated memory
    for (int i = 0; i < n; i++) {
        char buffer[100];
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline

        // Allocate exact memory for the string and copy from buffer
        strings[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (strings[i] == NULL) {
            perror("Unable to allocate memory for string");
            return 1;
        }
        strcpy(strings[i], buffer);
    }

    // Array to store counts of vowels: a, e, i, o, u
    int vowelCount[5] = {0};

    // Count vowels across all strings
    countVowels(strings, n, vowelCount);

    // Output the frequency of each vowel
    printf("a: %d, e: %d, i: %d, o: %d, u: %d\n", vowelCount[0], vowelCount[1], vowelCount[2], vowelCount[3], vowelCount[4]);

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
