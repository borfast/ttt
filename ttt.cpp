/**
 * A simple Tic-Tac-Toe game.
 * The implementation borrowed a few ideas from the Tic-Tac-Toe game in chapter
 * 9 of "Invent Your Own Comptuer Games with Python, 2nd Edition"
 * http://inventwithpython.com/chapter9.html
 * In particular, the notSoStupidMove is entirely based on the AI of that game.
 */


#include <iostream>
#include <cstdlib>
#include "board.h"
#include "computer.h"
#include "ttt.h"

using namespace std;

int main() {
	Board board;
	Computer computer;
	char turn, again;
	bool playing;
	
	displayInstructions();

	while (1) {
		board.reset();
		board.setLetters(inputPlayerLetter());
		computer.setSmart(inputComputerSmartness());
		turn = whoGoesFirst();
		cout << "The " << turn << " will go first." << endl << endl;
		playing = true;
		again = '?';

		while (playing) { // The main game loop
			board.draw();

			// Who's turn is it?
			int move;

			if (turn == 'p') {
				// player's turn
				move = getPlayerMove(board);
				if (move == 9)
					break;
				board.setPlace(move, board.getPlayerLetter());
				cout << "You played " << move << endl;

				// Check if player won
				if (board.isWinner(board.getPlayerLetter())) {
					board.draw();
					cout << "Hooray! You have won the game!" << endl << endl;
					playing = false;
				} else {
					if (board.isFull()) {
						board.draw();
						cout << "The game is a tie!" << endl << endl;
						break;
					} else {
						turn = 'c';
					}
				}
			} else {
				// computer's turn
				move = getComputerMove(board, computer);
				board.setPlace(move, board.getComputerLetter());
				cout << "The computer played " << move << endl;

				if (board.isWinner(board.getComputerLetter())) {
					board.draw();
					cout << "The computer has beaten you! You lose." << endl << endl;
					playing = false;
				} else {
					if (board.isFull()) {
						board.draw();
						cout << "The game is a tie!";
						break;
					} else {
						turn = 'p';
					}
				}
			}
		}


		while (again != 'y' && again != 'n') {
			cout << "Do you want to play again? (y/n): ";
			cin >> again;
		}
		if (again == 'y')
			continue;
		else
			break;
	}

	cout << endl << "Sorry to see you go. Perhaps a nice game of Global Thermonuclear War next time?" << endl;

	return 0;
}

/**
 * Let's the player choose which letter he wants to play with.
 */
char inputPlayerLetter() {
	char letter;
	while (letter != 'X' && letter != 'O') {
		cout << "Do you want to be X or O?" << endl;
		cin >> letter;
	}
	return letter;
}

/**
 * Let's the player choose how smart he wants the computer to be.
 */
int inputComputerSmartness() {
	int smartness;
	while (smartness != 0 && smartness != 1 && smartness != 2) {
		cout << "How smart do you want the computer to be? (0-2, although 2 is not yet implemented) # " << endl;
		cin >> smartness;
	}
	return smartness;
}

/*
 * Randomly choose the player who goes first.
 */
char whoGoesFirst() {
	srand((unsigned) time(0));
	if ((rand() % 2) == 0)
		return 'c';
	else
		return 'p';
}

/**
 * Displays the instructions to the player
 */
void displayInstructions() {
	cout << "Each square on the board is represented by a number from 0 to 8:" << endl << endl;
	cout << " 0 | 1 | 2 " << endl;
	cout << "---+---+---" << endl;
	cout << " 3 | 4 | 5 " << endl;
	cout << "---+---+---" << endl;
	cout << " 6 | 7 | 8 " << endl << endl;
	cout << "Enter 9 to quit." << endl << endl;
}

int getPlayerMove(Board& board) {
	// Next move by the player
	int nextMove = 0;

	while (1) {
		cout << "What's your next move? (0-8, 9 to quit) #" << endl;
		cin >> nextMove;

		// No possibility of passing an out of bounds index to board.getPlace(), because we're short-circuiting the condition:
		// if nextMove < 1 the condition evaluates to true as a whole, so the remaining expression will not even be evaluated.
		if (nextMove < 0 || nextMove > 9 || !board.isEmpty(nextMove)) {
			cout << endl << "Invalid choice, try again." << endl << endl;
			continue;
		}

		break;
	}

	return nextMove;
}


int getComputerMove(Board& board, Computer& computer) {
	return computer.getMove(board);
}
