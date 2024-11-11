//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Structure to hold character and its frequency
typedef struct {
    char character;
    int frequency;
} CharFreq;

// Function to compare two CharFreq structures
int compare(const void *a, const void *b) {
    CharFreq *freqA = (CharFreq *)a;
    CharFreq *freqB = (CharFreq *)b;
    
    // Sort by frequency (descending), then by character (ascending)
    if (freqB->frequency != freqA->frequency) {
        return freqB->frequency - freqA->frequency;
    }
    return freqA->character - freqB->character;
}

int main() {
    // Allocate memory for input paragraph
    char *paragraph = (char *)malloc(1000 * sizeof(char)); // Adjust size as needed
    if (paragraph == NULL) {
        perror("Unable to allocate memory for paragraph");
        return 1;
    }

    // Read the paragraph
    fgets(paragraph, 1000, stdin);

    // Initialize frequency array
    CharFreq freq[ALPHABET_SIZE] = {0};
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freq[i].character = 'a' + i; // Initialize characters a-z
        freq[i].frequency = 0; // Initialize frequency
    }

    // Count frequencies of characters
    for (int i = 0; paragraph[i] != '\0'; i++) {
        char ch = tolower(paragraph[i]);
        if (isalpha(ch)) {
            freq[ch - 'a'].frequency++;
        }
    }

    // Sort the frequency array
    qsort(freq, ALPHABET_SIZE, sizeof(CharFreq), compare);

    // Print the frequency distribution
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq[i].frequency > 0) {
            printf("%c: %d\n", freq[i].character, freq[i].frequency);
        }
    }

    // Free allocated memory
    free(paragraph);

    return 0;
}
