#include <stdio.h>
#include <unistd.h> // for sleep function

int main() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("Think of a number between 1 and 100.\n");
    printf("You have 5 seconds.\n");

    int lowerBound = 1;
    int upperBound = 100;
    int guessedNumber;
    sleep(5);

    do {
        guessedNumber = (lowerBound + upperBound) / 2;
        printf("Is your number %d? (Enter 'h' if it's higher, 'l' if it's lower, or 'c' if it's correct): ", guessedNumber);

        char response;
        scanf(" %c", &response);

        if (response == 'h') {
            lowerBound = guessedNumber + 1;
        } else if (response == 'l') {
            upperBound = guessedNumber - 1;
        } else if (response == 'c') {
            printf("Great! I guessed your number: %d\n", guessedNumber);
            break;
        } else {
            printf("Invalid input. Please enter 'h', 'l', or 'c'.\n");
        }
    } while (1);
    return 0;
}

