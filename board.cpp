#include "board.h"
#include <iostream>
#include <vector>
#include <cstdlib>

Board::Board() {
    reset();
}

Board::Board(Board& oldBoard) {
    for (int i = 0; i < 9; i++)
	board[i] = oldBoard.board[i];

    playerLetter = oldBoard.playerLetter;
    computerLetter = oldBoard.computerLetter;
    currentPlayer = oldBoard.currentPlayer;
}

void Board::draw() {
    using namespace std;
    cout << "Current game board:" << endl << endl;
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << endl;
}

void Board::reset() {
    for (int i = 0; i < 9; i++)
	board[i] = ' ';
}

void Board::setLetters(char playerLetter) {
    this->playerLetter = playerLetter;
    if (playerLetter == 'X')
	computerLetter = 'O';
    else
	computerLetter = 'X';
}

const char& Board::getPlayerLetter() const {
    return playerLetter;
}

const char& Board::getComputerLetter() const {
    return computerLetter;
}

const char& Board::getCurrentPlayer() const {
    return currentPlayer;
}

void Board::setCurrentPlayer(char player) {
    currentPlayer = player;
}

bool Board::isEmpty(int place) const {
    return board[place] == ' ';
}

/*const char& Board::getPlace(int place) const {
    return board[place];
}*/

void Board::setPlace(int place, char value) {
    // No, I'm not checking this for out-of-bounds values. Perhaps I should, or
    // perhaps I should use a Vector instead of a simple array...
    board[place] = value;
}

void Board::makeMove(int place) {
    board[place] = currentPlayer;

    if (currentPlayer == 'X')
	currentPlayer = 'O';
    else
	currentPlayer = 'X';
}


void Board::getPossibleMoves(std::vector<int>& possibleMoves) const {
    for (int i = 0; i < 9; i++)
	if (isEmpty(i))
	    possibleMoves.push_back(i);
}


/**
 * Returns a valid move from the passed list or NULL if there is no valid move.
 * It has to receive a size because only the address for the array is passed,
 * not its size.
 */
const int Board::getRandomMoveFromList(const int list[], int listSize) const {
    std::vector<int> possibleMoves;
    int i;
    for (i = 0; i < listSize; i++) {
	if (isEmpty(i))
	    possibleMoves.push_back(list[i]);
    }

    int sz = possibleMoves.size();
    if (sz != 0) {
	i = rand() % sz;
	return possibleMoves[i];
    }
    else
	return -1;
}


/*
 * Given a player's letter, this function returns true if that player has won.
 * I'm sure there's a better way to do this but right now I don't really feel
 * like thinking about it.
 */
bool Board::isWinner(const char player) const {
    return ((board[6] == player && board[7] == player && board[8] == player) || // across the top
	    (board[3] == player && board[4] == player && board[5] == player) || // across the middle
	    (board[0] == player && board[1] == player && board[2] == player) || // across the bottom
	    (board[6] == player && board[3] == player && board[0] == player) || // down the left side
	    (board[7] == player && board[4] == player && board[1] == player) || // down the middle
	    (board[8] == player && board[5] == player && board[2] == player) || // down the right side
	    (board[6] == player && board[4] == player && board[2] == player) || // diagonal
	    (board[8] == player && board[4] == player && board[0] == player)); // diagonal
}

/*
 * Return true if every space on the board has been taken. Otherwise return false.
 */
bool Board::isFull() const {
    for (int i = 0; i < 9; i++)
	if (isEmpty(i))
	    return false;

    return true;
}


int Board::evaluate(const char& player) const {
    return 0;
}