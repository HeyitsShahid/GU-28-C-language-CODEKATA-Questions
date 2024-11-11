//Let's Code--Shahid
#include <stdio.h>

int count_words(char arr[]) {
    int count = 0;
    int in_word = 0;  // Flag to track if we're inside a word
    int i = 0;

    while (arr[i] != '\0') {  // Iterate until null terminator
        if (arr[i] != ' ') {  // If current character is not a space
            if (in_word == 0) {  // Check if we are at the start of a new word
                count++;  // Increment word count
                in_word = 1;  // Set in_word flag
            }
        } else {
            in_word = 0;  // If we encounter a space, reset in_word flag
        }
        i++;  // Move to the next character
    }

    return count;
}

int main() {
    char arr[101];

    // Read the input string without displaying a prompt
    fgets(arr, sizeof(arr), stdin);

    // Count the words
    int word_count = count_words(arr);

    // Output only the word count
    printf("%d\n", word_count);

    return 0;
}
