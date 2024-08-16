#include <iostream>
using namespace std;

void showCelebration() {
    cout << "  YOU WON! CONGRATULATIONS!" << endl;
}

void showLosingPic() {
    cout << "    _____   " << endl;
    cout << "   /     \\  " << endl;
    cout << "  | () () | " << endl;
    cout << "   \\  ^  /  " << endl;
    cout << "    |||||   " << endl;
    cout << "    |||||   " << endl;
    cout << "  OH NO! YOU LOST!" << endl;
}

void playGame(const char word[], int wordLength, bool& gameWon) {
    char* guessedWord = new char[wordLength + 1];
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0';

    int lives = 5;
    bool wordGuessed = false;

    while (lives > 0 && !wordGuessed) {
        cout << "Word: " << guessedWord << endl;
        cout << "Lives left: " << lives << endl;
        cout << "Enter a letter: ";

        char guess;
        cin >> guess;

        bool correctGuess = false;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess || word[i] == guess + 32 || word[i] == guess - 32) {
                guessedWord[i] = word[i];
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            lives--;
            cout << "Wrong guess! You lost a life." << endl;
        }
        else {
            cout << "Good guess!" << endl;
        }

        bool fullyGuessed = true;
        for (int i = 0; i < wordLength; i++) {
            if (guessedWord[i] == '_') {
                fullyGuessed = false;
                break;
            }
        }

        if (fullyGuessed) {
            wordGuessed = true;
        }
    }

    if (wordGuessed) {
        showCelebration();
        gameWon = true;
    }
    else {
        showLosingPic();
        gameWon = false;
    }

    delete[] guessedWord;
}

int main() {
    const char word1[] = "APPLE";
    const char word2[] = "BANANA";
    const char word3[] = "ORANGE";

    bool gameWon = true;

    while (true) {
        if (!gameWon) {
            cout << "\nYou lost! Restarting from Round 1...\n";
        }

        cout << "Welcome to Hangman!\n\n";

        cout << "Round 1:\n";
        playGame(word1, 5, gameWon);
        if (!gameWon) continue;

        cout << "\nRound 2:\n";
        playGame(word2, 6, gameWon);
        if (!gameWon) continue;

        cout << "\nRound 3:\n";
        playGame(word3, 6, gameWon);
        if (!gameWon) continue;

        cout << "\nCongratulations! You've completed all rounds!\n";
        break;
    }

    return 0;
}
