#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    int attemptCount = 0;

    // Display a welcome message
    cout << "******************************\n";
    cout << "* Welcome to the Guessing Game! *\n";
    cout << "******************************\n";
    cout << "I have selected a random number between 1 and 100.\n";
    cout << "Your task is to guess the number!\n\n";

    // Main game loop
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        attemptCount++; // Increment the attempt count

        // Provide feedback to the user based on their guess
        if (userGuess > randomNumber) {
            cout << "Too high! Try again.\n\n";
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again.\n\n";
        } else {
            cout << "Congratulations! You've guessed the correct number: " << randomNumber << "\n";
            cout << "It took you " << attemptCount << " attempts to guess the correct number.\n";
        }

    } while (userGuess != randomNumber); // Continue until the user guesses correctly

    return 0;
}
