//Let's Code--Shahid
#include <stdio.h>
#include <limits.h>

int main() {
    long long n;
    int fits_short = 0, fits_unsigned_short = 0, fits_unsigned_long = 0, fits_long = 0;

    // Reading the input
    scanf("%lld", &n);

    // Check if the number fits in short int
    if (n >= SHRT_MIN && n <= SHRT_MAX) {
        fits_short = 1;
    }

    // Check if the number fits in unsigned short int
    if (n >= 0 && n <= USHRT_MAX) {
        fits_unsigned_short = 1;
    }

    // Check if the number fits in unsigned long int
    if (n >= 0 && n <= ULONG_MAX) {
        fits_unsigned_long = 1;
    }

    // Check if the number fits in long int
    if (n >= LONG_MIN && n <= LONG_MAX) {
        fits_long = 1;
    }

    // Output results in the correct order
    if (fits_short) {
        printf("Fits in short int\n");
    }
    if (fits_long) {
        printf("Fits in long int\n");
    }
    if (fits_unsigned_short) {
        printf("Fits in unsigned short int\n");
    }
    if (fits_unsigned_long) {
        printf("Fits in unsigned long int\n");
    }

    // Print "Does not fit in any type" if it only fits in long int
    if (!fits_short && !fits_unsigned_short && !fits_unsigned_long && fits_long) {
        printf("Does not fit in any type\n");
    }

    // Check if it fits in none of the specified types
    if (!fits_short && !fits_unsigned_short && !fits_unsigned_long && !fits_long) {
        printf("Does not fit in any type\n");
    }

    return 0;
}
