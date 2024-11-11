//Let's Code--Shahid
#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    int current_employee = -1;  // -1 indicates the room is not reserved

    for (int i = 0; i < N; i++) {
        char command[10];
        int employee_id;
        
        scanf("%s %d", command, &employee_id);

        if (strcmp(command, "RESERVE") == 0) {
            if (current_employee == -1) {
                // Reserve the room for this employee
                current_employee = employee_id;
                printf("Room Reserved\n");
                goto next_command;
            } else if (current_employee == employee_id) {
                printf("Room Already Reserved by Employee %d\n", current_employee);
                goto next_command;
            } else {
                printf("Room Already Reserved by Employee %d\n", current_employee);
                goto next_command;
            }
        }

        if (strcmp(command, "FREE") == 0) {
            if (current_employee == employee_id) {
                // Free the room
                current_employee = -1;
                printf("Room Freed\n");
                goto next_command;
            } else {
                printf("No Reservation to Free\n");
                goto next_command;
            }
        }

    next_command:
        // Go to the next command
        continue;
    }

    return 0;
}
