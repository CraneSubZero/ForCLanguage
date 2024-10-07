#include <stdio.h>   // Required for input/output functions like printf() and scanf()
#include <stdlib.h>  // Required for functions like rand() and srand()
#include <time.h>    // Required to use time() for seeding the random number generator

int main() {
    char playAgain;   // Variable to store if the user wants to play again

    // Start the game loop, allowing the user to play multiple times
    do {
        int values[3];          // Array to store 3 randomly generated numbers
        int guess;              // Variable to store the user's guess
        int predicted = 0;      // Counter to track how many numbers the user has predicted correctly
        int attempts = 3;       // Number of attempts the user has to guess
        int used[3] = {0, 0, 0}; // Array to track which numbers have been guessed correctly (initialized to 0)

        // Initialize random number generator using the current time as the seed.
        // This ensures that the random numbers are different in each game.
        srand(time(0));

        // Inform the user that 3 random numbers between 1 and 10 are being generated
        printf("Hello. I am generating 3 numbers from 1 to 10.\n");
        
        // Loop to generate 3 random numbers and store them in the 'values' array
        for (int i = 0; i < 3; i++) {
            values[i] = (rand() % 10) + 1;  // Generate a random number between 1 and 10
        }

        // Inform the user to start guessing the generated numbers
        printf("Can you take a guess what those numbers are?\n");
        printf("You have 3 attempts.\n");

        // Inner loop to allow the user to guess 3 times
        while (attempts > 0) {
            printf("Enter your guess [Attempts: %d]: ", attempts);  // Display the number of remaining attempts
            scanf("%d", &guess);  // Read the user's guess

            // Check if the guess matches any number in the array that hasn't been guessed yet
            int correct_guess = 0;  // Flag to track if the guess is correct
            for (int i = 0; i < 3; i++) {
                if (guess == values[i] && used[i] == 0) {  // If the guess matches and hasn't been guessed yet
                    predicted++;           // Increment the predicted counter
                    used[i] = 1;           // Mark the number as guessed
                    correct_guess = 1;     // Set flag to indicate a correct guess
                    break;                 // Exit the loop as the guess is correct
                }
            }

            // Provide feedback based on the correctness of the guess
            if (correct_guess) {
                printf("You have predicted %d number(s).\n", predicted);  // Display the updated number of correct predictions
            } else {
                printf("You have predicted %d number(s).\n", predicted);  // Inform the user that the prediction count remains the same
            }
            printf("\n");

            attempts--;  // Decrement the number of attempts left
        }

        // After the loop ends, display the stored values (the correct numbers)
        printf("You have zero attempts left. Thanks for playing.\n");
        printf("The numbers stored were: %d %d %d\n", values[0], values[1], values[2]);
        printf("\n");

        // Ask the user if they want to play the game again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);  // Get the user's input (the space before %c consumes any leftover newline)
        printf("\n");

    } while (playAgain == 'y' || playAgain == 'Y');  // Loop and replay the game if the user inputs 'y' or 'Y'

    // End the program with a thank you message
    printf("Thanks for playing!\n");
    return 0;  // Exit the program successfully
}