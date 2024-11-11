//Let's Code--Shahid
#include <stdio.h>

int main() {
    // Define nightly rates for each room (index 0 is unused for simplicity)
    int room_rates[] = {0, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550};
    
    int N;
    // Input number of booking requests
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int R, S, E;
        // Read room number R, start date S, and end date E
        scanf("%d %d %d", &R, &S, &E);
        
        // Check if the booking is valid
        if (S > E) {
            printf("Invalid booking\n");
        } else {
            // Calculate the total cost for the stay
            int nights = E - S + 1;
            int total_cost = nights * room_rates[R];
            printf("%d\n", total_cost);
        }
    }
    
    return 0;
}
