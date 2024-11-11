//Let's Code--Shahid
#include <stdio.h>

// Function to replace vowels in the character array
void replace_vowels(char arr[], char replacement) {
    int i = 0;
    
    // Loop through each character until null terminator is found
    while (arr[i] != '\0') {
        // Check if the character is a vowel (either upper or lower case)
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' ||
            arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U') {
            // Replace vowel with the replacement character
            arr[i] = replacement;
        }
        i++;
    }
}

int main() {
    // Declare a character array with a size limit
    char arr[101];
    char replacement;

    // Read input for the string and replacement character
    printf("");
    fgets(arr, sizeof(arr), stdin);  // Use fgets to safely read input

    printf("");
    scanf(" %c", &replacement);  // Read the replacement character

    // Replace vowels in the array
    replace_vowels(arr, replacement);

    // Output the modified string
    printf(arr);
    
    return 0;
}
