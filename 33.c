//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100  // Arbitrary limit on number of words for simplicity

void reverseWords(char *sentence) {
    char *words[MAX_WORDS]; // Array of pointers to store each word
    int wordCount = 0;

    // Tokenize the sentence into words
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }

    // Print words in reverse order
    for (int i = wordCount - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char *sentence;
    size_t bufferSize = 256;

    // Dynamically allocate memory for the input sentence
    sentence = (char *)malloc(bufferSize * sizeof(char));
    if (sentence == NULL) {
        perror("Unable to allocate memory");
        exit(1);
    }

    // Get the sentence input from the user without any additional prompt
    if (getline(&sentence, &bufferSize, stdin) == -1) {
        perror("Error reading input");
        free(sentence);
        exit(1);
    }

    // Remove newline character if present
    size_t len = strlen(sentence);
    if (sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    // Reverse the words in the sentence
    reverseWords(sentence);

    // Free the allocated memory
    free(sentence);

    return 0;
}
