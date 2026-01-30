#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int secretNumber, userGuess;
    int attempts = 0;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    secretNumber = rand() % 100 + 1;

    cout << "🎮 Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess < secretNumber) {
            cout << "Too low! Try again.\n" << endl;
        } else if (userGuess > secretNumber) {
            cout << "Too high! Try again.\n" << endl;
        } else {
            cout << "🎉 Congratulations!" << endl;
            cout << "You guessed the correct number in "
                 << attempts << " attempts." << endl;
        }

    } while (userGuess != secretNumber);

    return 0;
}
