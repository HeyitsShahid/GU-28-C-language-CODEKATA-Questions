//Let's Code--Shahid
#include <stdio.h>

int main() {
    char T;  // Traffic light state
    int E;   // Emergency vehicle indicator

    // Read inputs
    scanf(" %c", &T);
    scanf("%d", &E);

    // Determine the action based on the traffic light state and emergency status
    if (T == 'R') {  // Red Light
        if (E == 1) {
            printf("ALLOW EMERGENCY\n");
        } else {
            printf("STOP\n");
        }
    } else if (T == 'Y') {  // Yellow Light
        if (E == 1) {
            printf("ALLOW EMERGENCY\n");
        } else {
            printf("PREPARE TO STOP\n");
        }
    } else if (T == 'G') {  // Green Light
        if (E == 1) {
            printf("CLEAR THE WAY\n");
        } else {
            printf("PROCEED\n");
        }
    } else {
        printf("Invalid input\n");  // Edge case if T is not 'R', 'Y', or 'G'
    }

    return 0;
}
