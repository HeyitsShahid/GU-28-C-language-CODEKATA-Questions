//Let's Code--Shahid
#include <stdio.h>
#include <string.h>

// Function to print the control register in binary format (as per expected output)
void printBinary(unsigned char control) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (control >> i) & 1);  // Extract each bit and print it
    }
    printf("\n");
}

// Function to grant permission (set bit to 1)
unsigned char grantPermission(unsigned char control, int deviceBit) {
    return control | (1 << deviceBit);  // Set the bit corresponding to the device to 1
}

// Function to revoke permission (set bit to 0)
unsigned char revokePermission(unsigned char control, int deviceBit) {
    return control & ~(1 << deviceBit);  // Set the bit corresponding to the device to 0
}

// Function to check if permission is granted for a device
int hasControl(unsigned char control, int deviceBit) {
    return (control >> deviceBit) & 1;  // Check if the bit corresponding to the device is set
}

// Function to combine the permissions of two users
unsigned char combinePermissions(unsigned char controlA, unsigned char controlB) {
    return controlA | controlB;  // Combine the control registers using bitwise OR
}

int main() {
    unsigned char userA, userB;

    // Input: control registers for User A and User B
    scanf("%hhu %hhu", &userA, &userB);

    // Perform operations on User A and User B's control registers
    // Operation 1: Grant Lights control to User A
    userA = grantPermission(userA, 0);  // Bit 0 corresponds to Lights
    printf("User A Control Register after Granting Lights: %d\n", userA);

    // Operation 2: Revoke Music System control from User B
    userB = revokePermission(userB, 7);  // Bit 7 corresponds to Music System
    printf("User B Control Register after Revoking Music System: %d\n", userB);

    // Operation 3: Check if User A has control over Cameras (Bit 3)
    printf("User A has control over Cameras: %s\n", hasControl(userA, 3) ? "Yes" : "No");

    // Operation 4: Combine User A and User B's permissions to create User C's control register
    unsigned char userC = combinePermissions(userA, userB);
    printf("Combined Control Register (User C): %d\n", userC);

    // Operation 5: Display the control register of User C in binary
    printf("User A Control Register in Binary: ");
    printBinary(userA);

    return 0;
}
