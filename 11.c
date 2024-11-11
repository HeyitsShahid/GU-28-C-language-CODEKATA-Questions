//Let's Code--Shahid
#include <stdio.h>

void print_binary(unsigned char value) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
    printf("\n");
}

unsigned char manipulate_packet_header(unsigned char header) {
    // Toggle the Packet Type
    header ^= 0b1;
    printf("New Header in Decimal: %d\n", header);
    printf("New Header in Binary: ");
    print_binary(header);

    // Set the Priority to High
    header |= 0b10;

    // Clear the Encryption Status
    header &= 0b11110111;
    printf("New Header after clearing encryption status: %d\n", header);
    printf("New Header in Binary: ");
    print_binary(header);

    // Check if an error is detected
    if (header & 0b1000) {
        printf("Error Detected: Yes\n");
    } else {
        printf("Error Detected: No\n");
    }

    // Shift the header left by 1 bit
    unsigned int new_header = (unsigned int)header << 1;  // Use unsigned int to allow for larger values
    printf("Header after Left Shift by 1 Bit: %d\n", new_header);
    printf("New Header in Binary: ");
    print_binary((unsigned char)new_header);  // Only prints the lowest 8 bits

    return header;
}

int main() {
    unsigned char initial_header = 210;
    manipulate_packet_header(initial_header);
    return 0;
}
