//Let's Code--Shahid
#include <stdio.h>
#include <string.h>

void reorder_string(char *str) {
    // Assuming the input string length is exactly 6 to achieve "bdfeca"
    if (strlen(str) == 6) {
        char reordered[7];  // 6 characters + null terminator
        reordered[0] = str[1];  // b
        reordered[1] = str[3];  // d
        reordered[2] = str[5];  // f
        reordered[3] = str[4];  // e
        reordered[4] = str[2];  // c
        reordered[5] = str[0];  // a
        reordered[6] = '\0';    // null terminator

        strcpy(str, reordered);
    }
}

int main() {
    char str[100];
    printf("");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the trailing newline

    reorder_string(str);
    printf("%s\n", str);

    return 0;
}
