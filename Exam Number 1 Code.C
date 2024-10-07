#include <stdio.h>   // Required for input/output functions like printf() and getchar()
#include <stdlib.h>  // Required for functions like rand() and srand()
#include <time.h>    // Required to use time() for seeding the random number generator

int main() {
    char input;         // Variable to store the user's input
    int values[3];      // Array to store the 3 random numbers

    // Initialize the random number generator using the current time as the seed.
    // This ensures that a different sequence of random numbers is generated every time the program is run.
    srand(time(0));

    // Start a loop that will continue until the user inputs 'x'
    do {
        // Inform the user that the program is generating 3 random numbers
        printf("Hello. Generating 3 random numbers (1-10)\n");

        // Loop to generate 3 random numbers between 1 and 10
        for (int i = 0; i < 3; i++) {
            values[i] = (rand() % 10) + 1;  // Generate a random number between 1 and 10
            // Print the generated number and store it in the 'values' array
            printf("Value stored in values[%d] = %d\n", i, values[i]);
        }

        // Prompt the user to either regenerate the numbers or quit by pressing 'x'
        printf("Press any key to regenerate again. Press x to quit.\n");

        // Use getchar() to capture the user's input
        input = getchar();   // This reads a character from the input

        // Consume the newline character that is left in the input buffer after pressing enter
        // Without this, getchar() would immediately read the newline in the next loop iteration
        getchar();

    } while (input != 'x');  // Continue regenerating numbers unless the user enters 'x'

    // Inform the user that the program is terminating
    printf("Program terminated.\n");

    return 0;  // Exit the program successfully
}