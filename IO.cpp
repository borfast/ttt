#include <iostream>
#include "IO.h"

using namespace std;

/**
 * Let's the player choose which letter he wants to play with.
 */
char IO::inputPlayerLetter() {
    char letter = Board::EMPTY_PLACE;

    while (letter != 'X' && letter != 'O') {
        cout << "Do you want to be X or O?" << endl;
        cin >> letter;
    }

    return letter;
}

/**
 * Let's the player choose how smart he wants the computer to be.
 */
int IO::inputComputerSmartness() {
    int smartness = -1;

    while (smartness != 0 && smartness != 1 && smartness != 2) {
        cout << "How smart do you want the computer to be? (0-2, although 2 is "
                "not yet implemented) # " << endl;
        cin >> smartness;
    }

    return smartness;
}

/**
 * Displays the instructions to the player
 */
void IO::displayInstructions() {
    cout << "Each square on the board is represented by a number from 0 to 8:" << endl << endl;
    cout << " 0 | 1 | 2 " << endl;
    cout << "---+---+---" << endl;
    cout << " 3 | 4 | 5 " << endl;
    cout << "---+---+---" << endl;
    cout << " 6 | 7 | 8 " << endl << endl;
    cout << "Enter 9 to quit." << endl << endl;
}

void IO::drawBoard(Board& board) {
    using namespace std;

    cout << "Current game board:" << endl << endl;
    cout << " " << board.getPlace(0) << " | " << board.getPlace(1) << " | " << board.getPlace(2) << endl;
    cout << "---+---+---" << endl;
    cout << " " << board.getPlace(3) << " | " << board.getPlace(4) << " | " << board.getPlace(5) << endl;
    cout << "---+---+---" << endl;
    cout << " " << board.getPlace(6) << " | " << board.getPlace(7) << " | " << board.getPlace(8) << endl;
    cout << endl;
}