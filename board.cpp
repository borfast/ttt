#include "board.h"
#include <iostream>

Board::Board() { reset(); }

Board::Board(const Board &oldBoard) {
    for (int i = 0; i < 9; i++) {
        board[i] = oldBoard.board[i];
    }
}


void Board::reset() {
    for (int i = 0; i < 9; i++) {
        board[i] = Board::EMPTY_PLACE;
    }
}


bool Board::placeEmpty(int place) const {
    return board[place] == Board::EMPTY_PLACE;
}

const char& Board::getPlace(int place) const {
    return board[place];
}

void Board::setPlace(int place, char value) {
    // No, I'm not checking this for out-of-bounds values. Perhaps I should...
    board[place] = value;
}


std::vector<int> Board::getPossibleMoves() const {
    std::vector<int> possibleMoves;

    for (int i = 0; i < 9; i++) {
        if (placeEmpty(i)) {
            possibleMoves.push_back(i);
        }
    }

    return possibleMoves;
}

/**
 * Returns a valid move from the passed list. Throws an exception if there is no valid move.
 */
const int Board::getRandomMoveFromList(const int list[], int listSize) const {
    std::vector<int> possibleMoves;

    for (int i = 0; i < listSize; i++) {
        if (placeEmpty(i)) {
            possibleMoves.push_back(list[i]);
        }
    }
    unsigned long sz = possibleMoves.size();

    if (sz == 0) {
        throw std::exception();
    }

    return possibleMoves[rand() % sz];
}


/*
 * Return true if every space on the board has been taken. Otherwise return
 * false.
 */
bool Board::isFull() const {
    for (int i = 0; i < 9; i++) {
        if (placeEmpty(i)) {
            return false;
        }
    }

    return true;
}

int Board::evaluate(const char &player) const {
    return 0;
}
