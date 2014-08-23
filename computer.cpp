/*
 * File:	 Computer.cpp
 * Author: Raul Santos
 *
 * Created on December 29, 2009, 5:57 PM
 */

#include "board.h"
#include "computer.h"

#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;


// Stupid limitations of C++ const member arrays initialization... :|
const int Computer::fullBoardList[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
const int Computer::cornersList[4] = { 0, 2, 6, 8 };
const int Computer::sidesList[4] = { 1, 3, 5, 7 };

/**
 * Initializes the smartness level to 0 and set the board center
 */
Computer::Computer():
	smartness(0),
	center(4) {
}


/**
 * Sets the smartness level
 */
void Computer::setSmart(int smartness) {
	this->smartness = smartness;
}

/**
 * Returns the next computer move based on the passed board and smartness level.
 */
int Computer::getMove(Board& board) const {
	switch(smartness) {
	        case 1:
		        return notSoStupidMove(board);
		        break;
	        case 2:
		        return smartMove(board);
		        break;
	        case 0:
	        default:
		        return stupidMove(board);
	}
}


/**
 * Returns the most basic move.
 */
int Computer::stupidMove(Board& board) const {
	return board.getRandomMoveFromList(fullBoardList, 9);
}


/**
 * Returns a not so basic move.
 */
int Computer::notSoStupidMove(Board& board) const {
	int i; // No need to redeclare the for loop index every time

	// We'll also need this a few times
	char computerLetter = board.getComputerLetter();
	char playerLetter = board.getPlayerLetter();

	// First, check if we can win in the next move
	for (i = 0; i < 9; i++) {
		Board tempBoard(board);
		if (tempBoard.isEmpty(i)) {
			tempBoard.setPlace(i, computerLetter);
			if (tempBoard.isWinner(computerLetter))
				return i;
		}
	}

	// Check if the player could win on his next move, and block them.
	for (i = 0; i < 9; i++) {
		Board tempBoard(board);
		if (tempBoard.isEmpty(i)) {
			tempBoard.setPlace(i, playerLetter);
			if (tempBoard.isWinner(playerLetter))
				return i;
		}
	}

	// Try to take one of the corners, if they are free.
	/* TODO: This can still be improved: if one corner is already taken by the
	 * computer, it should try to take the opposite corner to immediately create
	 * the opportunity of winning with a diagonal. After that, it should take
	 * one of the other two corners and maybe create the possibility to win on
	 * one of two sides, if they're both free, since the player can only cut one
	 * of them.
	 */
	int move = board.getRandomMoveFromList(cornersList, 4);
	if (move != -1)
		return move;

	// Try to take the center, if it is free.
	if (board.isEmpty(4))
		return 4;

	// Move on one of the sides.
	return board.getRandomMoveFromList(sidesList, 4);
}


/**
 * Returns a smart move based on minimax (or negamax).
 * Implementation heavily inspired on the pseudo-code of page 676 of
 * "Artificial Intelligence for Games, 2nd edition", by Ian Millington and
 * John Funge.
 */
int Computer::smartMove(Board& board) const {
	// When calling minimax for the first time, the computer is always the player
	minimaxresult res = minimax(board, board.getComputerLetter(), 0, 100000);

	return res.bestMove;
}

minimaxresult Computer::minimax(Board& board, char player, int currentDepth, int maxDepth) const {
	minimaxresult res;

	// Check if we're done recursing
	if (board.isWinner(board.getCurrentPlayer()) || currentDepth == maxDepth) {
		res.bestMove = NULL;
		res.bestScore = board.evaluate(player);
		return res;
	}

	//Otherwise, bubble up values from below
	int bestMove = -1, bestScore = 0, currentScore, currentMove;


	// Assuming numeric_limits<int>::has_infinity is true
	if (board.getCurrentPlayer() == player)
		bestScore = -std::numeric_limits<int>::infinity();
	else
		bestScore = std::numeric_limits<int>::infinity();

	// Go through each move
	std::vector<int> possibleMoves;
	board.getPossibleMoves(possibleMoves);
	std::vector<int>::iterator move;
	for (move = possibleMoves.begin(); move < possibleMoves.end(); move++) {
		Board newBoard(board);
		newBoard.makeMove(*move);

		// Recurse
		res = minimax(newBoard, player, maxDepth, currentDepth+1);
		currentScore = res.bestScore;
		currentMove = res.bestMove;

		// Update the best score
		if (board.getCurrentPlayer() == player) {
			if (currentScore > bestScore) {
				bestScore = currentScore;
				bestMove = *move;
			}
		} else {
			if (currentScore < bestScore) {
				bestScore = currentScore;
				bestMove = *move;
			}
		}
	}

	// Return the score and the best move
	res.bestMove = bestMove;
	res.bestScore = bestScore;
	return res;
}
